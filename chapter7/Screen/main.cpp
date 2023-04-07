#include "Screen.h"
#include <iostream>

using namespace std;

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.display();

    myScreen.move(4, 0).set('#').display();

    return 0;
}