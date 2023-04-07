//日期：20221227
//内容：类成员函数的继承问题
#include <iostream>
#include <cstring>

using namespace std;

class ABC //基类
{
    private:
        char *label;
        int rating;
    public:
        ABC(const char *l = "null", int r = 0); //默认构造函数，此处所有形参都有默认参数
        ABC(const ABC &rs); //复制构造函数，构造函数不能是虚函数
        virtual ~ABC(); //当一个类是基类时，其析构函数必须为虚函数

        //当基类中的成员函数为虚函数时，通过引用或指针调用该函数将由引用或指向的对象的类型决定调用基类还是派生类的成员函数
        //当基类中的成员函数不是虚函数时，通过引用或指针调用该函数将直接有引用本身或指针本身的类型决定调用基类还是派生类的成员函数
        virtual void View() const; 
        //赋值运算符是成员函数，但声明为虚函数没有意义，因此不会通过引用或指针调用
        ABC &operator=(const ABC &s);

        //友元函数不是成员函数，因此无法被继承、不能声明为虚函数
        friend ostream &operator<<(ostream &os, const ABC &rs);
};

class baseDMA : public ABC //派生类1，该派生类并没有添加专属的成员变量，因此少写很多成员函数
{
    public:
        //构造函数无法被继承，也不能是虚函数，它使用成员初始化列表的方式调用基类的构造函数
        baseDMA(const char *l = "null", int r = 0);
        baseDMA(const baseDMA &rs); //复制构造函数

        //当要重写虚函数时，最好在派生类的声明中也是用关键字virtual，增强可读性
        virtual void View() const;
};

class lacksDMA : public ABC //派生类2，该派生类虽然有专属的成员变量，但并不使用new开辟新的内存空间
{//因此不需要重写赋值构造函数、析构函数、重载赋值运算符
    private:
        enum {COL_LEN = 40};
        char color[COL_LEN];
    public:
        lacksDMA(const char *l = "null", int r = 0, const char *c = "blank");
        lacksDMA(const ABC &rs, const char *c = "blank"); 
        //这是一个构造函数，只不过第一个形参是基类对象，第二个形参带了一个默认参数
        //但不是默认构造函数，因为默认构造函数如果有形参则应该所有形参都有默认参数

        //当要重写虚函数时，最好在派生类的声明中也是用关键字virtual，增强可读性
        virtual void View() const;

        //友元函数不是成员函数，因此无法被继承、不能声明为虚函数
        friend ostream &operator<<(ostream &os, const lacksDMA &rs);
};

class hasDMA : public ABC //派生类3，该派生类不仅有专属的成员变量，而且使用new开辟新的内存空间
{//因此必须要重写赋值构造函数、析构函数、重载赋值运算符
    private:
        char *style;
    public:
        hasDMA(const char *l = "null", int r = 0, const char *s = "null");
        hasDMA(const ABC &rs, const char *s);
        hasDMA(const hasDMA &rs);
        ~hasDMA();

        //当要重写虚函数时，最好在派生类的声明中也是用关键字virtual，增强可读性
        virtual void View() const;
        hasDMA &operator=(const hasDMA &hs);

        //友元函数不是成员函数，因此无法被继承、不能声明为虚函数
        friend ostream &operator<<(ostream &os, const hasDMA &rs);
};

//函数定义中不写形参的默认参数
ABC::ABC(const char *l, int r)
{
    label = new char[strlen(l) + 1];
    strcpy(label, l);
    rating = r;
}

ABC::ABC(const ABC &rs)
{
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
}

ABC::~ABC()
{
    delete []label;
}

//虚函数的函数定义中不再使用关键字virtual
void ABC::View() const
{
    cout << "Label: " << label << endl;
    cout << "Rating: " << rating << endl;
}

