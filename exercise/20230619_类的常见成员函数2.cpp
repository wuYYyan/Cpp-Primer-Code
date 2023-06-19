#include <string>
#include <iostream>
#include <memory>
#include <algorithm>
#include <initializer_list>

using namespace std;

class StrVec
{
    private:
        string *elements;
        string *first_free;
        string *cap;
        allocator<string> alloc;
        
        // 分配内存空间并拷贝给定范围内的元素，返回由指向新空间的开始位置和拷贝的尾后位置的指针构成的pair
        pair<string *, string *> alloc_n_copy(const string *, const string *); 
        void free(); //逆序销毁构造的元素并释放内存
        void reallocate(); //在内存用完时重新分配内存，拷贝原有元素时使用移动构造函数
        void chk_n_alloc() //检查是否至少有一个容纳新元素的空间
        {
            if (size() == capacity())
                reallocate();
        }

    public:
        StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { } //默认构造函数，其中的alloc成员使用默认初始化
        StrVec(initializer_list<string> il); //形参类型相同、个数可变的可变参数构造函数

        StrVec(const StrVec &); //拷贝构造函数
        StrVec(StrVec &&) noexcept; //移动构造函数
        StrVec &operator=(const StrVec &); //拷贝赋值运算符
        StrVec &operator=(StrVec &&) noexcept; //移动赋值运算符
        StrVec &operator=(initializer_list<string> il);
        // 不管形参的类型是什么，赋值运算符都必须定义为成员函数

        ~StrVec(); //析构函数

        // 同时提供拷贝版本和移动版本的成员函数
        void push_back(const string &);
        void push_back(string &&);

        // 获取容器中元素数量和容量的成员函数
        size_t size() const { return first_free - elements; }
        size_t capacity() const { return cap - elements;}

        // 返回指向首元素和尾后元素的迭代器
        string *begin() const { return elements; }
        string *end() const { return first_free; }

        // 容器内存管理相关的成员函数
        void reserve(size_t n); //预分配至少能容纳n个元素的内存空间(可能更大)
        void resize(size_t n); //改变容器中元素的数量，如果n小于当前大小则删除多余的元素，否则在尾部添加默认初始化的元素

        // 下标运算符[]必须重载为类的成员函数，且必须返回容器中元素类型的引用，这样做的好处是返回值可以出现在等号的任意一端
        string &operator[](size_t n) { return elements[n]; }
        const string &operator[](size_t n) const { return elements[n]; }
        // 当常量对象调用重载的下标访问运算符时，返回容器中元素的常量引用，确保不会给返回的对象赋值
        // 赋值(=)、下标([])、调用( () )、成员访问箭头(->)运算符必须是成员

        // 重载相等、不相等运算符，由于希望该类运算符具有对称性操作，因此必须定义为友元函数
        friend bool operator==(const StrVec &, const StrVec &);
        friend bool operator!=(const StrVec &, const StrVec &);

        // 重载关系运算符，由于希望该类运算符具有对称性操作，因此必须定义为友元函数
        // 基本设计思路是逐个手动比较容器中的每个string
        friend bool operator<(const StrVec &, const StrVec &);
        friend bool operator<=(const StrVec &, const StrVec &);
        friend bool operator>(const StrVec &, const StrVec &);
        friend bool operator>=(const StrVec &, const StrVec &);
};

pair<string *, string *> StrVec::alloc_n_copy(const string *beg, const string *ed)
{
    string *data = alloc.allocate(ed - beg); //分配内存空间保存给定范围内的元素
    return {data, uninitialized_copy(beg, ed, data)};
    // 返回拷贝完成之后的元素所在区间
}

void StrVec::free()
{
    if (elements) //传递给deallocate的指针必须是之前某次allocate返回的指针，所以必须判断elements是否为空
    {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        // for_each(elements, first_free, [&](string &s) {alloc.destroy(&s);});
        // 因为在lambda表达式中要用到alloc成员变量，所以必须使用引用捕获this指针
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate()
{
    auto new_capacity = size() ? 2 * size() : 1;
    auto new_data = alloc.allocate(new_capacity);
    
    auto dest = new_data;
    auto elem = elements;

    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest ++, std::move(*elem ++)); //第二个参数决定了会调用string的移动构造函数
        // alloc.construct(dest ++, *elem ++); //会用到string的拷贝构造函数
    
    free(); //一旦移动完元素就释放旧的内存空间
    elements = new_data;
    first_free = dest;
    cap = elements + new_capacity;
}

// 使用移动迭代器的reallocate成员函数
// void StrVec::reallocate()
// {
//     auto new_capacity = size() ? 2 * size() : 1;
//     auto first = alloc.allocate(new_capacity);
//     auto last = uninitialized_copy(make_move_iterator(begin()), 
//                                                     make_move_iterator(end()), first);
//     free();
//     elements = first;
//     first_free = last;
//     cap = elements + new_capacity;
// }

StrVec::StrVec(initializer_list<string> il)
{
    auto new_data = alloc_n_copy(il.begin(), il.end());
    elements = new_data.first;
    cap = first_free = new_data.second;
}

// 拷贝构造函数，大多数情况下只有一个形参，且该形参必须是const类型的引用，否则会造成无限循环调用
StrVec::StrVec(const StrVec &rhs)
{
    auto new_data = alloc_n_copy(rhs.begin(), rhs.end());
    elements = new_data.first; //之前不需要释放源对象的内存空间，因为这是对象初始化
    first_free = cap = new_data.second;
}

// 移动构造函数，大多数情况下只有一个形参，且该形参必须是非const类型的右值引用，因为要改变源对象的状态
// 在声明和定义是都在参数列表之后指定noexcept，表示该函数不会抛出任何异常
StrVec::StrVec(StrVec &&rhs) noexcept : elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
    // 令源对象rhs进入这样的状态，对其调用析构函数是安全的
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto new_data = alloc_n_copy(rhs.begin(), rhs.end());
    free(); //释放原对象旧的内存空间
    elements = new_data.first;
    cap = first_free = new_data.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    // 有可能传入的右值是move调用返回的结果，所以必须检测是否是自赋值
    if (this != &rhs) //自赋值检测
    {
        free(); //释放原对象旧的内存空间
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr; //令源对象进入这样的状态，对其调用析构函数是安全的
    }
    return *this;
}

