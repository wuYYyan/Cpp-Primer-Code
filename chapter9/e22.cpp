#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    vector<int> ivec = {1, 2, 3, 3, 5, 6, 7, 8, 9, 10};
    vector<int>::iterator iter = ivec.begin();
    int n = ivec.size(), some_value = 3;

    for(int i = 0; i < n / 2; i ++)
    {
        if(*iter == some_value)
        {
            iter = ivec.insert(iter, 2 * some_value);
            iter += 2; //注意成员函数insert返回的迭代器指向新插入的元素
        }
        else
            iter++;
    }

    for(const auto &r : ivec)
        cout << r << " ";
    cout << endl;

    return 0;
}