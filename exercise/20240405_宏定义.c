#include <stdio.h>

#define PRINT_NUMS(...) printf(__VA_ARGS__)
// __VA_ARGS__ 全称为：variable argument lists，是C语言中的一个预处理器宏
// 它用于表示可变参数列表，可以接受任意数量的参数

#define PRINTF_STRING ({ printf("Hello World!\n"); printf("===========\n"); printf("Hello World!\n");})
// 复合语句是由括号 {} 包围的一组语句，它可以在需要一个语句的地方使用，就像一个单独的语句一样

int main() {
    PRINT_NUMS("%d %d %d %d\n", 1, 2, 3, 4);

    PRINTF_STRING;

    return 0;
}