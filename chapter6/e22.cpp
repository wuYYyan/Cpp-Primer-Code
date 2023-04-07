#include <iostream>

using std::cout; using std:: endl;

void swap1(int *pt1, int *pt2);
void swap2(int *pt1, int *pt2);
void swap3(int *&r1, int *&r2);

int main()
{
    int a = 1, b = 2;
    int *pt1 = &a, *pt2 = &b;

    swap1(pt1, pt2);
    cout << "After swap1(): " << endl;
    cout << "*pt1 = " << *pt1 << ", *pt2 = " << *pt2 << endl;
    cout << "a = " << a << ", b = " << b << endl;

    cout << "--------------" << endl;

    swap2(pt1, pt2);
    cout << "After swap2(): " << endl;
    cout << "*pt1 = " << *pt1 << ", *pt2 = " << *pt2 << endl;
    cout << "a = " << a << ", b = " << b << endl;

    cout << "--------------" << endl;

    swap3(pt1, pt2);
    cout << "After swap3(): " << endl;
    cout << "*pt1 = " << *pt1 << ", *pt2 = " << *pt2 << endl;
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}

//交换两个指针的指向，因为是传值参数，所以并未改变实参
void swap1(int *pt1, int *pt2)
{
    int *temp = pt1;
    pt1 = pt2;
    pt2 = temp;
}

//交换两个指针所指向的内容
void swap2(int *pt1, int *pt2)
{
    int temp = *pt1;
    *pt1 = *pt2;
    *pt2 = temp;
}

/*
调用格式：swap2(a, b);
void swap2(int &v1, int &v2)
{
    int temp = v1;
    v1 = v2;
    v2 = temp;
}
*/

//交换两个指针的指向，但是因为是传引用参数，所以也改变了实参
void swap3(int *&r1, int *&r2)
{
    int *temp = r1;
    r1 = r2;
    r2 = temp;
}