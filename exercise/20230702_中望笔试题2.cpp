#include <iostream>

using namespace std;

int main()
{
    const char* p = "abc"; //字符串常量存放在只读段的文字常量区
    // cout << p << endl; 
    char* c = (char*)p;  
    // c[1] = 'g'; 
    cout << p << endl;
    cout << c << endl;
}

