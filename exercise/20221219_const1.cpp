//日期：20221219 
//内容：指针常量
#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    int m = 100;
    int *const pt = &n; //本质上是一个常量，只不过这个常量的类型是指针

    cout << "1):n = " << n << endl;

    *pt = 20; //允许通过指针修改所指向对象的值
    cout << "2):n = " << n << endl;

    //pt = &m; //不允许修改指针指向其他内存位置
    cout << "*pt = " << *pt << endl;

    return 0;
}