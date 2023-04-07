#include <iostream>

using namespace std;

int main()
{
    char *ch = "abcd"; //Warning：ISO C++ forbids converting a string constant to 'char*'
    ch += 2; //经过指针加法之后，ch指向字符c
    cout << ch << endl; 
    //输出字符指针时，cout智能对象会从当前位置的内容开始输出，直至遇见空字符，因此最终输出cd
    cout << *ch << endl; 
    //因为使用了取内容运算符，所以只会输出指针ch当前指向的内容，不会一直向后读取，因此最终输出c
    cout << &ch << endl; 
    //虽然本来ch就是个指针，但是想要输出其所指向对象的地址，还得再加取地址运算符，因此输出字符c的地址，而不是指针本身的地址

    //上述的问题只对字符指针是特例，对于其他类型的指针按照指针的正常理解即可

    return 0;
}