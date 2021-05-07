#include <iostream>
#include <vector>

using namespace std;
void ShellSort(vector<int>& arr) {
    int gap = arr.size() / 2;
    while (gap >= 1) {
        for (int i = gap; i < arr.size(); i++) {
            int insertNum = arr[i];
            int j = i - gap;
            while (j >= 0 && insertNum < arr[j]) {
                arr[j + gap] = arr[j];
                j = j - gap;
            }
            arr[j + gap] = insertNum;
        }

        gap = gap / 2;
    }
}

int main() {
    vector<int> arr{5, 6, 8, 3, 2, 7, 1, 9};
    ShellSort(arr);
    for (int i : arr) {
        cout << i << endl;
    }
    return 0;
}