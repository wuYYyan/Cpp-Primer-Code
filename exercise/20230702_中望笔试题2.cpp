#include <iostream>

using namespace std;

int main()
{
    const char* p = "abc"; //�ַ������������ֻ���ε����ֳ�����
    // cout << p << endl; 
    char* c = (char*)p;  
    // c[1] = 'g'; 
    cout << p << endl;
    cout << c << endl;
}

