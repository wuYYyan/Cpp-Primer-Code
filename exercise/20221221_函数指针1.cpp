//日期：20221221
//内容：函数指针、常量指针、运算符优先级
//数组->指针：存放指针的数组；指针->数组：指向数组的指针；指针->函数：函数指针；函数->指针：返回指针的函数。先出现的是主语，后出现的是定语
#include <iostream>

using namespace std;

char ch1 = 'w';
char ch2 = 'y';
char ch3 = 'L';
char *const pt1 = &ch1; //常量指针，意味着不能再更改指针指向其他变量，因此pt1是指向字符类型的常量指针
const char *pt2 = &ch2; //指向常量的指针，意味着不能通过指针修改所指向对象的值，但这不代表ch2是常量，但是从指针的角度来看ch2是常量
char const *pt3 = &ch3; //C++标准规定const关键字放在类型名或变量名之前都是等价的，因此pt3与pt2的含义相同

char *const *fun();

int main()
{
    char *const *(*next)();
    /*
    1):圆括号优先级最高，(*next) --> next是个指针
    2):圆括号优先级高于取内容运算符，(*next)() --> next是个函数指针
    3):char *const pt; --> pt是一个指向字符类型的常量指针
    4):char *const *(*next)() --> next是一个函数指针，它指向形参为空、
            返回值为指向字符类型的常量指针的指针的函数
    */

    next = fun;
    cout << **next() << endl;

    return 0;
}

char *const *fun()
{
    char *const *ppt1 = &pt1; //ppt1是指向字符类型的常量指针的指针
    //cout << **ppt1 << endl;
    return ppt1;
}

char const *(*(*const bar)[5])(int);
//(*const bar)[5] --> bar是指向拥有五个元素的数组的常量指针
//char const *pt --> pt是指向const char类型的指针 
//char const *(*a)(int) --> a是函数指针，它指向具有一个int类型的形参、返回值为指向const char类型的指针的函数
//因此bar是指向拥有五个元素的数组的常量指针，数组中的每个元素都是函数指针，指向具有一个int类型的形参、返回值为指向const char类型的指针的函数

//https://blog.csdn.net/struggle6688/article/details/71725244