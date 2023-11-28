#include <stdio.h>

int main() {
    const int x = 3;
    printf("x = %d\n", x);

    int *p = &x;
    *p = 4;
    printf("x = %d\n", x); // 证明还是可以通过指针间接修改x的值

    // int arr[x] = {1, 2, 3, 4}; // error，不可以使用变量定义数组大小

    return 0;
}