//日期：20230102
//内容：题目来源：https://www.runoob.com/w3cnote/const-char.html
//参考：https://blog.csdn.net/u012601587/article/details/50462189

/*
const char *p="hello";       
foo(&p);   
假设有函数定义：foo(const char **pp)，则下面说法不正确的是 (B)
A.函数foo()不能改变p指向的字符串内容。
B.函数foo()不能使指针p指向malloc生成的地址。
C.函数foo()可以使p指向新的字符串常量。
D.函数foo()可以把p赋值为 NULL。
*/

#include <stdio.h>
#include <stdlib.h>

const char *p = "Hello"; //p是指向const char类型的指针，这意味着不能通过指针p修改其所指向对象的值
//但可以使指针p指向其他字符串常量或其他内存处

void foo(const char **pp) //foo是有一个形参为指向const char类型的指针的指针pp、但无返回值的函数
{
    //*pp = p，是指向const char类型的指针

    //选项A：
    //(*pp)[1] = 'x';

    //选项B：
    //*pp = (char *) malloc(11);
    //snprintf(*pp, 11, "hi google!");

    //选项C：
    //*pp = "Google";

    //选项D：
    //*pp = NULL;
}

int main()
{
    printf("Before foo:  %s\n",p);

    foo(&p);
    printf("After foo:  %s\n",p);

    //p[1] = 'x'; //本句与选项B配合使用：即使在foo中让p指向了由malloc生成的内存块，但是仍旧不能用 p[1]='x' 这样的语句修改其指向的内容
    //Gcc只是根据const的字面的意思对其作了限制，对于const char *p这样的指针，不管后来p实际指向malloc的内存或者常量的内存，均不能用 p[1]='x' 这样的语句修改其指向的内容
    //但是很奇怪，在foo里面，对p指向malloc的内存后，可以用snprintf之类的函数修改其内容，虽然会有警告但依旧可以实现修改目的

    return 0;
}