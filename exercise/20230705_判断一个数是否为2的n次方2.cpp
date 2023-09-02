#include <stdio.h>
// 利用计算机中对数的二进制表示的特点，如果一个数是2的幂次方，那么它的补码的二进制表示中一定只有一个1
// n&(n-1) 就会让n的2进制补码中的1消失，那么 n&(n-1) == 0

// 使用judge函数判断num是否为2的幂次方
int judge(int n)
{
	if (n <= 0)
		return 0;
	if ((n & (n - 1)) == 0) // 根据2的n次幂的二进制表达的特点
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
		printf("%d 是2的幂次方\n", num);
	}
	else
	{
		printf("%d 不是2的幂次方\n", num);
	}

	return 0;
}
