// https://blog.csdn.net/qq_28584889/article/details/88136498
#include <iostream>
#include <vector>

using namespace std;

int paratition(int left, int right, vector<int>& arr)
{
    int base = arr[left];
    int i = left;
    int j = right;
    while (i < j) {
        while (base <= arr[j] && i < j) {
            j--;
        }
        while (base >= arr[i] && i < j) {
            i++;
        }
        swap(arr[i], arr[j]);
    }
    swap(arr[left], arr[i]);
    return i;
}
void quickSort(int left, int right, vector<int>& arr)
{
    if (left >= right) {
        return;
    }
    int pos = paratition(left, right, arr);
    quickSort(left, pos - 1, arr);
    quickSort(pos + 1, right, arr);
}
void quickSort(vector<int>& arr)
{
    quickSort(0, arr.size(), arr);
}
int main()
{
    vector<int> arr { 5, 6, 8, 3, 2, 7, 1, 9 };
    quickSort(arr);
    for (int i : arr) {
        cout << i << endl;
    }
    return 0;
}
