#include <iostream>
#include <iomanip>

using namespace std;

/*
    std::setw(n)  n ��ʾ��ȣ������ֱ�ʾ��ֻ�Խ����ں���������������
    ����������ŵ�����ֶγ���С�� n ��ʱ���ڸ��ֶ�ǰ���ÿո��룬������ֶγ��ȴ��� n ʱ��ȫ���������
*/

int main()
{
    // ��ͷ���ÿ��Ϊ 4������� runoob �ַ����ȴ��� 4�����Բ�������
    cout << setw(4) << "runoob" << endl;
    
    // �м�λ�����ÿ��Ϊ 4������� runoob �ַ����ȴ��� 4�����Բ�������
    cout << "runoob" << setw(4) << "runoob" << endl;
    
    // ��ͷ���ÿ��Ϊ 14������ runoob �ַ���Ϊ6��ǰ�油�� 8 ���ո� 
    cout << setw(14) << "runoob" << endl;
    
    // �м�λ�����ÿ��Ϊ 14 ������ runoob �ַ���Ϊ6��ǰ�油�� 8 ���ո� 
    cout << "runoob" << setw(14) << "runoob" << endl;

    return 0;
}