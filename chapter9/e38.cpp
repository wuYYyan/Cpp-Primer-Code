#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;

    //v.reserve(10); //有没有这一行语句效果完全不一样
    cout << "v.size() = " << v.size() << endl;
    cout << "v.capacity() = " << v.capacity() << endl;
    cout << "--------------------------" << endl;

    for(int i = 0; i < 100;i ++)
    {
        v.push_back(i);
        cout << "v.size() = " << v.size() << endl;
        cout << "v.capacity() = " << v.capacity() << endl;
        cout << "--------------------------" << endl;
    }

    v.reserve(20);
    cout << "v.size() = " << v.size() << endl;
    cout << "v.capacity() = " << v.capacity() << endl;
    cout << "--------------------------" << endl;

    return 0;
}