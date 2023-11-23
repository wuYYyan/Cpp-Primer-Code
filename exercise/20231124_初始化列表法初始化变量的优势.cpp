#include <iostream>

using namespace std;

int main() {
    int a = 1; // 赋值表示法
    int b(2); // 函数表示法
    int c {3}; // 初始化列表法
    cout << a << " " << b << " " << c << endl;

    int a1 = 1.5;
    int b1 = 2.4;
    int c1 {3.5}; // 对于缩窄转换会产生警告
    cout << a1 << " " << b1 << " " << c1 << endl;

    return 0;
}