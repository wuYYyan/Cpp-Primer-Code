#include <iostream>
#include <string>

using namespace std;

template <unsigned H, unsigned W>
class Screen; // 由于在模板函数的声明中要用到该类型的形参，所以需要前置声明

template <unsigned H, unsigned W>
ostream &operator<<(ostream &os, const Screen<H, W> &s);

template <unsigned H, unsigned W>
istream &operator>>(istream &is, Screen<H, W> &s);

template <unsigned H, unsigned W> // 使用非类型参数定义类模板
class Screen {
    // 模板类将访问权限授予使用相同类型实例化的模板函数
    friend ostream &operator<<<H, W>(ostream &os, const Screen<H, W> &s);
    friend istream &operator>><H, W>(istream &is, Screen<H, W> &s);
    private:
        string contents;
        unsigned cursor = 0;
    public:
        Screen() : contents(H * W, ' ') {}
        Screen(char c) : contents(H * W, c) {}

        Screen &set(char c); // 在类内声明可以只写类模板名
        Screen &set(unsigned row, unsigned col, char c);
        Screen &move(unsigned row, unsigned col);
        Screen &display() { cout << contents << endl; return *this; }
};

template <unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::set(char c) {
    contents[cursor] = c;
    return *this;
}

template <unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::set(unsigned row, unsigned col, char c) {
    contents[row * W + col] = c;
    return *this;
}

template <unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::move(unsigned row, unsigned col) {
    cursor = row * W + col;
    return *this;
}

template <unsigned H, unsigned W>
ostream &operator<<(ostream &os, const Screen<H, W> &s) {
    os << s.contents;
    return os;
}

template <unsigned H, unsigned W>
istream &operator>>(istream &is, Screen<H, W> &s) {
    string tmp;
    is >> tmp;
    s.contents = tmp.substr(0, H * W);
    return is;
} 

int main() {
    return 0;
}