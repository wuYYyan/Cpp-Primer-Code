// ��֪����������a = 10��b = 20��Ҫ������������ֵ���н���
// ���մ�ӡ���Ϊ��a = 20��b = 10
#include <iostream>

using namespace std;

int main()
{
    // �����壺ָ������
    int *a = new int(10);
    int *b = new int(20); 

    cout << a << "`````";
    cout << b << "`````";

    if (a < b){
        a = (int*)(b - a); 
        cout << a << "`````";

        b = (int*)(b - (long(a) & 0x0000ffff));
        cout << b << "`````";
        
        a = (int*)(b + long(a));
        cout << a << "`````";
    } else {
        b = (int*)(a - b); 
        cout << b << "`````";

        a = (int*)(a - (long(b) & 0x0000ffff));
        cout << a << "`````";
        
        b = (int*)(a + long(b));
        cout << b << "`````";
    }

    return 0;
}