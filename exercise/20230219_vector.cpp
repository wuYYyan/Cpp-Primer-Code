#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    int len = 5;
    vector<vector<int>> arr;
    vector<int> arr1, arr2, arr3, arr4; //创建空对象

    //赋值方法一，使用方括号索引查询时必须指定长度
    arr1.resize(len); // 初始化方式：vector<int> arr1(len);
    for (int i = 0; i < len; i ++)
    {
        arr1[i] = 2 * i; 
    }
    cout << "输出 arr1 中的元素: ";
    for (auto &i : arr1)
        cout << i << ' ';
    cout << endl;
         
    //赋值方法二，产生元素值相同的动态数组
    arr2 = vector<int>(len, 6); // 初始化方式：vector<int> arr2(len, 6);
    cout << "输出 arr2 中的元素: ";
    for (auto &i : arr2)
        cout << i << ' ';
    cout << endl;

    //赋值方法三，在未对动态数组指定长度之前使用库函数push_back
    //cout << arr.size() << endl; //未指定具体长度时为零
    for (int i = 0; i < len; i ++)
        arr3.push_back(2 * i + 1);
    cout << "输出 arr3 中的元素: ";
    for (auto &i : arr3)
        cout << i << ' ';
    cout << endl;

    //赋值方法四，成员初始化列表
    arr4 = {10, -1, 0, 20, 11};
    cout << "输出 arr4 中的元素: ";
    for (auto &i : arr4)
        cout << i << ' ';
    cout << endl;

    //二维vector初始化
    arr.push_back(arr1);
    arr.push_back(arr2);
    arr.push_back(arr3);
    arr.push_back(arr4);
    cout << "此时arr 有" << arr.size() << "行、" << arr[0].size() << "列" << endl; 

    //按照第一个元素的字典序进行比较
    if (arr1 < arr2)
        puts("arr1 < arr2");

    //清空方法一，使用库函数clear
    arr2.clear();
    cout << "此时 arr2 中的元素个数为: " << arr2.size() << ", ";
    if (arr2.empty()) //库函数empty的时间复杂度为O(1)
        cout << "因此 arr2 为空" << endl;
    else
        cout << "因此 arr2 不为空" << endl;

    //清空方法二，使用库函数pop_back
    for (int i = 0; i < len; i ++)
        arr3.pop_back();
    cout << "此时 arr3 中的元素个数为: " << arr3.size() << ", ";
    if (arr3.size()) //库函数size的时间复杂度为O(1)
        cout << "因此 arr3 不为空" << endl;
    else
        cout << "因此 arr3 为空" << endl;

    //插入
    arr1.insert(arr1.end(), arr4.begin(), arr4.end());
    cout << "插入之后 arr1 中的元素: ";
    for (auto &i : arr1)
        cout << i << ' ';
    cout << endl;

    //信息
    cout << "arr1 中的第一个元素是: " << arr1.front() << endl;
    cout << "arr1 中的最后一个元素是: " << arr1.back() << endl;
    cout << "arr1 中的最大值是: " << *max_element(arr1.begin(), arr1.end()) << endl;
    cout << "arr1 中的最小值是: " << *min_element(arr1.begin(), arr1.end()) << endl;
    cout << "arr1 中的元素总和是: " << accumulate(arr1.begin(), arr1.end(), 0.0) << endl;

    //翻转
    reverse(arr1.begin(), arr1.end());
    cout << "翻转之后 arr1 中的元素: ";
    for (auto &i : arr1)
        cout << i << ' ';
    cout << endl;

    //排序
    sort(arr1.begin(), arr1.end());
    cout << "排序之后 arr1 中的元素: ";
    for (auto &i : arr1)
        cout << i << ' ';
    cout << endl;

    //迭代器
    for (auto i = arr1.begin(); i != arr1.end(); i ++)
        cout << *i << ' '; //迭代器可以看作是一个指针
    cout << endl;

    //与上面的引用迭代器遍历差不多，只不过这个没加引用
    for (auto i : arr1)
        cout << i << ' ';
    cout << endl;

    return 0;
}
