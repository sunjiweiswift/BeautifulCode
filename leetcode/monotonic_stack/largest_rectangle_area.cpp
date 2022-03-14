class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> stk;
        int ret = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                int a = stk.top();
                stk.pop();
                if (stk.empty()) {
                    ret = max(ret, heights[a] * i);
                } else {
                    ret = max(ret, heights[a] * (i - stk.top() - 1));
                }
            }
            stk.push(i);
        }
        return ret;
    }
};
