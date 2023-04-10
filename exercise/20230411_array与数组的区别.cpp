#include <array>
#include <iostream>

using namespace std;

int main()
{
    array<int, 10> arr1 = {1, 2, 3}; //未赋值的元素执行值初始化
    array<int, 10> arr2 = {6, 6, 6};

    for(const auto &r : arr1)
        cout << r << " ";
    cout << endl;

    arr1 = arr2; //类型相同的array可以相互赋值，array的类型包括元素类型与容器大小
    arr2 = {1}; //可以使用花括号列表为array赋值

    return 0;
}