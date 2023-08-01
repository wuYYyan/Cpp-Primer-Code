#include <iostream>

using namespace std;

int main()
{
    int* q1 = nullptr;
    int* const q2 = nullptr;
    cout << typeid(q1).name() << endl;
    cout << typeid(q2).name() << endl;
    // const如果右边没有指针*的话，const是不参与修饰类型的

    int a = 10;
    int* p1 = &a;
    const int* p2 = &a;
    int* const p3 = &a; //注意p3的类型是int*，而不是int* const
    int *p4 = p3; //合法，因为p3的类型是int*，顶层const不参与修饰类型

    return 0;
}