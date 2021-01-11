#include <iostream>
#include <vector>

#include "top_k_frequent.h"

using namespace std;
int main() {
    vector<int> input{1, 1, 1, 2, 2, 3};
    int k = 2;
    Solution solution;
    vector<int> result = solution.topKFrequent(input, k);
    for (int num : result) {
        cout << num << endl;
    }
    return 0;
}