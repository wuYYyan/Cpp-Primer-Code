#include <iostream>

using namespace std;

class Employee
{
    private:
        static int id;
        string name;
        int mysn;
    public:
        Employee() { mysn = id++; }
        Employee(string s) : name(s) { mysn = id++; }
        Employee(const Employee &e) : name(e.name) { mysn = id++; }
        Employee &operator=(const Employee &e) { name = e.name; return *this; }
};

int main()
{
    return 0;
}