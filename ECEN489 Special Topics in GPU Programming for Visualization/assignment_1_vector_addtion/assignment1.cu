#include <cstdio>
#include <cstdlib>
#include <cuda_runtime.h>

//Part 1: Device Query
int deviceQuery(int* gridDimx){
    int deviceCount;
    cudaError_t err = cudaGetDeviceCount(&deviceCount);

    if (err != cudaSuccess) {
        printf("cudaGetDeviceCount returned error code %d: %s\n", err, cudaGetErrorString(err));
        return 1;
    }

    printf("Number of CUDA devices: %d\n", deviceCount);

    for (int device = 0; device < deviceCount; ++device) {
        cudaDeviceProp deviceProp;
        cudaGetDeviceProperties(&deviceProp, device);

        printf("\nDevice %d: %s\n", device, deviceProp.name);
        printf("  Compute capability: %d.%d\n", deviceProp.major, deviceProp.minor);
        printf("  Total global memory: %.2f MB\n", (float)deviceProp.totalGlobalMem / (1024 * 1024));
        printf("  Shared memory per block: %.2f KB\n", (float)deviceProp.sharedMemPerBlock / 1024.0f);
        printf("  Maximum threads per block: %d\n", deviceProp.maxThreadsPerBlock);
        printf("  Max grid dimension: (%d, %d, %d)\n\n",
            deviceProp.maxGridSize[0], deviceProp.maxGridSize[1], deviceProp.maxGridSize[2]);
        *gridDimx = deviceProp.maxGridSize[0];
    }
    return 0;
}

//Part 2: Vector Addition
__global__ void vectorAdd(const float* A, const float* B, float* C, int N){
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    if(i < N){
        C[i] = A[i] + B[i];
    }
}

float vectorAddHost(const float* A, const float* B, float* C, int N, 
                        int threadsPerBlock, int blocksPerGrid){
    int size = N * sizeof(float);
    float *d_A, *d_B, *d_C;

    cudaMalloc((void **) &d_A, size);
    cudaMemcpy(d_A, A, size, cudaMemcpyHostToDevice);
    cudaMalloc((void **) &d_B, size);
    cudaMemcpy(d_B, B, size, cudaMemcpyHostToDevice);

    cudaMalloc((void **) &d_C, size);
    
    float milliseconds = 0;
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    cudaEventRecord(start);
    vectorAdd<<<blocksPerGrid, threadsPerBlock>>>(d_A, d_B, d_C, N);
    cudaEventRecord(stop);
    cudaEventSynchronize(stop);
    cudaEventElapsedTime(&milliseconds, start, stop);

    cudaMemcpy(C, d_C, size, cudaMemcpyDeviceToHost);
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
    return milliseconds;
}

int main(){
    // Part 1: Device Query
    int gridDimx;
    int err = deviceQuery(&gridDimx);
    if(err == 1){
        return 1;
    }

    // Part 2: Vector Addition
    int N = 100000000; //gridDimx
    int size = N * sizeof(float);
    float *h_A = (float *) malloc(size);
    float *h_B = (float *) malloc(size);
    float *h_C = (float *) malloc(size);
    if (h_A == NULL || h_B == NULL || h_C == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    for(int i = 0; i < N; i++){
        h_A[i] = static_cast<float>(rand()) / RAND_MAX;
        h_B[i] = static_cast<float>(rand()) / RAND_MAX;
    }
    float milliseconds = vectorAddHost(h_A, h_B, h_C, N, 1, N);
   
    // Part 3 and 4: Experimentation with Data Parallelism,
    //                  and Performance Analysis
    for(int i = 1; i <= N; i*=2){
        milliseconds = vectorAddHost(h_A, h_B, h_C, i, 1, i);
        printf("%d, %.3f\n", i, milliseconds);
    }

    free(h_A); free(h_B); free(h_C);
}
