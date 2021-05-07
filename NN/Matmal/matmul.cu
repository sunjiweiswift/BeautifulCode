#include <stdio.h>

__global__ void matMulCUDA(float* A, float* B, float* C, int M, int K, int N) {

    int row = blockIdx.x * blockDim.x + threadIdx.x;
    int col = blockIdx.y * blockDim.y + threadIdx.y;
    float sum = 0.0;
    if (row < M && col < N ) {
        for (int i = 0; i < K; i++) {
            sum += A[row * K + i] * B[i * N + col];
        }
        C[row * N + col] = sum;
    }
}

int main(void) {
    int M = 2;
    int K = 3;
    int N = 3;
    float cpuA[M][K] = {{1, 2, 3}, {4, 5, 6}};
    float cpuB[K][N] = {{7, 8, 9}, {10, 11, 12}, {13, 14, 15}};
    // malloc GPU Memory
    float* A;
    float* B;
    float* C;
    cudaMalloc(&A, M * K * sizeof(float));
    cudaMalloc(&B, K * N * sizeof(float));
    cudaMalloc(&C, M * N * sizeof(float));
    // Copy CPU to GPU
    cudaMemcpy(A, cpuA, M * K * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(B, cpuB, K * N * sizeof(float), cudaMemcpyHostToDevice);
    // Run On GPU
    dim3 blockSize(M, N);
    dim3 gridSize((M + blockSize.x - 1) / blockSize.x,
                  (N + blockSize.y - 1) / blockSize.y);
    matMulCUDA<<<gridSize, blockSize>>>(A, B, C, M, K, N);
    // Copy GPU to CPU
    float* cpuC = (float*)malloc(M * N * sizeof(float));
    cudaMemcpy(cpuC, C, M * N * sizeof(float), cudaMemcpyDeviceToHost);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%f ", *(cpuC + i * N + j));
        }
        printf("\n");
    }
    cudaFree(A);
    cudaFree(B);
    cudaFree(C);
    free(cpuC);
    return 0;
}
