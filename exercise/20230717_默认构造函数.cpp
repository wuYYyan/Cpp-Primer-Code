#include <iostream>

using namespace std;

class A
{
    public:
        void show()
        {
            cout << "A::a = " << a << endl;
        }

    private:
        int a;
};

struct B
{
    void show()
    {
        cout << "B::b = " << b << endl;
    }
    int b;
};

int main()
{
    A a; //Ĭ�Ϲ��캯�����ṩ���ڳ�ʼֵ�ĳ�Ա��������ֵ��ʼ��
    a.show();

    B b;
    b.show();

    return 0;
}
