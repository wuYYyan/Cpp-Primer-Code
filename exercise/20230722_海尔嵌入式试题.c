#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ss(char *s)
{
    return s + strlen(s) / 2;
}

int main()
{
    int a = 10, b = 20;
    if (!a < b)
        puts("Yes"); //Yes
    else
        puts("No");
    // �߼�����������ȼ����ڹ�ϵ�����

    char x[8] = {8, 7, 6, 5, 0, 0}, *s;
    s = x + 1; //��ʱָ��ڶ���Ԫ��
    printf("%d\n", s[2]); //�ӵڶ���Ԫ�ؿ�ʼ���ƫ��������λ�������ĸ�Ԫ�أ����5

    printf("a = %d\n", 25 / 3 % 3); //2

    char i = '1', j = '2';
    printf("%c\n", j ++); //2
    printf("%d\n", j - i); //2

    unsigned int c;
    printf("%d\n", c % 2 + (c + 1) % 2); //1

    int k;
    for (k = 0; k < 10; i ++)
        if (k <= 5)
            break;
    printf("%d\n", k); //0

    char *p, *q = "abcdefgh";
    p = ss(q);
    printf("%s\n", q); //abcdefgh
    printf("%s\n", p); //efgh

    return 0;
}