#include <iostream>

using namespace std;

/*
    1) �Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�����������
    2) ��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԣ�����������Ԫ��Ӧ�û���������
    3) ������е�Ԫ���ظ����ϵĲ��裬�������һ��
    4) �ظ�����1~3��ֱ���������
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