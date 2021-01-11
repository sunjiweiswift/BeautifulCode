#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (arr[i] < arr[j]) {
                swap(arr[j], arr[i]);
            }
        }
    }
}
int main() {
    vector<int> arr{5, 6, 8, 3, 2, 7, 1, 9};
    BubbleSort(arr);
    for (int i : arr) {
        cout << i << endl;
    }
    return 0;
}
