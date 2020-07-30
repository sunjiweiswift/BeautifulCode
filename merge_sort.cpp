#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>& arr)
{
    if (arr.size() == 1) {
        return;
    }
    int mid = (arr.size()) / 2;
    vector<int> leftArr(arr.begin(), arr.begin() + mid);
    vector<int> rightArr(arr.begin() + mid, arr.end());
    mergeSort(leftArr);
    mergeSort(rightArr);

    vector<int>::iterator leftIter = leftArr.begin();
    vector<int>::iterator rightIter = rightArr.begin();
    vector<int>::iterator arrIter = arr.begin();
    while (arrIter != arr.end()) {
        if (leftIter == leftArr.end()) {
            *arrIter = *rightIter;
            rightIter++;
        } else if (rightIter == rightArr.end()) {
            *arrIter = *leftIter;
            leftIter++;
        } else if (*leftIter > *rightIter) {
            *arrIter = *rightIter;
            rightIter++;
        } else {
            *arrIter = *leftIter;
            leftIter++;
        }
        arrIter++;
    }
}
int main()
{
    vector<int> arr { 5, 6, 8, 3, 2, 7, 1, 9 };
    mergeSort(arr);
    for (int i : arr) {
        cout << i << endl;
    }
    return 0;
}
