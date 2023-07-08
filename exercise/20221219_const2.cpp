//日期：20221219 
//内容：指向常量的指针
#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    int m = 100;
    const int *pt = &n; //指向const int类型变量的指针

    cout << "1):n = " << n << endl;

    // 不能通过指向常量的指针修改所指向对象的值，因此下面一行代码会报错
    // *pt = 20;
    n = 100; //但这并不意味这n是个常量
    cout << "2):n = " << n << endl;

    pt = &m; //但可以修改指针所指向的对象
    cout << "*pt = " << *pt << endl;
    cout <<  "m = " << m << endl;

    return 0;
}