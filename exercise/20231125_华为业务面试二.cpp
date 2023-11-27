#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void quick_sort(int *arr, int l, int r);
void merge_sort(int *arr, int l, int r);

void SortIntegerArray1(int * pIntegerArray, int iMemberNum, int iSortFlag){
    quick_sort(pIntegerArray, 0, iMemberNum - 1);
    if (iSortFlag)
        reverse(pIntegerArray, pIntegerArray + iMemberNum);
}

void SortIntegerArray2(int * pIntegerArray, int iMemberNum, int iSortFlag){
    merge_sort(pIntegerArray, 0, iMemberNum - 1);
    if (iSortFlag)
        reverse(pIntegerArray, pIntegerArray + iMemberNum);
}

void quick_sort(int *arr, int l, int r) {
    if (l >= r) return;
    int x = arr[(l + r) / 2];
    int i = l - 1, j = r + 1;
    while (i < j) {
        do i ++; while (arr[i] < x);
        do j --; while (arr[j] > x);
        if (i < j) swap(arr[i], arr[j]);
    }
    quick_sort(arr, l, j);
    quick_sort(arr, j + 1, r);
}

void merge_sort(int *arr, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    vector<int> tmp(r - l + 1);
    while (i <= mid && j <= r) {
        if (arr[i] < arr[j])
            tmp[k ++] = arr[i ++];
        else 
            tmp[k ++] = arr[j ++];
    }
    while (i <= mid) tmp[k ++] = arr[i ++];
    while (j <= r) tmp[j ++] = arr[j ++];
    for (int i = l, j = 0; i <= r; i ++, j ++)
        arr[i] = tmp[j];
}

int main() {
    int arr[5] = {1, 6, 4, 8, 3};
    
    SortIntegerArray1(arr, 5, 1);
    for (int i = 0; i <= 5 ; i ++)
        cout << arr[i] << " ";
    cout << endl;

    SortIntegerArray2(arr, 5, 1);
    for (int i = 0; i <= 5 ; i ++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}