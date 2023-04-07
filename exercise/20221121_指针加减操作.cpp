//日期：20221121
//内容：指针加减操作
#include <iostream>

using namespace std;

int main()
{
    int arr[3] = {1, 2, 3};
    int *pa = arr;

    cout << arr << endl;
    cout << pa << endl;

    pa = pa + 2;
    cout << pa - arr << endl; //必须相同类型的指针才能进行相减操作
    
    return 0;
}