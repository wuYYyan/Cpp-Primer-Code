#include <iostream>
#include <string>
#include <vector>

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

int main()
{
    ReadString rs;

    vector<string> svec = {rs(), rs(), rs()};
    for (const auto &r : svec)
        std:: cout << r << ' ';
    std::cout << endl;

    return 0;
}