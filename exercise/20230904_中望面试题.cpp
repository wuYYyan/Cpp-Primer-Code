// 输入一个正整数数组和一个正整数target，求和为target的连续子数组的个数
// 解法一：前缀和 + 左右双指针
#include <iostream>
#include <vector>

using namespace std;

vector<int> sum;

int main()
{
    vector<int> nums;

    int target;
    cin >> target;

    while (cin.get() != '\n')
        continue; // 跳过换行符(回车符)
    cout << target;

    int n;
    while (cin >> n) // 按下q表示输入结束
        nums.push_back(n);

    // 检查输入是否正确
    // for (int i = 0; i < nums.size(); i ++)
    //     cout << nums[i] << " ";
    
    int len = nums.size();
    sum.resize(len + 1);
    for (int i = 1; i <= len; i ++)
        sum[i] = sum[i - 1] + nums[i - 1]; // 表示在原数组中前n个数的和

    // 检查前缀和是否处理正确
    // for (int i = 1; i < len; i ++)
    //     cout << sum[i] << " ";
    
    // 注意题目说的是正整数数组，只有这样才能使用双指针的做法
    int res = 0;
    for (int i = 1, j = len; i <= j; j --) {
        while (i <= j && sum[j] - sum[i - 1] < target)
            i ++;
        if (i <= j && sum[j] - sum[i - 1] == target)
            res ++;
    }
    cout << res << endl;

    return 0;
}