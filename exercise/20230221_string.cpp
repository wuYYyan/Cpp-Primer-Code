#include <iostream>
#include <string>

using namespace std;

int main()
{
    char ch;
    string s1 = "hello";
    string s2 = "world";
    string s3;

    //像数组一样使用下标随机访问
    ch = s1[0];
    cout << ch << endl;

    int len = s1.size();
    cout << "s1的长度为: " << len << endl;
    
    //算法题常用技巧：字符转化为数字
    for (int i = 0; i < len; i ++)
        cout << s1[i] - 'a' << ' ';
    cout << endl;

    s3 = s1 + s2; //两个字符串连接
    cout << s3 << endl;
    s3 += "oo";   //与新的字符串连接
    cout << s3 << endl;
    s3 += '!';    //与新的字符连接
    cout << s3 << endl;
    //s3 += 666;  //会产生警告然后乱码
    s3 += to_string(666); //将int类型转换为string类型才能相加
    cout << s3 << endl;

    cout << s1.substr(1, 2) << endl; // 从第二个元素(下标从0开始)开始返回长度为 2 的子串
    //若要求返回的长度大于剩余字符的全长，则输出完当前字符串为止；若省略长度参数，则也是从指定位置开始返回完当前字符串为止

    printf("%s\n", s1.c_str()); //库函数 c_str 返回字符数组的头指针

    s1.clear(); //清空元素
    if (s1.empty()) //判断是否为空
        cout << "s1为空" << endl;

    //将字符串中的数组转换为int类型
    cout << 1 + stoi("666") << endl; //输出667
    cout << 1 + "666" << endl; //输出66.好奇怪！

    return 0;
}