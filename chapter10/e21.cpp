#include <iostream>

using namespace std;

int main()
{
    int i = 10;

    auto f = [i]() mutable -> bool{
        if(i > 0) 
        {
            i--;
            return false;
        } 
        else 
            return true;};
    
    for(int j = 0; i < 20; j ++)
    {
        if(f())
            break;
        cout << i << endl; //lambda表达式中的i是一个拷贝，而不是引用，所以输出为10
    }

    return 0;
}