// https://www.cnblogs.com/chengxiao/p/6129630.html
#include <iostream>
#include <vector>

using namespace std;

void adjust(vector<int>& arr, int parent, int length)
{
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    int newParent = parent;
    if (left < length && arr[left] > arr[newParent]) {
        newParent = left;
    }
    if (right < length && arr[right] > arr[newParent]) {
        newParent = right;
    }
    if (newParent != parent) {
        swap(arr[newParent], arr[parent]);
        adjust(arr, newParent, length);
    }
}

void HeapSort(vector<int>& arr)
{
    // Build big top heap
    for (int i = arr.size() / 2 - 1; i >= 0; i--) {
        adjust(arr, i, arr.size());
    }
    // adjust big top head
    for (int i = arr.size() - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        adjust(arr, 0, i);
    }
}

int main()
{
    vector<int> arr { 5, 6, 8, 3, 2, 7, 1, 9 };
    HeapSort(arr);
    for (int i : arr) {
        cout << i << endl;
    }
    return 0;
}
