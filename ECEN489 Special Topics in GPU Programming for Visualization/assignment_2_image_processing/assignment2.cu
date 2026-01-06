#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <chrono>


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void generateGaussianKernel(float* kernel, int size, float sigma) {
    float sum = 0.0f;
    int center = size / 2;
    
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            float dx = x - center;
            float dy = y - center;
            kernel[y * size + x] = exp(-(dx*dx + dy*dy) / (2.0f * sigma * sigma));
            sum += kernel[y * size + x];
        }
    }
    
    // Normalize kernel
    for (int i = 0; i < size * size; i++) {
        kernel[i] /= sum;
    }
}

void gaussianBlur(unsigned char* input, unsigned char* output, 
                  int width, int height, int channels,
                  float* kernel, int kernelSize) {
    int radius = kernelSize / 2;
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                float sum = 0.0f;
                
                for (int ky = -radius; ky <= radius; ky++) {
                    for (int kx = -radius; kx <= radius; kx++) {
                        int px = x + kx;
                        int py = y + ky;
                        
                        px = (px < 0) ? 0 : ((px >= width) ? width - 1 : px);
                        py = (py < 0) ? 0 : ((py >= height) ? height - 1 : py);
                        
                        int pixel_idx = (py * width + px) * channels + c;
                        float kernel_val = kernel[(ky + radius) * kernelSize + (kx + radius)];
                        sum += input[pixel_idx] * kernel_val;
                    }
                }
                
                output[(y * width + x) * channels + c] = (unsigned char)sum;
            }
        }
    }
}

__global__ void gaussianBlurGlobal(unsigned char *input, unsigned char *output,
                  int width, int height, int channels,
                  float* kernel, int kernelSize) {
    int x = blockIdx.x * blockDim.x + threadIdx.x;
    int y = blockIdx.y * blockDim.y + threadIdx.y;
    int radius = kernelSize / 2;

    if(x < width && y < height) {
        for (int c = 0; c < channels; c++) {
            float sum = 0.0f;
                
            for (int ky = -radius; ky <= radius; ky++) {
                for (int kx = -radius; kx <= radius; kx++) {
                    int px = x + kx;
                    int py = y + ky;
                    
                    px = (px < 0) ? 0 : ((px >= width) ? width - 1 : px);
                    py = (py < 0) ? 0 : ((py >= height) ? height - 1 : py);
                    
                    int pixel_idx = (py * width + px) * channels + c;
                    float kernel_val = kernel[(ky + radius) * kernelSize + (kx + radius)];
                    sum += input[pixel_idx] * kernel_val;
                }
            }
            
            output[(y * width + x) * channels + c] = (unsigned char)sum;
        }
    }
}

#define MAX_BLOCK_SIZE 32  // Set to highest block size

__global__ void gaussianBlurShared(unsigned char *input, unsigned char *output,
                                   int width, int height, int channels,
                                   float* kernel, int kernelSize) {
                                   
    __shared__ float s_kernel[25]; // Fixed kernel size (kernelSize*kernelSize)
    __shared__ unsigned char s_image[MAX_BLOCK_SIZE][MAX_BLOCK_SIZE][3]; // Max padding

    int tx = threadIdx.x, ty = threadIdx.y;
    int x = blockIdx.x * blockDim.x + tx;
    int y = blockIdx.y * blockDim.y + ty;
    int radius = kernelSize / 2;
    int sharedWidth = blockDim.x + 2 * radius;
    int sharedHeight = blockDim.y + 2 * radius;

    // Load kernel into shared memory (first 25 threads)
    if (tx < kernelSize && ty < kernelSize) {
        s_kernel[ty * kernelSize + tx] = kernel[ty * kernelSize + tx];
    }

    __syncthreads();

    // Load image tile into shared memory
    for (int c = 0; c < channels; c++) {
        int img_x = min(max(x - radius, 0), width - 1);
        int img_y = min(max(y - radius, 0), height - 1);
        
        if (ty + radius < sharedHeight && tx + radius < sharedWidth) {
            s_image[ty + radius][tx + radius][c] = input[(img_y * width + img_x) * channels + c];
        }
    }

    __syncthreads();

    // Apply convolution only for valid pixels
    if (tx >= radius && tx < blockDim.x - radius &&
        ty >= radius && ty < blockDim.y - radius &&
        x < width && y < height) {

        for (int c = 0; c < channels; c++) {
            float sum = 0.0f;

            for (int ky = -radius; ky <= radius; ky++) {
                for (int kx = -radius; kx <= radius; kx++) {
                    float kernel_val = s_kernel[(ky + radius) * kernelSize + (kx + radius)];
                    sum += s_image[ty + ky + radius][tx + kx + radius][c] * kernel_val;
                }
            }

            output[(y * width + x) * channels + c] = (unsigned char)sum;
        }
    }
}



