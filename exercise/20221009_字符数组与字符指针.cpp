//日期：20221009
//内容：字符数组/字符串的下标索引方法、输出地址
#include <iostream>
#include <string>

using namespace std;

int main()
{
    char flower[10] = "rose"; //用引号括起的字符串常量初始化字符串数组，会自动在末尾补结束符
    string str = "flower";
    int num[10] = {1, 2, 3}; //部分初始化时，未被赋值的元素为零

    //字符数组名也指向字符数组中的第一个字符，但cout智能对象会一直输出直到遇到空字符为止
    cout << flower << ' ' << flower[2] << endl;
    cout << str << ' ' << str[2] << endl; 
    
    //要输出字符数组/字符串的地址，必须再加一个取地址运算符；而整型数组直接写数组名就可以
    cout << &flower << ' ' << num <<  ' ' << &str << endl;  

    return 0;
}