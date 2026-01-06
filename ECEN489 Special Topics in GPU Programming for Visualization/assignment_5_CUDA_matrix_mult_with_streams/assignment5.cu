#include <stdio.h>
#include <cuda_runtime.h>
#include <cublas_v2.h>

#define TILE_SIZE 32

__global__ void matrix_mul(float* A, float* B, float* C, int n, int k, int m) {
    __shared__ float tileA[TILE_SIZE][TILE_SIZE];
    __shared__ float tileB[TILE_SIZE][TILE_SIZE];
    
    int row = blockIdx.y * TILE_SIZE + threadIdx.y;
    int col = blockIdx.x * TILE_SIZE + threadIdx.x;
    
    float val = 0.0f;
    
    for (int i = 0; i < (k + TILE_SIZE - 1) / TILE_SIZE; i++) {
        // Load tiles into shared memory
        if (row < n && i * TILE_SIZE + threadIdx.x < k)
            tileA[threadIdx.y][threadIdx.x] = A[row * k + i * TILE_SIZE + threadIdx.x];
        else
            tileA[threadIdx.y][threadIdx.x] = 0.0f;
        if (i * TILE_SIZE + threadIdx.y < k && col < m)
            tileB[threadIdx.y][threadIdx.x] = B[(i * TILE_SIZE + threadIdx.y) * m + col];
        else
            tileB[threadIdx.y][threadIdx.x] = 0.0f;
            
        __syncthreads();
        
        // Multiply tiles
        for (int j = 0; j < TILE_SIZE; j++)
            val += tileA[threadIdx.y][j] * tileB[j][threadIdx.x];
    }
    
    if (row < n && col < m)
        C[row * m + col] = val;
    
}

