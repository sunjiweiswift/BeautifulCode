void Img2Col(float* img, int channels, int height, int width, int kernelSize, int stride, int pad,
             float* col) {
    int colHeight = (height + 2 * pad - kernelSize) / stride + 1;
    int colWidth = (width + 2 * pad - kernelSize) / stride + 1;
    int colChannels = channels * kernelSize * kernelSize;
    
}