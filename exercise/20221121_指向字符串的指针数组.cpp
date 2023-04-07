//日期：20221121
//内容：存放指向字符串的指针的数组
#include <iostream>

using namespace std;

int main()
{
    const char * Snames[] = {"spring", "summer", "fall", "winter"}; //存放常量字符串指针的数组
    //方括号的优先级更高，因此Snames首先是一个数组，前面的定义是数组中变量的类型
    //运算符优先级：圆括号 -> 方括号 -> 取内容运算符

    cout << Snames[0] << endl;
    cout << Snames[3] << endl;

    return 0;
}