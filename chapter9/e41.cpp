#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<char> v = {'h', 'e', 'l', 'l', 'o'};
    string str(v.data(), v.size()); //成员函数data返回首元素的地址
    cout << str << endl;

    return 0;
}