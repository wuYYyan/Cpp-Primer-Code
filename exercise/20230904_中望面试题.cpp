// ����һ�������������һ��������target�����Ϊtarget������������ĸ���
// �ⷨһ��ǰ׺�� + ����˫ָ��
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
        continue; // �������з�(�س���)
    cout << target;

    int n;
    while (cin >> n) // ����q��ʾ�������
        nums.push_back(n);

    // ��������Ƿ���ȷ
    // for (int i = 0; i < nums.size(); i ++)
    //     cout << nums[i] << " ";
    
    int len = nums.size();
    sum.resize(len + 1);
    for (int i = 1; i <= len; i ++)
        sum[i] = sum[i - 1] + nums[i - 1]; // ��ʾ��ԭ������ǰn�����ĺ�

    // ���ǰ׺���Ƿ�����ȷ
    // for (int i = 1; i < len; i ++)
    //     cout << sum[i] << " ";
    
    // ע����Ŀ˵�������������飬ֻ����������ʹ��˫ָ�������
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