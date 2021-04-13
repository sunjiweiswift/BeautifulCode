#include <stdio.h>
#include <vector>

using namespace std;

__global__ void getMidNum(int* input, int size, int k, double* mid) {
    int index = blockIdx.x * blockDim.x + threadIdx.x;
    if (index <= size - k) {
        int* tmp = (int*)malloc(k * sizeof(int));
        memcpy(tmp, input + index, k * sizeof(int));

        // sort
        for (int i = 1, j; i < k; i++) {
            int insert = tmp[i];
            for (j = i - 1; j >= 0 && tmp[j] > insert; j--) {
                tmp[j + 1] = tmp[j];
            }
            tmp[j + 1] = insert;
        }

        // Get mid
        if (k % 2 == 1) {
            mid[index] = tmp[k / 2];
        } else {
            mid[index] = tmp[k / 2] / 2.0  + tmp[k - 1] / 2.0;
        }
        free tmp;
    }
}

int main(void) {
    // SetInput
    vector<int> cpuInputVec {1,3,-1,-3,5,3,6,7};
    int k = 3;
    // Generate variable
    int inputSize = cpuInputVec.size();
    int outputSize = inputSize - k + 1;
    int* cpuInput = cpuInputVec.data();

    double* cpuOutput = (double*)malloc(outputSize * sizeof(double));

    int* input;
    double* output;
    cudaMalloc(&input, inputSize * sizeof(int));
    cudaMalloc(&output, outputSize * sizeof(double));
    cudaMemcpy(input, cpuInput, inputSize * sizeof(int), cudaMemcpyHostToDevice);
    int threadPerBlock = 1;
    int numBlock = (inputSize - 1) / threadPerBlock + 1;
    // Run On GPU
    getMidNum<<<numBlock, threadPerBlock>>>(input, inputSize, k, output);
    cudaMemcpy(cpuOutput, output, outputSize * sizeof(double), cudaMemcpyDeviceToHost);
    for (int i = 0; i < outputSize; i++) {
        printf("%f ", cpuOutput[i]);
    }
    printf("\n");
    cudaFree(input);
    cudaFree(output);
    free(cpuOutput);
    cudaDeviceReset();
    return 0;
}
