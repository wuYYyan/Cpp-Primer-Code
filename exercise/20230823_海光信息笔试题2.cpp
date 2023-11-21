#include <iostream>

using namespace std;

int main()
{
    int arr[2][3] = {1, 2, 3, 4, 5, 6};
    // 二维数组名是指向指针的指针

    cout << **(arr + 1) << endl; // 4
    cout << *(arr[1] + 1) << endl; // 5

    return 0;
}