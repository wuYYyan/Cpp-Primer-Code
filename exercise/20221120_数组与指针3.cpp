//日期：20221120
//内容：数组与数组首元素的地址
#include <iostream>

using namespace std;

int main()
{
    int arr[3] = {1, 2, 3};

    //输出值一样，但含义不一样
    cout << arr << endl; //代表数组中第一个元素的地址
    cout << &arr << endl; //代表整个数组的地址

    //输出值不一样，含义也不一样
    cout << arr + 1 << endl;  //指向下一个四字节的地址
    cout << &arr + 1 << endl; //指向下一个十二个字节的地址

    return 0;
}