#include <iostream>
#include <vector>

using namespace std;

void StraightSort(vector<int>& arr) {
    for (int i = 1, j; i < arr.size(); i++) {
        int insert = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > insert; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = insert;
    }
}

int main() {
    vector<int> arr{5, 6, 8, 3, 2, 7, 1, 9};
    StraightSort(arr);
    for (int i : arr) {
        cout << i << endl;
    }
    return 0;
}
