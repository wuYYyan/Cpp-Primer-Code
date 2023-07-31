#include <iostream>
#include <cstring>

using namespace std;

// 设计一个类首先要思考需要封装哪些数据
// 如果开辟一个存放字符的数组大小不确定，所以存放一个指向字符的指针
class String
{
    friend ostream &operator<<(ostream& os, const String& str);
    public:
        String(const char* str = 0);
        String(const String &str);
        String& operator=(const String &str);
        ~String();
        char* get_c_str() const { return m_data; }
    private:
        char *m_data;
};

ostream& operator<<(ostream& os, const String& str)
{
    os << str.get_c_str();
    return os;
}

inline String::String(const char* str)
{
    if (str)
    {
        m_data = new char[strlen(str) + 1];
        // strlen()函数在计算字符串长度时不包含末尾结束符，所以最后加一
        strcpy(m_data, str);
    }
    else
    {
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline String::String(const String& str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

inline String& String::operator=(const String& str)
{
    // 检测自我赋值
    if (this == &str)
        return *this;
    
    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

inline String::~String()
{
    delete[] m_data;
}

int main()
{
    return 0;
}