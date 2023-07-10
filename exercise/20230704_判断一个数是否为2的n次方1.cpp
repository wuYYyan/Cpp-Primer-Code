#include <stdio.h>
// 不断的算出2的幂次方的数来穷举，直到算出的数超出这个数本身结束循环
// 如果在穷举过程中等于给定的数，那么这个数就是2的幂次方，如果是超过了，那就不是

// 使用judge函数判断num是否为2的幂次方
int judge(int num)
{
	int ret = 1;
	while (ret <= num)
	{
		// 如果小于，则说明还没穷举完
		if (ret < num)
		{
			// 每次产生一个2的幂次方数
			ret *= 2;
		}
		else
		{
			// 是
			return 1;
		}
	}
	// 不是
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