StrVec &StrVec::operator=(initializer_list<string> il)
{
    // 无需检查自赋值情况，因为形参的类型决定了不可能出现自赋值
    // alloc_n_copy分配内存空间并从给定范围内拷贝元素
    auto new_data = alloc_n_copy(il.begin(), il.end());
    free();                     //销毁对象中的元素并释放旧内存空间
    elements = new_data.first;  //更新数据成员并令其指向新内存空间
    cap = first_free = new_data.second;
    return *this;
}

StrVec::~StrVec()
{
    free();
}

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free ++, s);
}

void StrVec::push_back(string &&s)
{
    chk_n_alloc();
    alloc.construct(first_free ++,std::move(s));
    // 虽然形参类型为右值引用，但它本身还是左值，因此在传递给construct()函数时必须调用move()函数转换为右值
}

void StrVec::reserve(size_t n)
{
    if (n <= capacity())
        return; //当需求大小不超过当前容量时，什么也不做

    auto new_data = alloc.allocate(n); //与成员函数reallocate()的区别在于，这里不一定是开辟原来的两倍空间
    
    auto dest = new_data;
    auto elem = elements;

    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest ++, std::move(*elem ++));  //第二个参数决定了会调用string的移动构造函数
        // alloc.construct(dest ++, *elem ++); //会用到string的拷贝构造函数
    
    free();
    elements = new_data;
    first_free = dest;
    cap = elements + n;
}

void StrVec::resize(size_t n)
{
    if (n > size())
        while (size() < n)
            push_back(" "); //如果当前大小小于所要求的大小，容器中会添加默认初始化的元素
    else if (n < size())
        while (size() > n)
            alloc.destroy(--first_free); //如果当前大小大于所要求的大小，容器中多余的元素会被销毁
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    for (auto it1 = lhs.begin(), it2 = rhs.begin(); 
         it1 != lhs.end() && it2 != rhs.end(); it1 ++, it2 ++)
        {
            if (*it1 != *it2)
                return false;
        }
    
    return true;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
    auto it1 = lhs.begin(), it2 = rhs.begin();
    for ( ; it1 != lhs.end(), it2 != rhs.end(); it1 ++, it2 ++)
    {
        if (*it1 < *it2) //之前的string都相等，当前string更小
            return true;
        else if (*it1 > *it2) //之前的string都相等，当前string更大
            return false;
    }
    // lhs中的string都与rhs中的string相等，且更短
    if (it1 == lhs.end() && it2 != rhs.end())
        return true;
    return false;
}

bool operator<=(const StrVec &lhs, const StrVec &rhs)
{
    auto it1 = lhs.begin(), it2 = rhs.begin();
    for ( ; it1 != lhs.end(), it2 != rhs.end(); it1 ++, it2 ++)
    {
        if (*it1 < *it2) //之前的string都相等，当前string更小
            return true;
        else if (*it1 > *it2) //之前的string都相等，当前string更大
            return false;
    }
    // lhs中的string都与rhs中的string相等，且更短或一样长
    if (it1 == lhs.end())
        return true;
    return false;
}

bool operator>(const StrVec &lhs, const StrVec &rhs)
{
    auto it1 = lhs.begin(), it2 = rhs.begin();
    for ( ; it1 != lhs.end(), it2 != rhs.end(); it1 ++, it2 ++)
    {
        if (*it1 < *it2) //之前的string都相等，当前string更小
            return false;
        else if (*it1 > *it2) //之前的string都相等，当前string更大
            return true;
    }
    // rhs中的string都与lhs中的string相等，且更短
    if (it1 != lhs.end() && it2 == rhs.end())
        return true;
    return false;
}

bool operator>=(const StrVec &lhs, const StrVec &rhs)
{
    auto it1 = lhs.begin(), it2 = rhs.begin();
    for ( ; it1 != lhs.end(), it2 != rhs.end(); it1 ++, it2 ++)
    {
        if (*it1 < *it2) //之前的string都相等，当前string更小
            return false;
        else if (*it1 > *it2) //之前的string都相等，当前string更大
            return true;
    }
    // rhs中的string都与lhs中的string相等，且更短或一样长
    if (it2 == rhs.end())
        return true;
    return false;
}

int main()
{
    return 0;
}