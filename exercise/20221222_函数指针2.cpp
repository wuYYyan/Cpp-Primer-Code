//日期：20221222
//内容：函数指针、函数指针数组、通过函数指针调用函数的方法
#include <iostream>

using namespace std;

const double *f1(const double ar[], int n);
const double *f2(const double *ar, int n);
const double *f3(const double [], int);
const double *f4(const double *, int n);
/*
在函数原型中，参数列表const double ar[]与const double *ar的含义完全相同
而在函数原型中，可以省略形参名，因此const double ar[]与const double []相同、const double *ar与const double *相同
综上所述，上面四个函数的类型(返回类型与特征标)完全相同，因此main函数中在定义函数指针时都使用统一的格式
*/

int main()
{
    double arr[4] = {1112.3, 1542.6, 2227.9, 2248.5};

    //定义四个函数指针，在C++11之后，可以使用自动类型推断：auto p1 = f1;
    const double *(*p1)(const double [], int) = f1;
    const double *(*p2)(const double [], int) = f2;
    const double *(*p3)(const double [], int) = f3;
    const double *(*p4)(const double [], int) = f4;

    //通过函数指针调用函数的两种方式：指针名(形参)或(*指针名)(形参)
    cout << "Using pointers to function: " << endl;
    cout << "Address " << "  " << "Value" << endl;
    cout << p1(arr, 4) << ": " << *p1(arr, 4) << endl;
    cout << (*p2)(arr, 4) << ": " << *(*p2)(arr, 4) << endl;
    cout << p3(arr, 4) << ": " << *p3(arr, 4) << endl;
    cout << (*p4)(arr, 4) << ": " << *(*p4)(arr, 4) << endl;

    //自动类型推断只能用于单值初始化，而不能用于列表初始化

    //定义函数指针数组，并通过数组下标索引的方式调用函数，这里不能使用自动类型推断
    const double *(*pa[4])(const double *, int) = {f1, f2, f3, f4};
    cout << "\nUsing an array of pointers to function: " << endl;
    cout << "Address " << "  " << "Value" << endl;
    for (int i = 0; i < 4; i ++)
        //cout << pa[i](arr, 4) << ": " << *pa[i](arr, 4) << endl;
        cout << (*pa[i])(arr, 4) << ": " << *(*pa[i])(arr, 4) << endl;

    //定义指向函数指针的指针，并通过第一次取指针内容第二次数组下标索引的方式调用函数，这里可以使用自动类型推断
    const double *(**pb)(const double *, int) = pa;
    cout << "\nUsing a pointer to an array of function pointers: " << endl;
    cout << "Address " << "  " << "Value" << endl;
    for (int i = 0; i < 4; i ++)
        //cout << pb[i](arr, 4) << ": " << *pb[i](arr, 4) << endl;
        cout << (*pb[i])(arr, 4) << ": " << *(*pb[i])(arr, 4) << endl;

    //定义指向函数指针数组的指针
    const double *(*(*pc)[4])(const double *, int)= &pa;
    cout << "\nUsing a pointer to an array of function pointers: " << endl;
    cout << "Address " << "  " << "Value" << endl;
    for (int i = 0; i < 4; i ++)
        //cout << (*pc)[i](arr, 4) << ": " << *(*pc)[i](arr, 4) << endl;
        cout << (*(*pc)[i])(arr, 4) << ": " << *(*(*pc)[i])(arr, 4) << endl;

    return 0;
}

//在函数原型中可以省略形参名，但在函数定义中不可省略
const double *f1(const double ar[], int n)
{
    return ar;
}

const double *f2(const double *ar, int n)
{
    return ar + 1;
}

const double *f3(const double ar[], int)
{
    return ar + 2;
}

const double *f4(const double *ar, int n)
{
    return ar + 3;
}