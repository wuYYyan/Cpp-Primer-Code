#include <iostream>

using namespace std;

int func1(int x)
{
    int cnt = 0;
    while (x)
    {
        cnt ++;
        x = x & (x - 1);
    }
    return cnt;
}
/*
    x - 1: �����Ʊ���£�x - 1�����λ��1����0�������1�ұߵ�0����1����ߵ������ֲ���
    200��11001000��200 - 1 = 199��11000111 --> 11001000 & 11000111 =  11000000
*/

int func2(int x)
{
    int cnt = 0;
    while (x)
    {
        int k = x & 1;
        if (k == 1)
        {
            cnt ++;
        }
        x = x >> 1;
    }
    
    return cnt;
}

// �������ַ���������ʵ��ͳ��ĳ�������Ķ����Ʊ����1�ĸ���
// ���ǵ�һ�ַ������ã���Ϊ��һ�ַ�����ѭ��������1�ĸ��������ڶ��ַ�����ѭ�������Ƕ�����λ��
int main()
{
    int num;
    cin >> num;

    int cnt1 = func1(num);
    cout << num << "�Ķ����Ʊ����1�ĸ���Ϊ��" << cnt1 << endl;

    int cnt2 = func2(num);
    cout << num << "�Ķ����Ʊ����1�ĸ���Ϊ��" << cnt1 << endl;

    return 0;
}
