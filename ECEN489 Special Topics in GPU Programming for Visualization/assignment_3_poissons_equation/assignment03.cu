#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <chrono>

// Maximum number of iterations for the Jacobi method
#define MAX_ITERATIONS 100000
// Convergence tolerance for the solution
#define TOLERANCE 1e-6

// Function to define the right-hand side of the Poisson equation
// This represents the source term in the equation ∇²u = f(x,y)
__device__ double f(double x, double y) {
    return 2 * (y - y*y + x - x*x);
}

__device__ double atomicMaxDouble(double* address, double val) {
    unsigned long long int* address_as_ull = (unsigned long long int*)address;
    unsigned long long int old = *address_as_ull, assumed;
    do {
        assumed = old;
        old = atomicCAS(address_as_ull, assumed,
                        __double_as_longlong(fmax(val, __longlong_as_double(assumed))));
    } while (assumed != old);
    return __longlong_as_double(old);
}

// Jacobi iterative method
__global__ void jacobi_kernel(int n, double h, double *u, double *u_new, double *max_error) {
    int i = blockIdx.x * blockDim.x + threadIdx.x + 1;
    int j = blockIdx.y * blockDim.y + threadIdx.y + 1;
    
    double x, y, error;
    
    if(i < n-1 && j < n-1){
        x = i * h;
        y = j * h;
        double new_val = 0.25 * (u[(i+1)*n + j] + u[(i-1)*n + j] 
                + u[i*n + (j+1)] + u[i*n + (j-1)] - h*h*f(x, y));
                
        error = fabs(new_val - u[i*n + j]);
        
	    atomicMaxDouble(max_error, error);
	
	    u_new[i*n + j] = new_val;
    }
}

// Poisson equation solver using the Jacobi iterative method
void poisson_solver(int n, double h, double *u, int BLOCK_SIZE) {
    double *d_u, *d_u_new, *d_max_error;
    double h_max_error;
    
    // Allocate memory for the new solution array
    cudaMalloc(&d_u, n * n * sizeof(double));
    cudaMalloc(&d_u_new, n * n * sizeof(double));
    cudaMalloc(&d_max_error, sizeof(double));
    
    cudaMemcpy(d_u, u, n * n * sizeof(double), cudaMemcpyHostToDevice);
    
    dim3 blockDim(BLOCK_SIZE, BLOCK_SIZE);
    dim3 gridDim((n + blockDim.x - 1) / blockDim.x, (n + blockDim.y - 1) / blockDim.y);

    // Main iteration loop
    int iter;
    for (iter = 0; iter < MAX_ITERATIONS; iter++) {
        h_max_error = 0.0;
        cudaMemcpy(d_max_error, &h_max_error, sizeof(double), cudaMemcpyHostToDevice);

        // Update u_new using the Jacobi method
        jacobi_kernel<<<gridDim, blockDim>>>(n, h, d_u, d_u_new, d_max_error);
        cudaDeviceSynchronize();
        
        // Check for CUDA errors
        cudaError_t err = cudaGetLastError();
        if (err != cudaSuccess) {
            printf("CUDA Error (Shared): %s\n", cudaGetErrorString(err));
        }

        cudaMemcpy(&h_max_error, d_max_error, sizeof(double), cudaMemcpyDeviceToHost);

        // Copy new solution to u
        cudaMemcpy(d_u, d_u_new, n * n * sizeof(double), cudaMemcpyDeviceToDevice);

        // Check for convergence
        if (h_max_error < TOLERANCE) {
            printf("Converged after %d iterations\n", iter+1);
            break;
        }
    }
    
    cudaMemcpy(u, d_u, n * n * sizeof(double), cudaMemcpyDeviceToHost);

    // Free memory allocated for u_new
    cudaFree(d_u);
    cudaFree(d_u_new);
    cudaFree(d_max_error);
}

void save_output(double *u, int n, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s for writing.\n", filename);
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(fp, "%f ", u[i*n + j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    printf("Output saved to %s\n", filename);
}


int main() {
    for (int iter = 1; iter < 6; iter++) {
        int n = 400;  // Grid size (number of points in each dimension)
        double L = 1.0;  // Domain size (assuming a square domain)
        double h = L / (n - 1);  // Grid spacing
        int i, j, block_size;
    
        // Allocate memory for the solution array
        double *u = (double *)malloc(n * n * sizeof(double));
        memset(u, 0, n * n * sizeof(double));
    
        // Initialize boundary conditions (Dirichlet boundary conditions)
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == n-1 || j == n-1)
                    u[i*n + j] = 0.0;
            }
        }
    
        // Solve Poisson equation
        float time;
        cudaEvent_t start, stop;
        cudaEventCreate(&start);
        cudaEventCreate(&stop);
    
        block_size = pow(2, iter);
        cudaEventRecord(start);
        poisson_solver(n, h, u, block_size);
        cudaEventRecord(stop);
        cudaEventSynchronize(stop);
        cudaEventElapsedTime(&time, start, stop);
        
        printf("Execution time for block_size=%d: %f s\n", block_size, time / 1000.0f);

        // Save the output to a file
        save_output(u, n, "gpu_output.txt");
    
        // Free allocated memory
        free(u);
    }

    return 0;
}
