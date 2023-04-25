#include <stdio.h>

#define SIZE    22

int findSingleNumber(int *array, int size);

int main()
{
    //printf("%ld", sizeof(int)); //int类型占4个字节
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 1001, 1, 2, 3, 4, 5, 6, 7};

    printf("The number in array appears only once is: ");
    printf("%d\n", findSingleNumber(array, SIZE));

    return 0;
}

//使用数组作为参数时，因为数组名的本质是一个指针，所以还得传入数组的大小以确定读取的边界
//这种方法只能适用于在一个数组中，除了一个数字只出现一次之外，其他数字都出现了三次及以上(不能多也不能少)
//尤其是不适用于在一个数组中，除了一个数字只出现一次之外，其他数字都出现了两次
int findSingleNumber(int *array, int size)
{
    int bitSum[32] = {0}; //用来存储每一个二进制位上的数
    //bitSum[i]存储的是数组中所有数字的二进制表示中第i位的和(最右侧的为第0位)

    //将数组中的每一个数的每一位都加起来
    for(int i = 0; i < size; i ++)
    {
        for(int j = 0; j < 32; j ++)
        {
            bitSum[j] += (array[i] >> j) & 1; //区别按位与 & 和 逻辑与 &&
            //先按二进制位右移j位，再与1进行与运算，即取出了arr[i]的第j位，最后将结果加到bitSum数组中
        }
    }

    //将bitSum数组中的每一个数对3取余，得到的结果就是只出现一次的数的二进制表示
    //因为在数组中出现三次的数字的二进制位对3取余的结果都是0
    int result = 0;

    for(int i = 0; i < 32; i ++)
    {
        //result += (bitSum[31 - i] % 3) << (31 - i);
        result += (bitSum[i] % 3) << (i); //两种写法都可以
        //先对bitSum[i]对3取余，再左移(31-i)位，最后将结果加到result中
    }

    return result;
}