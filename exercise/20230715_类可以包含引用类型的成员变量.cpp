#include <iostream>

using namespace std;

class Widget
{
    public:
        // ����һ�����캯���β�Ϊ��ֵ�����ܱ�֤��ȷ��
        // error: call to constructor of 'Ref' is ambiguous
        // Widget (int target) : myref(target)
        // {
        //      cout << "Ref ctor" << endl;
        // }
    
        // �����������������ø�ֵ�������������δ��ʼ��
        // error: constructor for 'Ref' must explicitly initialize the reference member 'myref'
        // Widget (int &target)  {
        //      myref = target;
        //      cout << "Ref ctor" << endl;
        // }
    
        // �����Ա����Ϊ�������ͣ���ô���캯������Ӧ����ҲΪ��������
        // ���ñ����ڳ�Ա��ʼ���б������ʼ���������ں����������ʼ��
        // �ں����������޸�data���൱�ڸ�ֵ����Ȼ���ò��ܸ�ֵ
        Widget (int &target) : data(target) {
            cout << "constructor" << endl;
        }
    
        void print() {
            cout << "data value: " << data << endl;
        }

        void modified() {
            data = 20;
        }
    
        // ~Widget () {}
    
    private:
        int &data;
};

int main()
{
    cout << "Hello World!" << endl;

    int a = 10;
    Widget w(a);
    w.print();
    w.modified(); //ͨ�������ڲ��޸��������͵ĳ�Ա����������޸����ⲿ����a
    cout << "a = " << a << endl;

    return 0;
}