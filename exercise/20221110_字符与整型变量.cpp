//日期：20221009
//内容：字符与整型变量之间的相互转换
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word1, word2;
    char word3, word4;
    int num1, num2;

    cin >> word1 >> word2; //可以把数字看做是字符串
    cin >> word3 >> word4; //可以把十以内的数字看做是单个字符
    cin >> num1 >> num2; //但不能把字符转换为数字

    cout << "Part1: --------" << endl;
    cout << word1 << ' ' << word2 << endl;
    cout << word3 << ' ' << word4 << endl;
    cout << num1 << ' ' << num2 << endl;

    cout << "Part2: --------" << endl;
    //cout << (int)word1 << ' ' << (int)word2 << endl; //报错的原因是string类型不能强制转换为int类
    cout << (int)word3 << ' ' << (int)word4 << endl; //输出字符对应的ASCII码
    cout << (char)num1 << ' ' << (char)num2 << endl; //输出ASCII码对应的字符

    return 0;
}