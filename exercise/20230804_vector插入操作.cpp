#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> svec;

    // vector��֧��push_front()�������Բ��뵽begin()֮ǰ
    svec.insert(svec.begin(), "Hello");
    // ��3��Ԫ�ز��뵽svec��ĩβ����������Ԫ�ض���ʼ��Ϊ string "Anna"
    svec.insert(svec.end(), 3, "Anna");
    svec.insert(svec.begin(), {"wuyan", "WUYAN"});
    svec.insert(svec.begin(), svec.begin(), svec.end());
    // svec.insert(svec.end(), svec.begin(), svec.end()); //Ϊʲô������䲻�����ã�����
    
    for (const auto &s : svec)
        cout << s << " ";
    cout << endl;

    vector<int> ivec = {1, 2, 3, 4, 5};

    // ivec.insert(ivec.end(), ivec.begin(), ivec.end());
    // ivec.insert(ivec.begin(), ivec.begin(), ivec.end());
    // ivec.emplace(ivec.end(), 10);

    // ����ͨ���������ļӼ���������ָ��λ��
    // ������Ҫ�������ĵ�����Ԫ��ǰ�����һ��Ԫ��10
    ivec.insert(ivec.begin() + 2, 10);

    for (const auto &i : ivec)
        cout << i << " "; 
    cout << endl;

    return 0;
}