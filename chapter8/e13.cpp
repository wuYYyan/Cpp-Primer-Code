#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main()
{
    ifstream ifs("e13.txt");
    if(!ifs)
    {
        cerr << "Failed to open the file!" << endl;
        return -1;
    }

    string line, word;
    istringstream record;
    vector<PersonInfo> people;

    while(getline(ifs, line))
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