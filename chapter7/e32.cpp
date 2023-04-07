#include <iostream>

using namespace std;

class Window_mgr
{
    public:
        void clear();
};

class Screen
{
    friend void Window_mgr::clear();

    private:
        unsigned int cursor = 0;
        unsigned int height = 0, width = 0;
        string contents;
    public:
        Screen() = default;
        Screen(unsigned int ht, unsigned int wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
        Screen(unsigned int ht, unsigned int wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
};

void Window_mgr::clear()
{
    Screen myScreen(10, 20, 'A');
    myScreen.contents = " ";
    cout << myScreen.contents << endl;
}

int main()
{
    Window_mgr wm;
    wm.clear();

    return 0;
}