int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    int width, height, channels;
    unsigned char *h_input, *h_output;
    float *h_kernel;

    unsigned char* input = stbi_load(argv[1], &width, &height, &channels, 0);
    
    if (!input) {
        printf("Failed to load image: %s\n", argv[1]);
        return 1;
    }

    int img_size = width * height * channels;
    cudaMallocManaged(&h_input, img_size * sizeof(unsigned char));
    cudaMallocManaged(&h_output, img_size * sizeof(unsigned char));

    memcpy(h_input, input, img_size);
    unsigned char* output = (unsigned char*)malloc(img_size);
    
    // Generate and apply Gaussian kernel
    const int kernelSize = 5;
    const float sigma = 1.0f;
    cudaMallocManaged(&h_kernel, kernelSize * kernelSize * sizeof(float));
    generateGaussianKernel(h_kernel, kernelSize, sigma);

    // CPU Timing
    auto startCPU = std::chrono::high_resolution_clock::now();
    gaussianBlur(input, output, width, height, channels, h_kernel, kernelSize);
    auto endCPU = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> cpuTime = endCPU - startCPU;
    printf("CPU Time: %.3f ms\n", cpuTime.count() * 1000);

    float globalTime[5] = {0, 0, 0, 0, 0};
    float sharedTime[5] = {0, 0, 0, 0, 0};
    cudaEvent_t start, stop;

    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    // Define block sizes to test
    int blockSizes[] = {2, 4, 8, 16, 32};
    int numBlockSizes = sizeof(blockSizes) / sizeof(blockSizes[0]);

    printf("Performance Analysis for Different Block Sizes:\n");
    printf("      GLOBAL    |      SHARED      \n");
    printf("---------------------------------------------\n");
    
    int radius = kernelSize / 2;

    cudaError_t err;
    for (int i = 0; i < numBlockSizes; i++) {
        int block_size = blockSizes[i];
        printf("%d   | ", block_size);

        int sharedWidth = block_size + 2 * radius;
        int sharedHeight = block_size + 2 * radius;
        
        // Calculate shared memory size
        size_t sharedMemSize = (kernelSize * kernelSize * sizeof(float)) +
                       (sharedWidth * sharedHeight * channels * sizeof(unsigned char));
        
        dim3 blockDim(block_size, block_size);
        dim3 gridDim((width + block_size - 1) / block_size, (height + block_size - 1) / block_size);

        cudaEventRecord(start);
        gaussianBlurGlobal<<<gridDim, blockDim, sharedMemSize>>>(h_input, h_output, width, 
                    height, channels, h_kernel, kernelSize);
	    cudaEventRecord(stop);
	    cudaEventSynchronize(stop);
        cudaEventElapsedTime(&globalTime[i], start, stop);

	    printf("%.3f       | ", globalTime[i]);
	    
	    // Check for CUDA errors
        err = cudaGetLastError();
    	if (err != cudaSuccess) {
            printf("CUDA Error (Global): %s\n", cudaGetErrorString(err));
        }

        cudaEventRecord(start);
        gaussianBlurShared<<<gridDim, blockDim>>>(h_input, h_output, width, 
                    height, channels, h_kernel, kernelSize);
    	cudaEventRecord(stop);
    	cudaEventSynchronize(stop);
        cudaEventElapsedTime(&sharedTime[i], start, stop);
    	printf("%.3f\n", sharedTime[i]);
    	
    	// Check for CUDA errors
        err = cudaGetLastError();
    	if (err != cudaSuccess) {
            printf("CUDA Error (Shared): %s\n", cudaGetErrorString(err));
        }
    }
    // Save result
    stbi_write_png(argv[2], width, height, channels, h_output, width * channels);
    
    // Cleanup
    stbi_image_free(input);
    cudaFree(h_input);
    cudaFree(h_output);
    cudaFree(h_kernel);

    cudaEventDestroy(start);
    cudaEventDestroy(stop);
    
    return 0;
}
