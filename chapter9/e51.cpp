#include <string>
#include <iostream>

using namespace std;

class Date
{
    private:
        unsigned int day;
        unsigned int month;
        unsigned int year;
    public:
        Date(string date); 
};

string Month[] = {"January"};

Date::Date(string date)
{
    string::size_type pos = 0;
    if((pos = date.find(",")) != string::npos)
    {
        year = stoi(date.substr(pos + 1));
        auto pos2 = date.find(" ");
        day = stoi(date.substr(pos + 1, pos - pos2 - 1));
        string s = date.substr(0, pos2);
    }
}

int main()
{
    string str1 = "January 1,1990";
    Date d1(str1);

    return 0;
}