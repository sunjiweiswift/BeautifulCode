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
