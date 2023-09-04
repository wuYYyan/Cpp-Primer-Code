#include <iostream>
#include <iomanip>

using namespace std;

/*
    std::setw(n)  n 表示宽度，用数字表示，只对紧接在后面的输出产生作用
    当后面紧跟着的输出字段长度小于 n 的时候，在该字段前面用空格补齐，当输出字段长度大于 n 时，全部整体输出
*/

int main()
{
    // 开头设置宽度为 4，后面的 runoob 字符长度大于 4，所以不起作用
    cout << setw(4) << "runoob" << endl;
    
    // 中间位置设置宽度为 4，后面的 runoob 字符长度大于 4，所以不起作用
    cout << "runoob" << setw(4) << "runoob" << endl;
    
    // 开头设置宽度为 14，后面 runoob 字符数为6，前面补充 8 个空格 
    cout << setw(14) << "runoob" << endl;
    
    // 中间位置设置宽度为 14 ，后面 runoob 字符数为6，前面补充 8 个空格 
    cout << "runoob" << setw(14) << "runoob" << endl;

    return 0;
}