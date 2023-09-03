#include <stdio.h>

#define N 20
// 预处理命令后面不要加分号

struct std
{
    char name[N];
    int score;
};

int main()
{
    struct std stu1[3] = {{"Tom", 80}, {"Jerry", 90}, {"Micheal", 100}};
    std stu2[3] = {{"Tom", 80}, {"Jerry", 90}, {"Micheal", 100}};
    // 对于cpp语言，定义自定义类型的对象或存放对象的数组时，可以省略struct关键字
    // 当然为了兼容C语言，也可以保留struct关键字

    return 0;
}