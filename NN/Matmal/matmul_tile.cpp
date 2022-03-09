#include <omp.h>

#include <iostream>
#include <vector>

using namespace std;

void matMulCPU1(float* A, float* B, float* C, int M, int K, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < K; k++) {
                C[i * N + j] += A[i * K + k] * B[k * N + j];
            }
        }
    }
}

void matMulCPUTileJ(float* A, float* B, float* C, int M, int K, int N) {
    int tj = 4;
    for (int j1 = 0; j1 < N; j1 += tj) {
        for (int i = 0; i < M; i++) {
            for (int k = 0; k < K; k++) {
                for (int j2 = 0; j2 < tj; j2++) {
                    C[i * N + j2] += A[i * K + k] * B[k * N + j2];
                }
            }
        }
    }
}
void matMulCPUTileJK(float* A, float* B, float* C, int M, int K, int N) {
    int tj = 4;
    int tk = 4;
    for (int k1 = 0; k1 < K; k1 += tk) {
        for (int j1 = 0; j1 < N; j1 += tj) {
            for (int i = 0; i < M; i++) {
                for (int k2 = 0; k2 < tk; k++) {
                    for (int j2 = 0; j2 < tj; j2++) {
                        C[i * N + j2] += A[i * K + k] * B[k * N + j2];
                    }
                }
            }
        }
    }
}

inline void addDot(int M, int N, int K, float* A, float* B, float* C) {
    for (int k = 0; k < K; k++) {
        *C += A[k] * B[k * N];
    }
}

void matMulCPU2(float* A, float* B, float* C, int M, int K, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            addDot(M, N, K, (A + i * K), (B + j), (C + i * N + j));
        }
    }
}
// 1x4
inline void addDot1x4(int M, int N, int K, float* A, float* B, float* C) {
    // 4x1 output matrix C
    register float cReg00 = 0.0;
    register float cReg10 = 0.0;
    register float cReg20 = 0.0;
    register float cReg30 = 0.0;

    register float bReg = 0.0;

    float* a00 = A;
    float* a10 = A + K;
    float* a20 = A + 2 * K;
    float* a30 = A + 3 * K;

    for (int k = 0; k < K; k += 4) {
        bReg = *(B + k * N);
        cReg00 += bReg * *a00++;
        cReg10 += bReg * *a10++;
        cReg20 += bReg * *a20++;
        cReg30 += bReg * *a30++;

        bReg = *(B + (k + 1) * N);
        cReg00 += bReg * *a00++;
        cReg10 += bReg * *a10++;
        cReg20 += bReg * *a20++;
        cReg30 += bReg * *a30++;

        bReg = *(B + (k + 2) * N);
        cReg00 += bReg * *a00++;
        cReg10 += bReg * *a10++;
        cReg20 += bReg * *a20++;
        cReg30 += bReg * *a30++;

        bReg = *(B + (k + 3) * N);
        cReg00 += bReg * *a00++;
        cReg10 += bReg * *a10++;
        cReg20 += bReg * *a20++;
        cReg30 += bReg * *a30++;
    }
    *(C + 0 * N) += cReg00;
    *(C + 1 * N) += cReg10;
    *(C + 2 * N) += cReg20;
    *(C + 3 * N) += cReg30;
}

