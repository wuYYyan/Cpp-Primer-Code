#include <iostream>
#include <vector>

using namespace std;

class A
{
    public:
        A()
        {
            cout << "class create" << endl;
        }
        A(const A &a)
        {
            cout << "class copy" << endl;
        }
        A &operator=(const A &a)
        {
            cout << "override operator= " << endl;
            return *this;
        }
        ~A() //析构函数，先执行函数体，再销毁成员
        {
            cout << "class destroy" << endl;
        }
};

void f1(A a)
{
    cout << "f1 without ref A" << endl;
}

void f2(A &a)
{
    cout << "f2 with ref A" << endl;
    //当指向一个对象的引用离开作用域时，不会调用析构函数
}

int main()
{
    A a; //默认构造函数

    f1(a); //拷贝构造函数 -> 析构函数
    f2(a); //不会调用拷贝构造函数，也不会调用析构函数
    // 当指向一个对象的引用或指针离开作用域时，不会调用析构函数

    A *pa = new A(a); //拷贝构造函数
    delete pa; //析构函数

    vector<A> vec(3); //这只会调用默认构造函数，不会调用拷贝构造函数
    cout << "Size = " << vec.size() << ", Capacity = " << vec.capacity() << endl;
    // 在对vector进行扩容的过程中，新的内存空间中的元素从旧内存空间中的元素拷贝构造而来，然后再调用析构函数将旧内存空间中的元素析构掉
    vec.push_back(a); //拷贝构造函数，或者是用【花括号列表】初始化一个数组中的元素才会调用拷贝构造函数
    cout << "Size = " << vec.size() << ", Capacity = " << vec.capacity() << endl;

    return 0; //对a调用析构函数，对vec中的元素调用析构函数
}