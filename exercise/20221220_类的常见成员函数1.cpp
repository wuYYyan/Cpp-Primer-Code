//日期：20221220
//内容：复制构造函数、析构函数、重载输入输出运算符、重载赋值运算符
#include <iostream>
#include <cstring>

using namespace std;

class String
{
    private://类对象不能调用私有成员变量，只有成员函数可以
        char *str; //指向只有在实例化对象时才动态分配的内存空间
        int len; 
        static int num_strings; //类的所有对象共享一个静态成员变量
        static const int SIZE;  //存放在静态存储区，不属于任何一个对象

    public:
    /*
    一般成员函数的声明遵循如下顺序：静态成员函数 -> 默认构造函数 -> 复制构造函数 -> 传参/转换构造函数 -> 析构函数
    -> 内联函数 -> 一般成员函数 -> 重载运算符成员函数 -> 友元函数
    */

        // 静态成员函数不属于任何一个对象，因此不能通过某一个对象调用
        // 但需要通过类名+作用域解析运算符(::)调用，函数中同样访问的是静态成员变量
        static int Howmany();

        // 构造函数的定义中注意更新所有受影响的静态成员变量(num_strings)
        String(); //默认构造函数中如果有形参则必须全部带有默认参数，否则不能有任何一个形参
        String(const char *s); //有参构造函数，没有带默认参数，因此绝对不是默认构造参数
        String(const String &st); //重新声明复制构造函数(又称为拷贝构造函数)
        // 成员函数返回对象(而不是对象的引用)时会调用复制构造函数创建匿名对象
        ~String(); //使用关键字new动态分配内存时必须显式调用析构函数释放内存

        int length() const {return len;} //内联函数：函数定义直接写在类中

        void stringlow();
        void stringup();
        int has(char ch) const;

        // 赋值运算符会对调用函数的对象进行修改，因此只能返回非const对象
        // 为了提高连续使用赋值运算符时的效率(避免使用复制构造函数)，要返回非const对象的引用
        String &operator=(const String &st);
        String &operator=(const char *st);

        char &operator[](int i); //修改下标索引的元素
        // 既不修改对象也不修改字符，因此前后都要有const
        const char &operator[](int i) const; //访问下标索引的元素

        // 友元函数在类中声明，可以访问私有成员变量，但它本质上不是成员函数
        // 因为不是成员函数，所以定义时不需要有作用域运算符、不会转换为类对象的调用方式
        friend bool operator<(const String &str1, const String &str2);
        friend bool operator>(const String &str1, const String &str2);
        friend bool operator==(const String &str1, const String &str2);

        // 重载输入输出运算符时，为了与使用习惯相匹配必须使用友元函数重载
        // 为了方便串接/多个输入输出连续使用，重载时必须返回ostream/istream类对象或其引用
        // 而又因为ostream/istream类没有公有的复制构造函数，因此必须返回对象引用
        friend ostream &operator<<(ostream &os, const String &st);
        friend istream &operator>>(istream &is, String &st);
        // 重载输入运算符时一定会涉及到修改对象，因此要读入的对象不能用const修饰 

        // 为了保持加号使用时的交换律，需要用成员函数与非成员函数重载两次
        // 用来连接的两个字符串(或字符)在计算过程中保持不变，因此要用const限定
        // 计算完毕后，函数中用于存放计算结果的临时变量已不存在，因此只能返回对象，而不能是对象的引用
        friend String operator+(const char *s, const String &st);
        String operator+(const String &st) const;
};

// 初始化静态成员变量时，不再使用关键字static，只需声明类作用域
int String::num_strings = 0;
const int String::SIZE = 80;

int String::Howmany()
{
    return num_strings;  
}

String::String()
{
    num_strings++;
    len = 0;
    str = new char[1];
    str[0] = '\0';
}

String::String(const char *s)
{
    num_strings++;
    len = strlen(s);
    str = new char[len + 1]; //分配足够的空间来存储将要复制的数据
    strcpy(str, s); //复制数据，而不仅仅是数据的地址
    /*
    for (int i = 0; i < len; i ++)
        str[i] = s[i];
    */
}