void matMulCPU3(float* A, float* B, float* C, int M, int K, int N) {
    for (int i = 0; i < M; i += 4) {
        for (int j = 0; j < N; j++) {
            addDot1x4(M, N, K, (A + i * K), (B + j), (C + i * N + j));
        }
    }
}
// 4x4
void addDot4x4(int M, int N, int K, float* A, float* B, float* C) {
    // 4x4 output matrix C
    register float cReg00 = 0.0;
    register float cReg01 = 0.0;
    register float cReg02 = 0.0;
    register float cReg03 = 0.0;
    register float cReg10 = 0.0;
    register float cReg11 = 0.0;
    register float cReg12 = 0.0;
    register float cReg13 = 0.0;
    register float cReg20 = 0.0;
    register float cReg21 = 0.0;
    register float cReg22 = 0.0;
    register float cReg23 = 0.0;
    register float cReg30 = 0.0;
    register float cReg31 = 0.0;
    register float cReg32 = 0.0;
    register float cReg33 = 0.0;
    // matrix A
    register float aReg00 = 0.0;
    register float aReg10 = 0.0;
    register float aReg20 = 0.0;
    register float aReg30 = 0.0;
    // matrix B
    register float bReg00 = 0.0;
    register float bReg01 = 0.0;
    register float bReg02 = 0.0;
    register float bReg03 = 0.0;

    float* a00 = A;
    float* a10 = A + K;
    float* a20 = A + 2 * K;
    float* a30 = A + 3 * K;

    for (int k = 0; k < K; k++) {
        aReg00 = *a00++;
        aReg10 = *a10++;
        aReg20 = *a20++;
        aReg30 = *a30++;

        bReg00 = *(B + k * N + 0);
        bReg01 = *(B + k * N + 1);
        bReg02 = *(B + k * N + 2);
        bReg03 = *(B + k * N + 3);

        // First row
        cReg00 += aReg00 * bReg00;
        cReg01 += aReg00 * bReg01;
        cReg02 += aReg00 * bReg02;
        cReg03 += aReg00 * bReg03;
        // Second row
        cReg10 += aReg10 * bReg00;
        cReg11 += aReg10 * bReg01;
        cReg12 += aReg10 * bReg02;
        cReg13 += aReg10 * bReg03;
        // Third row
        cReg20 += aReg20 * bReg00;
        cReg21 += aReg20 * bReg01;
        cReg22 += aReg20 * bReg02;
        cReg23 += aReg20 * bReg03;
        // Forth row
        cReg30 += aReg30 * bReg00;
        cReg31 += aReg30 * bReg01;
        cReg32 += aReg30 * bReg02;
        cReg33 += aReg30 * bReg03;
    }
    *(C + 0 * N + 0) += cReg00;
    *(C + 0 * N + 1) += cReg01;
    *(C + 0 * N + 2) += cReg02;
    *(C + 0 * N + 3) += cReg03;
    *(C + 1 * N + 0) += cReg10;
    *(C + 1 * N + 1) += cReg11;
    *(C + 1 * N + 2) += cReg12;
    *(C + 1 * N + 3) += cReg13;
    *(C + 2 * N + 0) += cReg20;
    *(C + 2 * N + 1) += cReg21;
    *(C + 2 * N + 2) += cReg22;
    *(C + 2 * N + 3) += cReg23;
    *(C + 3 * N + 0) += cReg30;
    *(C + 3 * N + 1) += cReg31;
    *(C + 3 * N + 2) += cReg32;
    *(C + 3 * N + 3) += cReg33;
}
void matMulCPU4(float* A, float* B, float* C, int M, int K, int N) {
    for (int i = 0; i < M; i += 4) {
        for (int j = 0; j < N; j += 4) {
            addDot4x4(M, N, K, (A + i * K), (B + j), (C + i * N + j));
        }
    }
}
int main(void) {
    int M = 512;
    int K = 2048;
    int N = 512;

    vector<float> A(M * K);
    vector<float> B(K * N);
    for (int i = 0; i < M * K; i++) {
        A[i] = rand() % 10 + 1;
    }
    for (int i = 0; i < K * M; i++) {
        B[i] = rand() % 10 + 1;
    }

    vector<float> C1(M * N);
    float dtime = omp_get_wtime();
    matMulCPU1(A.data(), B.data(), C1.data(), M, K, N);
    dtime = omp_get_wtime() - dtime;
    cout << "Running1 Time : " << dtime << endl;

    vector<float> C2(M * N);
    dtime = omp_get_wtime();
    matMulCPU2(A.data(), B.data(), C2.data(), M, K, N);
    dtime = omp_get_wtime() - dtime;
    cout << "Running2 Time : " << dtime << endl;

    vector<float> C3(M * N);
    dtime = omp_get_wtime();
    matMulCPU3(A.data(), B.data(), C3.data(), M, K, N);
    dtime = omp_get_wtime() - dtime;
    cout << "Running3 Time : " << dtime << endl;

    vector<float> C4(M * N);
    dtime = omp_get_wtime();
    matMulCPU4(A.data(), B.data(), C4.data(), M, K, N);
    dtime = omp_get_wtime() - dtime;
    cout << "Running4 Time : " << dtime << endl;

    if (C1 == C2 && C1 == C3 && C1 == C4) {
        cout << "correct" << endl;
    } else {
        cout << "error" << endl;
    }

    return 0;
}
