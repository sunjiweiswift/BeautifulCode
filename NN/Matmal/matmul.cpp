#include <omp.h>

#include <iostream>

using namespace std;

void matMulCPUOpenMP(float* A, float* B, float* C, int aHeight, int aWidth, int bWidth) {
#pragma omp parallel for num_threads(16)
    for (int i = 0; i < aHeight; i++) {
        for (int j = 0; j < bWidth; j++) {
            float sum = 0.0f;
            for (int k = 0; k < aWidth; k++) {
                sum += A[i * aWidth + k] * B[k * bWidth + j];
            }
            C[i * bWidth + j] = sum;
        }
    }
}

void matMulCPUOpenMPErr(float* A, float* B, float* C, int aHeight, int aWidth, int bWidth) {
    for (int i = 0; i < aHeight; i++) {
        for (int j = 0; j < bWidth; j++) {
            float sum = 0.0f;
#pragma omp parallel for num_threads(16)
            for (int k = 0; k < aWidth; k++) {
                sum += A[i * aWidth + k] * B[k * bWidth + j];
            }
            C[i * bWidth + j] = sum;
        }
    }
}
void matMulCPU(float* A, float* B, float* C, int aHeight, int aWidth, int bWidth) {
    for (int i = 0; i < aHeight; i++) {
        for (int j = 0; j < bWidth; j++) {
            float sum = 0.0f;
            for (int k = 0; k < aWidth; k++) {
                sum += A[i * aWidth + k] * B[k * bWidth + j];
            }
            C[i * bWidth + j] = sum;
        }
    }
}

int main(void) {
    int aHeight = 512;
    int aWidth = 512;
    int bWidth = 512;

    float* A = new float[aHeight * aWidth];
    float* B = new float[aWidth * bWidth];
    float* C = new float[aHeight * bWidth];
    for (int i = 0; i < aHeight * aHeight; i++) {
        A[i] = rand() / RAND_MAX;
        B[i] = rand() / RAND_MAX;
    }

    float dtime = omp_get_wtime();
    matMulCPU(A, B, C, aHeight, aWidth, bWidth);
    dtime = omp_get_wtime() - dtime;
    cout << "Running1 Time : " << dtime << endl;

    dtime = omp_get_wtime();
    matMulCPUOpenMP(A, B, C, aHeight, aWidth, bWidth);
    dtime = omp_get_wtime() - dtime;
    cout << "Running2 Time : " << dtime << endl;

    dtime = omp_get_wtime();
    matMulCPUOpenMPErr(A, B, C, aHeight, aWidth, bWidth);
    dtime = omp_get_wtime() - dtime;
    cout << "Running3 Time : " << dtime << endl;

    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
