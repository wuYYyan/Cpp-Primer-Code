#include <iostream>
#include <string>

using namespace std;

class ReadString
{
    private:
        istream &is;
    public:
        ReadString(istream &i = cin) : is(i) { }
        const string operator()() {
            string str;
            if (getline(is, str))
                return str;
            else
                return string();    
        } 
};