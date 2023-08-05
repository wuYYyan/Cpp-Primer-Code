/* 总结const和指针的类型转换公式：
const与几级指针的结合只看其右边有几个*，如果右边没有*，也就不参与修饰类型
注意：const与一级指针的结合，可以多const，但不能少const
int*         <==   const int*   错误
const int*   <==   int*         正确

int**        <==   int* const * 错误
int* const * <==   int**        正确

注意：const与二级指针的结合，左右都不能多或少const，否则都是错误的
int**        <==   const int**  错误
const int**  <==   int**        错误
*/
#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int *p = &a;
    const int **q = &p; //报错，q是指向整型常量的指针的指针，表示其二级指向的内容不可被修改，其本身和其一级指向的内容都是可以被修改的
    /* 在编译器看来是把const常量(二级指针二级指向的内容)的地址泄漏给了非const指针(二级指针一级指向的内容)
        const int * *q = &p;  *q <==> p;
        const int b = 20;  *q = &b;
        解决方法一：const int* p = &a; //将p变为const指针
        解决方法二：const int* const * q = &p; //禁止对*q赋值，也就禁止了泄漏通道
    */

    int a = 10;
    const int *p = &a; // const int*  <==  int*。正确
    int *q = p;        // int*  <==  const int*，错误

    int a = 10;
    int * const p = &a; // int*  <==  int*，正确
    int *q = p;        // int*  <==  int*，正确
    // const如果右边没有指针*的话，const是不参与修饰类型的

    int a = 10;
    int * const p = &a; // int*  <==  int*，正确
    int * const q = p;  // int*  <==  int*，正确
    // const如果右边没有指针*的话，const是不参与修饰类型的

    int a = 10;
    int * const p = &a; // int*  <==  int*，正确
    const int *q = p;  // const int*  <==  int*，正确

    int a = 10;
    int *p = &a;        // int*  <==  int*，正确
    const int **q = &p; // const int**  <==  int**，错误
    // const与二级指针的结合，多或少const都是错误的

    int a = 10;
    int *p = &a;         // int*  <==  int*，正确
    int * const *q = &p; // int* const *  <==  int**，等价于 const*  <==  *，正确

    int a = 10;
    int *p = &a;         // int*  <==  int*，正确
    int ** const q = &p; // int** <==  int**，正确
    // const如果右边没有指针*的话，const是不参与修饰类型的

    int a = 10;
    int * const p = &a; // int*  <==  int*，正确
    int **q = &p;       // int**  <==  int* const *，等价于 *  <==  const *，错误

    int a = 10;
    const int *p = &a;   // const int*  <==  int*，正确
    int * const *q = &p; // int* const *  <==  const int**，错误
    // const与一级指针结合，可以多const，转化为 int*  <==  const int*，但不能少const，所以是错误的

    return 0;
}
