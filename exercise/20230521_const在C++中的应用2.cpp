#include <iostream>

using namespace std;

int main()
{
    /* C��C++��const��������ʲô��
    1) const�ı��뷽ʽ��ͬ��C++�����г���const�������ֵĵط����������ĳ�ʼֵ�滻��
        ��C��const���������ǵ���һ����������������ָ���
    */

    //const int x; //��C++�У�const���ε�����Ϊ������һ��Ҫ��ʼ����������ڱ���׶α���

    int b = 10;
    const int a = b; //��һ����������ʼ��const��������˰�a����������
    printf("a = %d\n", a);

    int arr[a] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //����������Ϊ�����С
    printf("arr[0] = %d\n", arr[0]);

    // const int *p = &a; //a�ǳ�����p��ָ������ָ��(�ײ�const)
    int *p = (int*)&a; //ͨ��ǿ������ת������const int*ת����int*
    *p = 20;
    // ָ��p�������Ѿ��޸���a��ֵ
    printf("%p\n", &a);
    printf("%p\n", p);
    printf("a = %d\n", a); //20���ڱ���׶�û���������滻�����������a��ֵ�й�
    printf("*p = %d\n", *p); //20
    printf("*(&a) = %d\n", *(&a)); //20

    return 0;
}