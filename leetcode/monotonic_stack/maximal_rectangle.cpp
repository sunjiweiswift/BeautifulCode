class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        vector<int> heights(matrix[0].size(), 0);
        int result = 0;
        for (size_t row = 0; row < matrix.size(); row++) {
            for (size_t col = 0; col < matrix[0].size(); col++) {
                if (matrix[row][col] == '1') {
                    heights[col]++;
                } else {
                    heights[col] = 0;
                }
            }
            result = max(result, largestRectangleArea(heights));
        }
        return result;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        heights.push_back(0);
        stack<int> stk;
        for (int index = 0; index < heights.size(); index++) {
            while (!stk.empty() && heights[index] <= heights[stk.top()]) {
                int height = heights[stk.top()];
                stk.pop();
                if (stk.empty()) {
                    result = max(result, height * index);
                } else {
                    result = max(result, height * (index - stk.top() - 1));
                }
            }
            stk.push(index);
        }
        return result;
    }
};
