#include <iostream>

using namespace std;

class Example
{
    public:
        Example() { cout << "example constructor" << endl; }
        Example(const Example *ex) { cout << "copy constructor" << endl; }
        ~Example() { cout << "destructor" << endl; }
        Example operator+(Example &other)
        {
            cout << "operator +" << endl;
            return Example();
        }
};

class Another
{
    public:
        Another(const Example &ex) : example(ex) {  }
    private:
        Example example; 
};


int main()
{
    Example ex;
    Another at(ex + ex); 
    // 类Another的构造函数必须是const类型，因为算术表达式是右值，const的左值引用才可以绑定到右值

    return 0;
}