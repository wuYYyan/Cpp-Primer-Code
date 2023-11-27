#include <iostream>

using namespace std;

const int SIZE = 10;

void split_odd_even(const int arr[], int size_s, int *&odd_ptr, int &size_o, int *&even_ptr, int &size_e);

int main() {
    int arr[SIZE] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *odd {nullptr};
    int *even {nullptr};
    int odd_size {0}, even_size {0};

    split_odd_even(arr, SIZE, odd, odd_size, even, even_size);
    
    for (int i = 0; i < odd_size; i ++)
        cout << odd[i] << " ";
    cout << endl;
    for (int i = 0; i < even_size; i ++)
        cout << even[i] << " ";
    cout << endl;

    delete[] odd;
    odd = nullptr;
    delete[] even;
    even = nullptr;

    return 0;
}

// 对比使用二级指针传递参数的方式，更加好理解
void split_odd_even(const int arr[], int size_s, int *&odd_ptr, int &size_o, int *&even_ptr, int &size_e) {
    for (int i = 0; i < size_s; i ++) {
        if (arr[i] % 2 == 0) {
            even_ptr = (int *)realloc(even_ptr, (size_e + 1) * sizeof(int));
            (even_ptr)[size_e] = arr[i];
            size_e ++;
        } else {
            odd_ptr = (int *)realloc(odd_ptr, (size_o + 1) * sizeof(int));
            (odd_ptr)[size_o] = arr[i];
            size_o ++;
        }
    }
}