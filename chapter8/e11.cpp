#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    istringstream record;
    vector<PersonInfo> people;

    while(getline(cin, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while(record >> word)
            info.phones.push_back(word);

        people.push_back(info);
    }

    for(auto &r : people)
    {
        cout << r.name << " ";
        for(auto &ref : r.phones)
            cout << ref << " ";
        cout << endl;
    }

    return 0;
}