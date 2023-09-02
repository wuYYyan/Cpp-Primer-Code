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
    x - 1: 二进制表达下，x - 1的最低位的1会变成0，而这个1右边的0会变成1，左边的数保持不变
    200：11001000，200 - 1 = 199：11000111 --> 11001000 & 11000111 =  11000000
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

// 上述两种方法都可以实现统计某个整数的二进制表达下1的个数
// 但是第一种方法更好，因为第一种方法的循环次数是1的个数，而第二种方法的循环次数是二进制位数
int main()
{
    int num;
    cin >> num;

    int cnt1 = func1(num);
    cout << num << "的二进制表达中1的个数为：" << cnt1 << endl;

    int cnt2 = func2(num);
    cout << num << "的二进制表达中1的个数为：" << cnt1 << endl;

    return 0;
}
