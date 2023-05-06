#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    unique_ptr<string> p1(new string("Hello"));

    //unique_ptr<string> p2(p1); // error: copy is not allowed

    /*
    unique_ptr<string> p3;
    p3 = p1; // error: assignment is not allowed
    */

    unique_ptr<string> p4(p1.get());
    /*
    注意：不是通过拷贝或复制产生关系的两个unique_ptr可以指向同一块内存空间，编译、执行都不会报错
    但是当其中一个unique_ptr被销毁时，另一个unique_ptr就会成为悬空指针，这样就会导致程序崩溃
    所以还是不推荐这种用法
    */

    return 0;
}