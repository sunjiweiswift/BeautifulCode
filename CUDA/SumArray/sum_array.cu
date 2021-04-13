#include <stdio.h>

__global__ void sum(float* input, float* result, int inputSize) {
    int index = threadIdx.x;
    __shared__ float sharedData[1024];
    sharedData[index] = input[index];
    for (int i = inputSize / 2; i > 0; i /= 2) {
        if (index < i) {
            sharedData[index] = sharedData[index] + sharedData[index + i];
        }
        __syncthreads();
    }
    if (index == 0) {
        *result = sharedData[0];
    }
}

int main(void) {
    int inputSize = 1024;
    float* inputCPU = new float[inputSize];
    for (int i = 0; i < inputSize; i++) {
        inputCPU[i] = i * (i + 1);
    }
    float* inputGPU;
    float* outputGPU;
    cudaMalloc(&inputGPU, inputSize * sizeof(float));
    cudaMalloc(&outputGPU, sizeof(float));
    cudaMemcpy(inputGPU, inputCPU, inputSize * sizeof(float), cudaMemcpyHostToDevice);
    sum<<<1, inputSize>>>(inputGPU, outputGPU, inputSize);
    float outputCPU;
    cudaMemcpy(&outputCPU, outputGPU, sizeof(float), cudaMemcpyDeviceToHost);
    printf("result: %f \n", outputCPU);
    return 0;
}
