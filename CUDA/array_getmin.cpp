#include <stdio,h>
#include <vector>

using namespace std;

__global__ void getMidNum(int* input, int inputSize, int k, double* mid) {
    int index = blockIdx.x * blockDim.x + threadIdx.x;
    if (index <= size_k)
}