//注意必须有返回值
ABC &ABC::operator=(const ABC &rs)
{
    if (this == &rs)
        return *this;
    delete []label;
    label = new char [strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

//友元函数的函数定义中不再使用关键字friend
ostream &operator<<(ostream &os, const ABC &rs)
{
    os << "Label: " << rs.label << endl;
    os << "Rating: " << rs.rating << endl;
    return os;
}

//通过成员初始化列表的方式调用基类的构造函数，编译器会通过形参列表自动匹配
baseDMA::baseDMA(const char *l, int r) : ABC(l, r)
{

}

//通过成员初始化列表的方式调用基类的构造函数，该构造函数的形参是基类的引用，因此可传入派生类的对象
baseDMA::baseDMA(const baseDMA &rs) : ABC(rs)
{

}

void baseDMA::View() const
{
    ABC::View(); //在派生类的成员函数中调用基类的成员函数，必须显式地指明作用域
}

//通过成员初始化列表的方式调用基类的构造函数，编译器会通过形参列表自动匹配
lacksDMA::lacksDMA(const char *l, int r, const char *c) : ABC(l, r)
{
    strncpy(color, c, COL_LEN - 1);

    //必须判断数组的最大容量和传入字符串的长度，确保数组以空字符结尾
    if (strlen(c) >= COL_LEN)
        color[39] = '\0';
    else
        color[strlen(c)] = '\0';
}

//将形参传入基类的复制构造函数
lacksDMA::lacksDMA(const ABC &rs, const char *c) : ABC(rs)
{
    strncpy(color, c, COL_LEN - 1);

    //必须判断数组的最大容量和传入字符串的长度，确保数组以空字符结尾
    if (strlen(c) >= COL_LEN)
        color[39] = '\0';
    else
        color[strlen(c)] = '\0';
}

void lacksDMA::View() const
{
    ABC::View(); //在派生类的成员函数中调用基类的成员函数，必须显式地指明作用域
    cout << "Color: " << color << endl;
}

ostream &operator<<(ostream &os, const lacksDMA &rs)
{
    os << (const ABC &)rs; //要使用基类的友元函数，可以通过强制类型转换将派生类的引用或指针转换为基类的引用或指针
    os << "Color: " << rs.color << endl;

    return os; //必须有返回值
}

//通过成员初始化列表的方式调用基类的构造函数，编译器会通过形参列表自动匹配
hasDMA::hasDMA(const char *l, int r, const char *s) : ABC(l, r)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

//将形参传入基类的复制构造函数
hasDMA::hasDMA(const ABC &rs, const char *s) : ABC(rs)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

//通过成员初始化列表的方式调用基类的构造函数，该构造函数的形参是基类的引用，因此可传入派生类的对象
hasDMA::hasDMA(const hasDMA &hs) : ABC(hs)
{
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete []style;
}

hasDMA &hasDMA::operator=(const hasDMA &hs)
{
    if (this == &hs)
        return *this;
    
    ABC::operator=(hs); //函数表示法调用基类中重载的赋值运算符
    //在派生类的成员函数中调用基类的成员函数，必须显式地指明作用域
    //其实在编译器看来，重载运算符的函数名是“operator + 运算符”

    delete []style;
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);

    return *this; //必须有返回值
}

ostream &operator<<(ostream &os, const hasDMA &hs)
{
    os << (const ABC &)hs;
    os << "Style: " << hs.style << endl;

    return os; //必须有返回值
}

void hasDMA::View() const
{
    ABC::View(); //要使用基类的友元函数，可以通过强制类型转换将派生类的引用或指针转换为基类的引用或指针
    cout << "Style: " << style << endl;
}

int main()
{
    baseDMA shirt("Protabelly", 8);
    cout << "Displaying baseDMA object: " << endl;
    cout << shirt;
    cout << "-------------------" << endl;

    lacksDMA ballon("Blimpo", 4, "red");
    cout << "Displaying lacksDMA object: " << endl;
    cout << ballon;
    cout << "-------------------" << endl;

    lacksDMA ballon2(ballon); //这里调用的是默认的复制构造函数
    cout << "Result of lacksDMA copy: " << endl;
    cout << ballon2;
    cout << "-------------------" << endl;

    hasDMA map("Keys", 5, "Mercator");
    cout << "Displaying hasDMA object: " << endl;
    cout << map;
    cout << "-------------------" << endl;

    hasDMA map2 = map; //这里是类的对象的初始化，将调用用户显式定义的复制构造函数
    cout << "Result of hasDMA copy: " << endl;
    cout << map2;
    cout << "-------------------" << endl;

    hasDMA map3;
    map3 = map; //这里是类对象的赋值，将调用显式定义的重载的赋值运算符
    cout << "Result of hasDMA copy: " << endl;
    cout << map3;
    cout << "-------------------" << endl;

    return 0;
}