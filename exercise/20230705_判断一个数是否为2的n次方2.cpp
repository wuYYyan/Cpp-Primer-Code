#include <stdio.h>
// ���ü�����ж����Ķ����Ʊ�ʾ���ص㣬���һ������2���ݴη�����ô���Ĳ���Ķ����Ʊ�ʾ��һ��ֻ��һ��1
// n&(n-1) �ͻ���n��2���Ʋ����е�1��ʧ����ô n&(n-1) == 0

// ʹ��judge�����ж�num�Ƿ�Ϊ2���ݴη�
int judge(int n)
{
	if (n <= 0)
		return 0;
	if ((n & (n - 1)) == 0) // ����2��n���ݵĶ����Ʊ����ص�
		return 1;
	else
		return 0;
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	int ret = judge(num);
    
	if (ret == 1)
	{
		printf("%d ��2���ݴη�\n", num);
	}
	else
	{
		printf("%d ����2���ݴη�\n", num);
	}

	return 0;
}