String::String(const String &st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1]; //分配足够的空间来存储将要复制的数据
    strcpy(str, st.str); //复制数据，而不仅仅是数据的地址
    /*
    for (int i = 0; i < len; i ++)
        str[i] = st.str[i];
    */
}

// 当类的对象作用结束时(函数执行完毕或整个程序执行完毕)，析构函数会被自动调用
// 类中只能有一个析构函数，因此所有的构造函数都必须与之兼容(delete无论是否带[]都可以用于空指针)
String::~String()
{
    num_strings--; //更新静态变量
    delete []str; 
}

void String::stringlow()
{
    for (int i = 0; i < len; i ++)
        str[i] = tolower(str[i]);
}

void String::stringup()
{
    for (int i = 0; i < len; i ++)
        str[i] = toupper(str[i]);
}

int String::has(char ch) const
{
    int cnt = 0;
    for (int i = 0; i < len; i ++)
        if (str[i] == ch)
            cnt++;

    return cnt;
}

String &String::operator=(const String &st)
{
    if (this == &st)
        return *this; //当进行自我赋值时直接返回
    
    delete []str; //释放创建对象时成员指针指向的内存
    len = st.len;
    str = new char[len + 1]; //分配足够的空间来存储将要复制的数据
    strcpy(str, st.str); //复制数据，而不仅仅是数据的地址
    /*
    for (int i = 0; i < len; i ++)
        str[i] = st.str[i];
    */

    return *this; //this是指向对象的指针，所以要取内容
}

String &String::operator=(const char *st)
{
    // 形参类型不是类，因此无需检查自我复制的情况
    delete []str;
    len = strlen(st);
    str = new char[len+ 1];
    strcpy(str, st);
    /*
    for (int i = 0; i < len; i ++)
        str[i] = st.str[i];
    */

    return *this; //this是指向对象的指针，所以要取内容
}

char &String::operator[](int i)
{
    return str[i]; //这里用到的是指针的下标索引原理
}

const char &String::operator[](int i) const
{
    return str[i]; //这里用到的是指针的下标索引原理
}

bool operator<(const String &str1, const String &str2)
{
    return (strcmp(str1.str, str2.str) < 0);
}

bool operator>(const String &str1, const String &str2)
{
    return str2 < str1; //用到成员函数中<运算符的重载
}

bool operator==(const String &str1, const String &str2)
{
    return (strcmp(str1.str, str2.str) == 0);
}

ostream &operator<<(ostream &os, const String &st)
{
    os << st.str;
    return os;
}

// 重载输入运算符时必须要更改对象，因此不能加const
istream &operator>>(istream &is, String &st)
{
    char temp[String::SIZE];
    is.get(temp, String::SIZE); //面向整行的读取输入函数
    // is.getline(temp, String::SIZE);

    if (is)
        st = temp; //用到前面赋值运算符的重载
    
    // 消耗输入缓冲区中剩下的/放不下的字符
    // cin.get()用于读取单个字符，即便是换行符也可以读取
    while (is && is.get() != '\n')
        continue; 
    return is;
}

String operator+(const char *s, const String &st)
{
    String temp;

    temp.len = strlen(s) + st.len;
    temp.str = new char[temp.len + 1];
    strcpy(temp.str, s); //字符串拷贝函数
    strcat(temp.str, st.str); //字符串追加函数

    return temp;
}

String String::operator+(const String &st) const
{
    String temp;

    temp.len = len + st.len;
    temp.str = new char[temp.len + 1];
    strcpy(temp.str, str); //字符串拷贝函数
    strcat(temp.str, st.str); //字符串追加函数

    return temp;
}

int main()
{
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name: ";
    String s3;

    cout << s2;
    cin >> s3;
    s2 = "My name is " + s3;
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup();
    cout << "The string\n" << s2 << "\ncontains " << s2.has('A') << " 'A' characters in it.\n";
    s1 = "red";
    
    String rgb[3] = {String(s1), String("green"), String("blue")};
    cout << "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while (cin >> ans)
    {
        ans.stringlow();
        for (int i = 0; i < 3; i ++)
        {
            if (ans == rgb[i])
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again!\n";
    }
    cout << "Bye\n";

    return 0;
}