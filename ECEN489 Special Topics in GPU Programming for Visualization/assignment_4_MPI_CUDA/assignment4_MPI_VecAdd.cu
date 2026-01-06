#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define A_VALUE 3
#define B_VALUE 4

__global__ void vectorAddKernel(float* A, float* B, float* C, int N) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < N) {
        C[idx] = A[idx] + B[idx];
    }
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    // Define variables
    int VECTOR_SIZE = 100000000;
    int threadsPerBlock = 256;
    
    if (argc >= 2)
        VECTOR_SIZE = atoi(argv[1]);
    if (argc >= 3)
        threadsPerBlock = atoi(argv[2]);

    // Start timing
    double startTime = MPI_Wtime();

    // Calculate the number of elements per process
    int elementsPerProcess = VECTOR_SIZE / size;
    int remainder = VECTOR_SIZE % size;

    // Determine the start and end indices for each process
    int startIdx = rank * elementsPerProcess + (rank < remainder ? rank : remainder);
    int numElements = elementsPerProcess + (rank < remainder ? 1 : 0);

    // Allocate memory for local portions of vectors A, B, and C
    float* localA = (float*)malloc(numElements * sizeof(float));
    float* localB = (float*)malloc(numElements * sizeof(float));
    float* localC = (float*)malloc(numElements * sizeof(float));

    // Initialize local portions of A and B
    for (int i = 0; i < numElements; i++) {
        localA[i] = A_VALUE;
        localB[i] = B_VALUE;
    }
    
    // Copy vectors to device
    float *d_A, *d_B, *d_C;
    cudaMalloc((void**)&d_A, numElements * sizeof(float));
    cudaMalloc((void**)&d_B, numElements * sizeof(float));
    cudaMalloc((void**)&d_C, numElements * sizeof(float));

    cudaMemcpy(d_A, localA, numElements * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, localB, numElements * sizeof(float), cudaMemcpyHostToDevice);
    
    // Measure kernel execution time
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    
    // Launch kernel
    int blocksPerGrid = (numElements + threadsPerBlock - 1) / threadsPerBlock;
    
    cudaEventRecord(start);
    vectorAddKernel<<<blocksPerGrid, threadsPerBlock>>>(d_A, d_B, d_C, numElements);
    cudaDeviceSynchronize();

    cudaEventRecord(stop);
    cudaEventSynchronize(stop);
    float milliseconds = 0;
    cudaEventElapsedTime(&milliseconds, start, stop);

    // Copy result to host
    cudaMemcpy(localC, d_C, numElements * sizeof(float), cudaMemcpyDeviceToHost);

    // Free memory
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
    cudaEventDestroy(start);
    cudaEventDestroy(stop);

    // Gather results at the root process using MPI_Gatherv
    float* globalC = NULL;
    if (rank == 0) {
        globalC = (float*)malloc(VECTOR_SIZE * sizeof(float));
    }

    int* recvCounts = NULL;
    int* displs = NULL;

    if (rank == 0) {
        recvCounts = (int*)malloc(size * sizeof(int));
        displs = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            recvCounts[i] = elementsPerProcess + (i < remainder ? 1 : 0);
            displs[i] = i * elementsPerProcess + (i < remainder ? i : remainder);
        }
    }

    MPI_Gatherv(localC, numElements, MPI_FLOAT,
                globalC, recvCounts, displs, MPI_FLOAT,
                0, MPI_COMM_WORLD);

    // Stop timing after all processes finish their work
    double endTime = MPI_Wtime();

    // Print results on root process
    if (rank == 0) {
        printf("Vector addition completed.\n");
        printf("First 10 elements of C: ");
        for (int i = 0; i < 10; i++) {
            printf("%.1f ", globalC[i]);
        }
        printf("\n");

        // Print total execution time
        printf("Total execution time: %.6f seconds\n", endTime - startTime);

        free(globalC);
        free(recvCounts);
        free(displs);
    }
    
    // Print each kernel execution time
    printf("Rank %d, CUDA Kernel Time: %.3f ms\n", rank, milliseconds);
    // printf("Rank %d | Threads per Block: %d | Blocks per Grid: %d | Kernel Time: %.3f ms\n", rank, threadsPerBlock, blocksPerGrid, milliseconds);

    // Free memory for local vectors
    free(localA);
    free(localB);
    free(localC);

    MPI_Finalize();

    return 0;
}
