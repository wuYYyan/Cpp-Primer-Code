/* �ܽ�const��ָ�������ת����ʽ��
ע�⣺const��һ��ָ��Ľ�ϣ����Զ�const����������const
int*         <==   const int*   ����
const int*   <==   int*         ��ȷ

int**        <==   int* const * ����
int* const * <==   int**        ��ȷ

ע�⣺const�����ָ��Ľ�ϣ����Ҷ����ܶ����const�������Ǵ����
int**        <==   const int**  ����
const int**  <==   int*         ����
*/
#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int *p = &a;
    const int **q = &p; //����q��ָ�����ͳ�����ָ���ָ�룬��ʾ�����ָ������ݲ��ɱ��޸ģ��䱾�����һ��ָ������ݶ��ǿ��Ա��޸ĵ�
    /* �ڱ����������ǰ�const�����ĵ�ַй©���˷�constָ��
        const int* *q = &p;  *q <==> p;
        const int b = 20;  *q = &b;
        �������һ��const int* p = &a; //��p��Ϊconstָ��
        �����������const int* const * q = &p; //��ֹ��*q��ֵ��Ҳ�ͽ�ֹ��й©ͨ��
    */

    return 0;
}
