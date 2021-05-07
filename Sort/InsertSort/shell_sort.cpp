#include <iostream>
#include <vector>

using namespace std;
void ShellSort(vector<int>& arr) {}

int main() {
    vector<int> arr{5, 6, 8, 3, 2, 7, 1, 9};
    ShellSort(arr);
    for (int i : arr) {
        cout << i << endl;
    }
    return 0;
}