vector<vector<int>> RotatoMatrix90(vector<vector<int>>& matrix) {
    int height = matrix.size();
    int width = matrix[0].size();
    vector<vector<int>> ret(width, vector<int>(height));
    for (size_t row = 0; row < matrix.size(); row++) {
        for (size_t col = 0; col < matrix[0].size(); col++) {
            ret[col][height - 1 - row] = matrix[row][col];
        }
    }
    return ret;
}

vector<vector<int>> RotatoMatrix180(vector<vector<int>>& matrix) {
    int height = matrix.size();
    int width = matrix[0].size();
    vector<vector<int>> ret(height, vector<int>(width));
    for (size_t row = 0; row < matrix.size(); row++) {
        for (size_t col = 0; col < matrix[0].size(); col++) {
            ret[height - 1 - row][width - 1 - col] = matrix[row][col];
        }
    }
    return ret;
}

vector<vector<int>> RotatoMatrix270(vector<vector<int>>& matrix) {
    int height = matrix.size();
    int width = matrix[0].size();
    vector<vector<int>> ret(width, vector<int>(height));
    for (size_t row = 0; row < matrix.size(); row++) {
        for (size_t col = 0; col < matrix[0].size(); col++) {
            ret[width - 1 - col][row] = matrix[row][col];
        }
    }
    return ret;
}
