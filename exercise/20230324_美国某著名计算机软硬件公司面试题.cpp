#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct 
{
    short a1;
    short a2;
    short a3;
}A;

struct
{
    long a1;
    short a2;
}B;


int main()
{
    char *ss1 = "0123456789";
    char ss2[] = "0123456789";
    char ss3[100] = "0123456789";
    int ss4[100];

    char q1[] = "abc";
    char q2[] = "a\n";
    char *q3 = "a\n";

    char *str1 = (char *)malloc(100);
    void *str2 = (void *)malloc(100);

    cout << sizeof(ss1) << " "; //输出8，因为计算的是指针本身所占内存空间的大小
    cout << sizeof(ss2) << " "; //输出11，因为计算的是数组所占内存空间的大小，注意包含末尾的结束符且数组名不会退化为指针
    cout << sizeof(ss3) << " "; //输出100，理由同上
    cout << sizeof(ss4) << " "; //输出400，理由同上

    cout << endl;

    cout << sizeof(q1) << " "; //输出4
    cout << sizeof(q2) << " "; //输出3
    cout << sizeof(q3) << " "; //输出8

    cout << endl;

    cout << sizeof(short) << " "; //输出2
    cout << sizeof(long) << " ";  //输出4
    cout << sizeof(A) << " "; //输出6
    cout << sizeof(B) << " "; //输出8(2*4=8)

    cout << endl;

    cout << sizeof(str1) << " "; //输出8
    cout << sizeof(str2) << " "; //输出8

    return 0;
}