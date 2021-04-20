#include <iostream>

using namespace std;

void Convolution(float* img, int height, int width, float* kernel, int kernelSize, float* result) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            for (int i = 0; i < kernelSize; i++) {
                for (int j = 0; j < kernelSize; j++) {
                    int curRow = row - kernelSize / 2 + i;
                    int curCol = col - kernelSize / 2 + j;
                    if (curRow >= 0 && curRow < height && curCol >= 0 && curCol < width) {
                        result[row * width + col] +=
                                img[curRow * width + curCol] * kernel[i * kernelSize + j];
                    }
                }
            }
        }
    }
}

int main() {
    int width = 1920;
    int height = 1080;
    float* img = new float[width * height];
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            img[col + row * width] = (col + row) % 256;
        }
    }

    int kernelSize = 3;
    float* kernel = new float[width * height];
    for (int i = 0; i < kernelSize * kernelSize; i++) {
        kernel[i] = i % kernelSize - 1;
    }
    float* result = new float[width * height];
    Convolution(img, height, width, kernel, kernelSize, result);
    // Print
    cout << "Img data" << endl;
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            cout << img[col + row * width] << " ";
        }
        cout << endl;
    }
    cout << "Kernel data" << endl;
    for (int row = 0; row < kernelSize; row++) {
        for (int col = 0; col < kernelSize; col++) {
            cout << kernel[col + row * kernelSize] << " ";
        }
        cout << endl;
    }
    cout << "result data" << endl;
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            cout << result[col + row * width] << " ";
        }
        cout << endl;
    }
    delete[] img;
    delete[] kernel;
    delete[] result;
}