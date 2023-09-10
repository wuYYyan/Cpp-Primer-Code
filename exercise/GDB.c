// GDB调试模板
// 本文件夹内已经配置好单文件gdb调试，需要注意的是文件名必须是英文，否则会报错
// 按下F5进入调试模式，而不要直接通过侧边栏进入调试模式
// 通过调试按钮最右边的方框退出调试模式，而不要关闭输入框
#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    n = 1000 * n;
    printf("Love you %d times!\n", n);
    return 0;
}
