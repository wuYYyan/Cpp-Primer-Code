#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *FormatString(const char *str);

int main()
{
    char *str = "aaabbbbccccc"; // 将给定字符串转换为a3b4c5
    puts(FormatString(str));

    return 0;
}

char *FormatString(const char *str)
{
    int n = strlen(str); //strlen计算字符串长度时不包括'\0'
    char *s = (char *)malloc(2 * n + 1); // 申请内存空间
    
    if(s != NULL)
    {
        int k = 0;
        for(int i = 0, j = 0; j < n; i = j)
        {
            int num = 0;
            while(str[j] == str[i])
            {
                num ++;
                j ++;
            }    
            s[k ++] = str[i];
            s[k ++] = num + '0';
        }
        s[k] = '\0';
    }

    return s;
}