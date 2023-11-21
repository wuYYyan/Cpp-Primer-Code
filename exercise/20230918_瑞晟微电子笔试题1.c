// 力扣原题：https://leetcode.cn/submissions/detail/483489175/
#include <stdio.h>

int main()
{
    int a, b, c;
    int res = 0;
    scanf("%d%d%d", &a, &b, &c);
    while (a | b != c) {
        int i, j, k;
        i = a & 1, j = b & 1, k = c & 1;
        // 分别取出a, b, c的最后一位
        if (k == 1) {
            if (i == 0 && j == 0)
                res ++;
        } else {
            if (i == 1 && j == 1)
                res += 2;
            else if (i == 1 || b == 1)
                res ++;
        }
        a = a >> 1, b = b >> 1, c = c >> 1; 
    }
    printf("res = %d", res);

    return 0;
}