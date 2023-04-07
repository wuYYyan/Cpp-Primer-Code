//日期：20221223
//内容：用字符串常量初始化字符指针、字符串常量在内存中的位置
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    char *pt1 = "AAA"; //在C中，这一句完全没问题；但是在C++中会发出警告：避免将字符串常量赋值给char *类型
    char pt2[4] = "BBB";

    printf("%s\n", pt1);
    printf("%s\n", pt2);

    cout << "---------" << endl;
    pt1[0] = 'C'; //字符串常量存放在只读区域中，要避免通过指针修改它们的值
    pt2[0] = 'C';

    //printf("%s\n", pt1);
    //printf("%s\n", pt2);
    cout << "---------" << endl;

    return 0;
}