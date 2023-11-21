#include <iostream>

using namespace std;

int main()
{
    // 选择题1
    int k = 7 >> 1;
    cout << "k = " << k << endl; // k = 3

    // 选择题2
    int j;
    int a = (j = 3, j ++); // 只要在一个表达式中前置运算和后置运算就不一样，这是个逗号表达式
    cout << "a = " << a << endl; // a = 3

    // 选择题3
    int arr[3] = {1, 2, 3};
    cout << arr << endl;
    cout << *arr << endl;
    cout << *(arr + 1) << endl;
    cout << arr[0] << endl;
    // cout << arr ++ << endl; // 表达式必须是可修改的左值，数组名是 const 常量

    // 选择题4
    char ch[] = "abc\0def";
    char *p = ch;
    printf("%c", *p + 4); // e
    
    return 0;
}