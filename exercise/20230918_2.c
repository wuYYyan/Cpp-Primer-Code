#include <stdio.h>

const int N = 100;

int main()
{
    char str[N];
    // printf("%s", str);
    scanf("%s", str); // 读取输入的时候末尾不要加换行符，因为输入本身要以换行符来结束

    char *p;
    int len = 0;
    for (p = str; *p != '\0'; p = p + 1)
        len ++;
    printf("输入字符串的长度为：%d\n", len);

    // for (p = p - 1; p != str; p = p - 1)
    //     printf("%c", *p);
    // printf("%c", str[0]);
    for (int i = 0; i < len; i ++) {
        p = p - 1;
        printf("%c", *p);
    }
        
    return 0;
}