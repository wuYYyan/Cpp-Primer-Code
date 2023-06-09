#include <iostream>
#include <vector>

//相关知识点在C++ Primer P139 4.9小节 sizeof运算符

using namespace std;

void func(char str[], int n);

int main()
{
    char q[] = "WUYAN";
    char *qt = q;
    int x = 1;
    double *p;
    vector<int> vi(10, 1);

    cout << sizeof(q) << endl; //输出6，因为计算的是所占用内存空间的大小(此时数组名不会退化为指针)，并且末尾还有一个结束符
    cout << sizeof(qt) << endl; //输出8，因为计算的是指针本身所占用的内存大小
    cout << sizeof(*qt) << endl; //输出1，因为计算的是指针所指向的对象(字符串首字符)所占用的内存大小

    func(q, sizeof(q));

    cout << "1) x = " << x << endl;
    cout << sizeof(x++) << endl;
    cout << "2) x = " << x << endl; //sizeof运算符并不实际计算其运算对象的值

    cout << sizeof(p) << endl; //输出8，其中的指针无需有效

    for(auto i = vi.begin(); i != vi.end(); i ++)
        cout << *i << ' ';
    cout << endl << sizeof(vi) << endl; //输出24，只返回该类型固定部分(三个指针)的大小，不会计算对象中的元素占用了多少空间

    return 0;
}

//会有警告，提示内容为str会转化为指针
void func(char str[], int n)
{
    cout << "Hello World" << endl;
    cout << sizeof(str) << endl; //输出8，因为当数组作为参数传递时自动退化为指针
    return;
}