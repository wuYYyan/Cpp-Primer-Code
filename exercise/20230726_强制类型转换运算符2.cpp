#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    double b, c = 20.6;

    b = static_cast<double>(a);
    a = static_cast<int>(c);

    // ��Ȼ˵������static_castҲ����ת���ɹ�������static_cast�����ڱ���ʱ��������ת���Ƿ�Ϸ�
    // b = a;
    // a = c;
    // ��������ת����������ֱ��ȥ��С�����֣���������������

    cout << "b = " << b << endl;
    cout << "a = " << a << endl;

    return 0;
}