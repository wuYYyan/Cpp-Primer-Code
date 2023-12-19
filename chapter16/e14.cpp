#include <iostream>
#include <string>

using namespace std;

template <unsigned H, unsigned W> // 使用非类型参数定义类模板
class Screen {
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

int main() {
    return 0;
}