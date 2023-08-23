// 已知有两个变量a = 10、b = 20，要求将两个变量的值进行交换
// 最终打印结果为：a = 20、b = 10
#include <iostream>

using namespace std;

int main()
{
    // 方法五：指针运算
    int *a = new int(10);
    int *b = new int(20); 

    cout << a << "`````";
    cout << b << "`````";

    if (a < b){
        a = (int*)(b - a); 
        cout << a << "`````";

        b = (int*)(b - (long(a) & 0x0000ffff));
        cout << b << "`````";
        
        a = (int*)(b + long(a));
        cout << a << "`````";
    } else {
        b = (int*)(a - b); 
        cout << b << "`````";

        a = (int*)(a - (long(b) & 0x0000ffff));
        cout << a << "`````";
        
        b = (int*)(a + long(b));
        cout << b << "`````";
    }

    return 0;
}