#include <iostream>
#include <cstring>

using namespace std;

// ���һ��������Ҫ˼����Ҫ��װ��Щ����
// �������һ������ַ��������С��ȷ�������Դ��һ��ָ���ַ���ָ��
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
        // strlen()�����ڼ����ַ�������ʱ������ĩβ����������������һ
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
    // ������Ҹ�ֵ
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