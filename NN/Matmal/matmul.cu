#include <stdio.h>

__global__ void matMulCUDA(float* A, float* B, float* C, int aHeight, int aWidth, int bWidth) {

    int row = blockIdx.x * blockDim.x + threadIdx.x;
    int col = blockIdx.y * blockDim.y + threadIdx.y;
    float sum = 0.0;
    if (row < aHeight && col < bWidth ) {
        for (int i = 0; i < aWidth; i++) {
            sum += A[row * aWidth + i] * B[i * bWidth + col];
        }
        C[row * bWidth + col] = sum;
    }
}

int main(void) {
    int aHeight = 2;
    int aWidth = 3;
    int bWidth = 3;
    float cpuA[aHeight][aWidth] = {{1, 2, 3}, {4, 5, 6}};
    float cpuB[aWidth][bWidth] = {{7, 8, 9}, {10, 11, 12}, {13, 14, 15}};
    // malloc GPU Memory
    float* A;
    float* B;
    float* C;
    cudaMalloc(&A, aHeight * aWidth * sizeof(float));
    cudaMalloc(&B, aWidth * bWidth * sizeof(float));
    cudaMalloc(&C, aHeight * bWidth * sizeof(float));
    // Copy CPU to GPU
    cudaMemcpy(A, cpuA, aHeight * aWidth * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(B, cpuB, aWidth * bWidth * sizeof(float), cudaMemcpyHostToDevice);
    // Run On GPU
    dim3 blockSize(aHeight, bWidth);
    dim3 gridSize((aHeight + blockSize.x - 1) / blockSize.x,
                  (bWidth + blockSize.y - 1) / blockSize.y);
    matMulCUDA<<<gridSize, blockSize>>>(A, B, C, aHeight, aWidth, bWidth);
    // Copy GPU to CPU
    float* cpuC = (float*)malloc(aHeight * bWidth * sizeof(float));
    cudaMemcpy(cpuC, C, aHeight * bWidth * sizeof(float), cudaMemcpyDeviceToHost);
    for (int i = 0; i < aHeight; i++) {
        for (int j = 0; j < bWidth; j++) {
            printf("%f ", *(cpuC + i * bWidth + j));
        }
        printf("\n");
    }
    cudaFree(A);
    cudaFree(B);
    cudaFree(C);
    free(cpuC);
    return 0;
}
