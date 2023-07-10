#include <iostream>

using namespace std;

int main()
{
    const char* p = "abc"; 
    char* c = (char*)p;  
    c[1] = 'g'; 
    cout << c;
}