int main() {
    int sizes[] = {100, 500, 1000, 5000, 10000};
    int num = sizeof(sizes) / sizeof(sizes[0]);
    
    // Create CUDA events for timing
    cudaEvent_t start1, stop1, start2, 
    stop2, start3, stop3, start4, stop4;
    cudaEventCreate(&start1); cudaEventCreate(&stop1);
    cudaEventCreate(&start2); cudaEventCreate(&stop2);
    cudaEventCreate(&start3); cudaEventCreate(&stop3);
    cudaEventCreate(&start4); cudaEventCreate(&stop4);
    
    for (int i = 0; i < num; i++) {
        int n = sizes[i];
        int m = sizes[i];
        int k = sizes[i];
        
        // Allocate host memory
        float *h_A, *h_B, *h_C;
        cudaMallocHost((void **)&h_A, n * k * sizeof(float));
        cudaMallocHost((void **)&h_B, k * m * sizeof(float));
        cudaMallocHost((void **)&h_C, n * m * sizeof(float));
        
        // Initialize matrices
        for (int i = 0; i < n * k; i++) h_A[i] = i;
        for (int i = 0; i < k * m; i++) h_B[i] = i;

        // Allocate device memory
        float *d_A1, *d_B1, *d_C1, *d_A2, *d_B2, *d_C2;
        cudaMalloc((void **)&d_A1, n * k * sizeof(float));
        cudaMalloc((void **)&d_B1, k * m * sizeof(float));
        cudaMalloc((void **)&d_C1, n * m * sizeof(float));
        cudaMalloc((void **)&d_A2, n * k * sizeof(float));
        cudaMalloc((void **)&d_B2, k * m * sizeof(float));
        cudaMalloc((void **)&d_C2, n * m * sizeof(float));

        // Copy data from host to device
        cudaMemcpy(d_A1, h_A, n * k * sizeof(float), cudaMemcpyHostToDevice);
        cudaMemcpy(d_B1, h_B, k * m * sizeof(float), cudaMemcpyHostToDevice);
        cudaMemcpy(d_A2, h_A, n * k * sizeof(float), cudaMemcpyHostToDevice);
        cudaMemcpy(d_B2, h_B, k * m * sizeof(float), cudaMemcpyHostToDevice);

        // Create cuBLAS handle
        cublasHandle_t handle;
        cublasCreate(&handle);
        
        // Prepare cublas and kernel launches
        float alpha = 1.0f;
        float beta = 0.0f;
        dim3 dimBlock(TILE_SIZE, TILE_SIZE);
        dim3 dimGrid((n + TILE_SIZE - 1) / TILE_SIZE, (m + TILE_SIZE - 1) / TILE_SIZE);
        
        // Perform matrix multiplication WITHOUT CUDA streams
        cudaEventRecord(start1);
        cublasSgemm(handle, CUBLAS_OP_N, CUBLAS_OP_N, n, m, k, &alpha, d_A1, k, d_B1, m, &beta, d_C1, m);
        matrix_mul<<<dimGrid, dimBlock>>>(d_A2, d_B2, d_C2, n, k, m);
        cudaEventRecord(stop1);
        cudaEventSynchronize(stop1);
        
        float ms_nostreams = 0;
        cudaEventElapsedTime(&ms_nostreams, start1, stop1);
        cudaDeviceSynchronize();
        
        // Create CUDA streams
        cudaStream_t stream1, stream2;
        cudaStreamCreate(&stream1);
        cudaStreamCreate(&stream2);
        
        // Perform matrix multiplication WITH CUDA streams
        // Total timing start
        cudaEventRecord(start2);
        
        // Stream 1 (cuBLAS)
        cublasSetStream(handle, stream1);
        cudaEventRecord(start3, stream1);
        cublasSgemm(handle, CUBLAS_OP_N, CUBLAS_OP_N, n, m, k, &alpha, d_A1, k, d_B1, m, &beta, d_C1, m);
        cudaEventRecord(stop3, stream1);
        
        // Stream 2 (custom kernel)
        cudaEventRecord(start4, stream2);
        matrix_mul<<<dimGrid, dimBlock, 0, stream2>>>(d_A2, d_B2, d_C2, n, k, m);
        cudaEventRecord(stop4, stream2);
        
        // Total timing stop
        cudaEventRecord(stop2);
        
        // Synchronize
        cudaEventSynchronize(stop2);
        cudaEventSynchronize(stop3);
        cudaEventSynchronize(stop4);
        
        float ms_streams = 0, ms_stream1 = 0, ms_stream2 = 0;
        cudaEventElapsedTime(&ms_streams, start2, stop2);
        cudaEventElapsedTime(&ms_stream1, start3, stop3);
        cudaEventElapsedTime(&ms_stream2, start4, stop4);

        printf(" --- Matrix size: %d x %d ---\n", n, m);
        printf("With CUDA Streams: %.3f ms\n", ms_streams);
        printf("\t- CUDA Stream1: %.3f ms\n", ms_stream1);
        printf("\t- CUDA Stream2: %.3f ms\n", ms_stream2);
        printf("Without CUDA Streams: %.3f ms\n\n", ms_nostreams);

        // Copy result from device to host
        cudaMemcpy(h_C, d_C1, n * m * sizeof(float), cudaMemcpyDeviceToHost);

        // Clean up
        cublasDestroy(handle);
        cudaFreeHost(h_A);
        cudaFreeHost(h_B);
        cudaFreeHost(h_C);
        cudaFree(d_A1); cudaFree(d_B1); cudaFree(d_C1);
        cudaFree(d_A2); cudaFree(d_B2); cudaFree(d_C2);
        cudaStreamDestroy(stream1);
        cudaStreamDestroy(stream2);
    }
    
    // Clean up
    cudaEventDestroy(start1); cudaEventDestroy(stop1);
    cudaEventDestroy(start2); cudaEventDestroy(stop2);
    cudaEventDestroy(start3); cudaEventDestroy(stop3);
    cudaEventDestroy(start4); cudaEventDestroy(stop4);
    
    return 0;
}
