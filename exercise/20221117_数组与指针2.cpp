//日期：20221117
//内容：数组与指针的下标索引方式
#include <iostream>

using namespace std;

int main()
{
    int n[3] = {1, 2, 3};
    int *pn = n; //变量的类型是int *，而不是int，所以在大部分情况下可以认为pn = n

    cout << "Part1: --------" << endl; //该部分均输出数组n中第二个元素的内容
    cout << n[1] << endl;
    cout << pn[1] << endl;
    cout << *(n + 1) << endl;
    cout << *(pn + 1) << endl;

    cout << "Part2: --------" << endl; //该部分均输出数组n中第二个元素的地址
    cout << &n[1] << endl;
    cout << &pn[1] << endl;
    cout << (n + 1) << endl;
    cout << (pn + 1) << endl;

    cout << "Part3: --------" << endl;
    cout << n << endl; //输出的是数组n中第一个元素的地址，与&n[1]相同
    cout << n + 1 << endl;
    cout << &n << endl; //与25行输出的字面值相同，但代表的意义不同，本行代表的是整个数组的地址
    cout << &n + 1 << endl; //输出下一个十二字节的起始位置
    cout << pn << endl;
    cout << pn + 1 << endl;
    cout << &pn << endl; //输出的将是这个指针本身的地址
    cout << &pn + 1 << endl; //输出结果说明该指针占八个字节
    cout << sizeof(pn) << endl; //验证了上面的结论

    cout << "Part4: --------" << endl; //该部分均输出数组n中第一个元素的内容
    cout << *n << endl;
    cout << *pn << endl;
    cout << **&n << endl;
    cout << **&pn << endl;

    return 0;
}