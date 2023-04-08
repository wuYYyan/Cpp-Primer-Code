#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec1; //空容器
    vector<int> ivec2(ivec1); //拷贝构造
    vector<int> ivec3{1, 2, 3, 4, 5}; //列表初始化
    vector<int> ivec4(ivec3.begin(), ivec3.end()); //迭代器范围拷贝
    vector<int> ivec5(6); //具有6个元素的容器，每个元素均为0
    vector<int> ivec6(7, 8); //具有7个元素的容器，每个元素均为8

    return 0;
}