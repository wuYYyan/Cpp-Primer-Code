#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s1{"123"};
    string s2{"45699999999999999999"};

    auto it1 = s1.begin();
    auto it2 = s2.begin();
    auto &r = s1[0];

    cout << "Before swap(): " << endl;
    cout << "&it1 = " << &it1 << ", *it1 = " << *it1 << endl;
    cout << "&it2 = " << &it2 << ", *it2 = " << *it2 << endl;
    cout << "&r = " << &r << ", r = " << r << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    s1.swap(s2);
    cout << "After swap(): " << endl;
    cout << "&it1 = " << &it1 << ", *it1 = " << *it1 << endl;
    cout << "&it2 = " << &it2 << ", *it2 = " << *it2 << endl;
    cout << "&r = " << &r << "r = " << r << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    return 0;
}