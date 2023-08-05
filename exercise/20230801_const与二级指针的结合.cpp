/* �ܽ�const��ָ�������ת����ʽ��
const�뼸��ָ��Ľ��ֻ�����ұ��м���*������ұ�û��*��Ҳ�Ͳ�������������
ע�⣺const��һ��ָ��Ľ�ϣ����Զ�const����������const
int*         <==   const int*   ����
const int*   <==   int*         ��ȷ

int**        <==   int* const * ����
int* const * <==   int**        ��ȷ

ע�⣺const�����ָ��Ľ�ϣ����Ҷ����ܶ����const�������Ǵ����
int**        <==   const int**  ����
const int**  <==   int**        ����
*/
#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int *p = &a;
    const int **q = &p; //����q��ָ�����ͳ�����ָ���ָ�룬��ʾ�����ָ������ݲ��ɱ��޸ģ��䱾�����һ��ָ������ݶ��ǿ��Ա��޸ĵ�
    /* �ڱ����������ǰ�const����(����ָ�����ָ�������)�ĵ�ַй©���˷�constָ��(����ָ��һ��ָ�������)
        const int * *q = &p;  *q <==> p;
        const int b = 20;  *q = &b;
        �������һ��const int* p = &a; //��p��Ϊconstָ��
        �����������const int* const * q = &p; //��ֹ��*q��ֵ��Ҳ�ͽ�ֹ��й©ͨ��
    */

    int a = 10;
    const int *p = &a; // const int*  <==  int*����ȷ
    int *q = p;        // int*  <==  const int*������

    int a = 10;
    int * const p = &a; // int*  <==  int*����ȷ
    int *q = p;        // int*  <==  int*����ȷ
    // const����ұ�û��ָ��*�Ļ���const�ǲ������������͵�

    int a = 10;
    int * const p = &a; // int*  <==  int*����ȷ
    int * const q = p;  // int*  <==  int*����ȷ
    // const����ұ�û��ָ��*�Ļ���const�ǲ������������͵�

    int a = 10;
    int * const p = &a; // int*  <==  int*����ȷ
    const int *q = p;  // const int*  <==  int*����ȷ

    int a = 10;
    int *p = &a;        // int*  <==  int*����ȷ
    const int **q = &p; // const int**  <==  int**������
    // const�����ָ��Ľ�ϣ������const���Ǵ����

    int a = 10;
    int *p = &a;         // int*  <==  int*����ȷ
    int * const *q = &p; // int* const *  <==  int**���ȼ��� const*  <==  *����ȷ

    int a = 10;
    int *p = &a;         // int*  <==  int*����ȷ
    int ** const q = &p; // int** <==  int**����ȷ
    // const����ұ�û��ָ��*�Ļ���const�ǲ������������͵�

    int a = 10;
    int * const p = &a; // int*  <==  int*����ȷ
    int **q = &p;       // int**  <==  int* const *���ȼ��� *  <==  const *������

    int a = 10;
    const int *p = &a;   // const int*  <==  int*����ȷ
    int * const *q = &p; // int* const *  <==  const int**������
    // const��һ��ָ���ϣ����Զ�const��ת��Ϊ int*  <==  const int*����������const�������Ǵ����

    return 0;
}
