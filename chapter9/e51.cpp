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
        void show() const; 
};

string Month[] = {"January", "February", "March", "April", 
                    "May", "June", "July", "August", "September",
                    "October", "November", "December"};
string Month_abbr[] = {"Jan", "Feb", "Mar", "Apr", 
                    "May", "Jun", "Jul", "Aug", "Sep",
                    "Oct", "Nov", "Dec"};

Date::Date(string date)
{
    string::size_type pos = 0;

    if((pos = date.find(",")) != string::npos)
    {
        year = stoi(date.substr(pos + 1));
        auto pos2 = date.find(" ");
        day = stoi(date.substr(pos2 + 1, pos - pos2 - 1));
        string s = date.substr(0, pos2);
        for(int i = 0 ; i < 12; i ++)
        {
            if(s == Month[i])
            {
                month = i + 1;
                break;
            }
        }
    }
    else if((pos = date.find("/")) != string::npos)
    {
        day = stoi(date.substr(0, pos));
        auto pos2 = date.rfind("/");
        month = stoi(date.substr(pos + 1, pos2 - pos - 1));
        year = stoi(date.substr(pos2 + 1));
    }
    else if((pos = date.find(" ")) != date.rfind(" "))
    {
        string s = date.substr(0, pos);
        for(int i = 0; i < 12; i ++)
        {
            if(s == Month_abbr[i])
            {
                month = i + 1;
                break;
            }
        }
        auto pos2 = date.rfind(" ");
        year = stoi(date.substr(pos2 + 1));
        day = stoi(date.substr(pos + 1, pos2 - pos - 1));
    }
}

void Date::show() const
{
    cout << "Day = " << day;
    cout << " Month = " << month;
    cout << " Year = " << year;
    cout << endl;
}

int main()
{
    string str1 = "January 1,1900";
    Date d1(str1);
    d1.show();

    string str2 = "1/1/1900";
    Date d2(str2);
    d2.show();

    string str3 = "Jan 1 1900";
    Date d3(str3);
    d3.show();

    return 0;
}