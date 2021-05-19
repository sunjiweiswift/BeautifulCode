#include <omp.h>

#include <iostream>

using namespace std;

void matMulCPUOpenMP(float* A, float* B, float* C, int M, int K, int N) {
#pragma omp parallel for num_threads(16)
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            float sum = 0.0f;
            for (int k = 0; k < K; k++) {
                sum += A[i * K + k] * B[k * N + j];
            }
            C[i * N + j] = sum;
        }
    }
}

void matMulCPUOpenMPErr(float* A, float* B, float* C, int M, int K, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            float sum = 0.0f;
#pragma omp parallel for num_threads(16)
            for (int k = 0; k < K; k++) {
                sum += A[i * K + k] * B[k * N + j];
            }
            C[i * N + j] = sum;
        }
    }
}
void matMulCPUOK(float* A, float* B, float* C, int M, int K, int N) {
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                C[i * N + j] += A[i * K + k] * B[k * N + j];
            }
        }
    }
}

void matMulCPUErr1(float* A, float* B, float* C, int M, int K, int N) {
    for (int k = 0; k < K; k++) {
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < M; i++) { // A read by col
                C[i * N + j] += A[i * K + k] * B[k * N + j];
            }
        }
    }
}
void matMulCPUErr2(float* A, float* B, float* C, int M, int K, int N) {
    for (int i = 0; i < M; i++) { // outer is not k
        for (int j = 0; j < N; j++) {
            float sum = 0.0f;
            for (int k = 0; k < K; k++) {
                sum += A[i * K + k] * B[k * N + j];
            }
            C[i * N + j] = sum;
        }
    }
}

void matMulCPUErr2(float* A, float* B, float* C, int M, int K, int N) {
    for (int i = 0; i < M; i++) { // outer is not k
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < K; k++) { // every step need to modify C
                C[i * N + j] += A[i * K + k] * B[k * N + j];
            }
        }
    }
}

int main(void) {
    int M = 512;
    int K = 512;
    int N = 512;

    float* A = new float[M * K];
    float* B = new float[K * N];
    float* C = new float[M * N];
    for (int i = 0; i < M * K; i++) {
        A[i] = 1;
    }
    for (int i = 0; i < K * M; i++) {
        B[i] = 1;
    }

    float dtime = omp_get_wtime();
    matMulCPUOK(A, B, C, M, K, N);
    dtime = omp_get_wtime() - dtime;
    cout << "Running1 Time : " << dtime << endl;

    dtime = omp_get_wtime();
    matMulCPUOpenMP(A, B, C, M, K, N);
    dtime = omp_get_wtime() - dtime;
    cout << "Running2 Time : " << dtime << endl;

    dtime = omp_get_wtime();
    matMulCPUOpenMPErr(A, B, C, M, K, N);
    dtime = omp_get_wtime() - dtime;
    cout << "Running3 Time : " << dtime << endl;

    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
