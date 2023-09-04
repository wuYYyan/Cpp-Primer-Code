#include <iostream>

using namespace std;

/*
    1) 比较相邻的元素。如果第一个比第二个大，就交换它们两个
    2) 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数
    3) 针对所有的元素重复以上的步骤，除了最后一个
    4) 重复步骤1~3，直到排序完成
*/

void bubble_sort(int arr[], int len)
{
    int i, j, temp;

    for (i = 0; i < len - 1; i ++)
    {
        for (j = 0; j < len - 1 - i; j ++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }

        // for (int k = 0; k < len; k++)
        // {
        //     cout << arr[k] << " ";
        // }
        // cout << endl;
    }
}

int main()
{
    int arr[10] = {10, 31, 25, 17, 9, 28, 4, 61, 18, 1};

    bubble_sort(arr, 10);

    return 0;
}