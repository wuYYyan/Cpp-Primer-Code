#include <iostream>

using namespace std;

int main() {
    char ch = 'x';
    char &r1 = ch;
    cout << sizeof(char) << " " << sizeof(r1) << endl;

    // int x = 1;
    // int &r2 = x;
    // cout << sizeof(int) << " " << sizeof(r2) << endl;

    // C++语言中使用指针作为引用的内部实现，即引用所占用的内存空间与指针所占用的内存空间相同
    // 使用sizeof方法并不能查看引用所占用的内存空间，在计算时会替换到引用实际所绑定的对象上

    /*
    在Linux系统中编译此程序，生成可执行文件后，使用命令 size a.out 查看可执行文件的大小
    可以看到在添加一个引用变量前后，.data段所占用的内存空间增加八个字节
    即引用所占用的内存空间与引用所绑定的对象无关，而是与操作系统中指针所占用的内存空间一致 
    */

    return 0;
}