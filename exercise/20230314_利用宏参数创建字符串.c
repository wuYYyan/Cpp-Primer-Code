#include <stdio.h>

#define SQUARE(x)   (printf(""#x" square is %d\n", (x) * (x)))
//#define SQUARE(x)   (printf("%d square is %d\n", x, (x) * (x)))
//第3行的语句更兼容表达式，对于单个数字两行语句效果相同

int main()
{
    SQUARE(4);

    SQUARE(2 + 4); 
    //使用第3行预处理将输出：2 + 4 square is 36
    //使用第4行预处理将输出：6 square is 36

    return 0;
}