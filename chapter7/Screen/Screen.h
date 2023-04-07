#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <string>
#include <iostream>

using namespace std;

class Screen
{
    private:
        unsigned int cursor = 0;
        unsigned int height = 0, width = 0;
        string contents;
    public:
        Screen() = default;
        Screen(unsigned int ht, unsigned int wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
        Screen(unsigned int ht, unsigned int wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

        Screen &set(char c);
        Screen &set(unsigned int row, unsigned int col, char c);
        Screen &move(unsigned int row, unsigned int col);
        Screen &display() {cout << contents << endl; return *this;}
};

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;

    return *this;
}

inline Screen &Screen::set(unsigned int row, unsigned int col, char c)
{
    contents[row * width + col] = c;

    return *this;    
}

inline Screen &Screen::move(unsigned int row, unsigned int col)
{
    cursor = row * width + col;
    return *this;
}  

#endif