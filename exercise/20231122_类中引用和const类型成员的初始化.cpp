#include <iostream>

using namespace std;

/*
�����������ó�Ա��const���ͳ�Աʱ����Ĭ�Ϲ��캯����ɾ����
��Ҫ�ڸ������캯���г�ʼ������ֻ���ڳ�Ա��ʼ���б��г�ʼ�����������ڹ��캯���������г�ʼ��
���������ඨ��ʱֱ�ӳ�ʼ��һ�����е�ֵ(ָ��ָ���Ѷ����ȫ�ֱ��������ð������е�ȫ�ֱ���)
*/

class A {
    public:
        A(int n);
    private:
        int a;
        int &b;
        const int c;
};

// A::A(int n) {
//     a = n;
//     b = n;
//     c = n;
// }

A::A(int n) : a(n), b(n), c(n) {}

int main() {
    return 0;
}