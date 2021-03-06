#include <iostream>
#include <vector>

using namespace std;

void InsertSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        int insertNum = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > insertNum) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = insertNum;
    }
}

int main() {
    vector<int> arr{5, 6, 8, 3, 2, 7, 1, 9};
    InsertSort(arr);
    for (int i : arr) {
        cout << i << endl;
    }
    return 0;
}