#include <stdio.h>

#define SIZE    15

int findSingleNumber(int *array, int size);

int main()
{
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 1001};
    //int array[SIZE] = {1, 2, 3, 4, 5, 6, 1001, 1, 2, 3, 4, 5, 6, 1001, 1001};
    //int array[SIZE] = {2, 2, 3, 4, 5, 6, 1001, 2, 2, 3, 4, 5, 6, 1001, 1001};

    printf("The number in array appears only once is: ");
    printf("%d\n", findSingleNumber(array, SIZE));

    return 0;
}

//使用数组作为参数时，因为数组名的本质是一个指针，所以还得传入数组的大小以确定读取的边界
//这种方法只能适用于在一个数组中，除了一个数字只出现奇数次之外，其他数字都出现了偶数次
int findSingleNumber(int *array, int size)
{
    int result = array[0];

    for(int i = 1; i < size; i ++)
    {
        result ^= array[i]; //异或运算：相同为零，不同为一
        //printf("%d\n", result);
        //运用异或运算的性质是：数a两次异或同一个数b，结果等于数a本身，就好像数b没有参与运算一样
    }

    return result;
}