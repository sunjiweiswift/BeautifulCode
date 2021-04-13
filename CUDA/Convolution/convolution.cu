#include <stdio.h>

using namespace std;

__global__ void convolutionCUDA(float* img, float* kernel, float* result, int width, int height,
                                int kernelSize) {
    int index = threadIdx.x + blockIdx.x * blockDim.x;
    if (index < width * height) {
        int row = index / width;
        int col = index % width;
        for (int i = 0; i < kernelSize; i++) {
            for (int j = 0; j < kernelSize; j++) {
                int curRow = row - kernelSize / 2 + i;
                int curCol = col - kernelSize / 2 + j;
                if (curRow >= 0 && curRow < height && curCol >= 0 && curCol < width) {
                    result[index] += img[curRow * width + curCol] * kernel[i * kernelSize + j];
                }
            }
        }
    }
}

int getThreadNum() {
    cudaDeviceProp prop; //cudaDeviceProp的一个对象
    int count = 0;       //GPU的个数
    cudaGetDeviceCount(&count);
    printf("gpu 的个数：%d \n", count);

    cudaGetDeviceProperties(&prop, 0); //第二参数为那个gpu
    printf("最大线程数：%d \n", prop.maxThreadsPerBlock);
    printf("最大网格类型：%d %d %d \n", prop.maxGridSize[0], prop.maxGridSize[1],
           prop.maxGridSize[2]);
    return prop.maxThreadsPerBlock;
}

int main(void) {
    getThreadNum();
    int width = 1920;
    int height = 1080;
    float* imgCPU = new float[width * height];
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            imgCPU[col + row * width] = (col + row) % 256;
        }
    }

    int kernelSize = 3;
    float* kernelCPU = new float[width * height];
    for (int i = 0; i < kernelSize * kernelSize; i++) {
        kernelCPU[i] = i % kernelSize - 1;
    }
    float* resultCPU = new float[width * height];
    // Print
    printf("Img data \n");
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            printf("%2.0f ", imgCPU[col + row * width]);
        }
        printf("\n");
    }
    printf("Kernel data \n");
    for (int row = 0; row < kernelSize; row++) {
        for (int col = 0; col < kernelSize; col++) {
            printf("%2.0f ", kernelCPU[col + row * kernelSize]);
        }
        printf("\n");
    }
    // Malloc On GPU
    float* imgGPU;
    float* kernelGPU;
    float* resultGPU;
    cudaMalloc(&imgGPU, width * height * sizeof(float));
    cudaMalloc(&kernelGPU, kernelSize * kernelSize * sizeof(float));
    cudaMalloc(&resultGPU, width * height * sizeof(float));
    // Copy CPU To CPU
    cudaMemcpy(imgGPU, imgCPU, width * height * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(kernelGPU, kernelCPU, kernelSize * kernelSize * sizeof(float),
               cudaMemcpyHostToDevice);
    int threadNum = 1024;
    int blockNum = (width * height + threadNum - 1) / threadNum;
    printf("threadNum:%d, blockNum:%d", threadNum, blockNum);

    convolutionCUDA<<<blockNum, threadNum>>>(imgGPU, kernelGPU, resultGPU, width, height,
                                             kernelSize);
    // Copy GPU to CPU
    cudaMemcpy(resultCPU, resultGPU, width * height * sizeof(float), cudaMemcpyDeviceToHost);
    // GPU cudaFree
    cudaFree(imgGPU);
	cudaFree(kernelGPU);
	cudaFree(resultGPU);
    // Print
    printf("result data \n");
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            printf("%2.0f ", resultCPU[col + row * width]);
        }
        printf("\n");
    }
    delete[] imgCPU;
    delete[] kernelCPU;
    delete[] resultCPU;
    return 0;
}
