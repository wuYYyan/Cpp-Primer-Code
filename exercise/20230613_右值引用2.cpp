#include <iostream>

using namespace std;

class Example
{
    public:
        Example() { cout << "example constructor" << endl; }
        Example(const Example &ex) 
        { 
            cout << "Copy constructor for Example" << endl; 
        }
        Example(Example &&ex)
        {
            cout << "Move constructor for Example" << endl;
        }
        ~Example() { cout << "destructor" << endl; }
        Example operator+(Example &other)
        {
            cout << "operator +" << endl;
            return Example(); //默认构造函数，返回右值时不会调用拷贝构造函数
        }
        Example test() //返回类型为非引用类型的函数产生右值，右值向左值赋值完毕之后会调用析构函数
        {
            cout << "test function" << endl;
            return Example(); //默认构造函数，返回右值时不会调用拷贝构造函数
        }
};

class Another
{
    public:
        // Another(const Example &ex) {  } //对成员变量example调用默认构造函数
        
        Another(const Example &ex) : example(ex) 
        { 
            cout << "Copy constructor for Another" << endl;
        }
        Another(Example &&ex) : example(std::move(ex)) 
        { 
            cout << "Move constructor for Another" << endl;
        } 
        // 对成员变量example调用拷贝构造函数，在完成初始化之后，右值将消亡，因此会调用析构函数
    private:
        Example example; //注意本类的对象析构时也会调用成员变量类对象的析构函数
};


int main()
{
    Example ex; //默认构造函数
    Another at(ex + ex); //加法运算符重载函数
    // 类Another的构造函数必须是const类型，因为算术表达式是右值，const的左值引用才可以绑定到右值

    // ex = ex + ex;
    // 在给左值赋值完毕之后，调用加法运算符重载函数产生的临时右值也会消亡，因此也会调用析构函数

    // Example ex1 = ex.test();
    // Example ex2 = ex; //拷贝构造函数

    return 0;
}