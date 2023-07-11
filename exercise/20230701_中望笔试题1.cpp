#include <iostream>

using namespace std;

int main()
{
    int n[5][5] = {{1, 2, 3}, 
                    {4, 5, 6},
                    {7, 8, 9}};
    // 这种初始化方式没有提到的元素全部为零
    
    cout << n[0][0] << endl; //1
    cout << n[2][3] << endl; //0
    cout << n[4][4] << endl; //0

    cout << "-------------------" << endl;

    // 运算符优先级：圆括号 > 方括号 > 取内容运算符/取地址运算符

    // 这一组依次向后偏移20字节
    cout << n << endl;
    cout << n[0] << endl;
    cout << n + 1 << endl;
    cout << (n + 1)[0] << endl;
    cout << n + 2 << endl;
    cout << (n + 2)[0] << endl;

    cout << "-------------------" << endl;

    cout << &n[0] << endl;
    cout << &n[0][0] << endl;
    cout << &n[0] + 1 << endl;
    cout << &n[0][0] + 1 << endl;
    cout << &n[0] + 2 << endl;
    cout << &n[0][0] + 2 << endl;

    cout << "-------------------" << endl;

    // 注意&n[0]是指向第一个行数组的指针，因此&n[0] + 1要向后偏移20字节
    // &n[0] + 1作为指向行数组的指针(即指向指针的指针)，使用下标索引时
    // [0]表示当前指向的行数组的地址，[1]表示下一个行数组的地址
    // 对于指向数组的指针来说，使用下标索引相当于一次对指针取内容
    cout << (&n[0] + 1)[0] << endl;
    cout << *((&n[0] + 1)[0]) << endl;
    cout << *(&n[0] + 1)[0] << endl;

    cout << (&n[0] + 1)[1] << endl;
    cout << *((&n[0] + 1)[1]) << endl;
    cout << *(&n[0] + 1)[1] << endl;

    cout << "-------------------" << endl;

    cout << (&n[0] + 1) + 1 << endl;
    cout << *((&n[0] + 1) + 1) << endl;
    cout << **((&n[0] + 1) + 1) << endl;
    cout << &n[0] + 2 << endl;
    cout << *(&n[0] + 2) << endl;
    cout << **(&n[0] + 2) << endl;

    cout << "-------------------" << endl;

    cout << *(&n[0] + 1)[0] << endl;
    cout << *(&n[0] + 1)[1] << endl;
    cout << *(&n[1])[1] << endl;
    cout << *(&n)[1] << endl; //这里的&n是指向整个二维数组的指针，因此*(&n)[1]相比&n向后偏移100字节
    cout << *(&n[0])[1] << endl;
    cout << n[2][0] << endl;

    return 0;
}