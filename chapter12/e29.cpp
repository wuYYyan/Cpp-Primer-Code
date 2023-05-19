#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <set>

using namespace std;

void runQueries(ifstream &infile);
void input_text(ifstream &infile);
void query_and_print(const string &str);
string remove_punc(string &s);

vector<string> file;
map<string, set<int>> wm;

int main(int argc, char *argv[]) // ./a.exe book.txt
{
    ifstream infile;
    infile.open(argv[1]);

    runQueries(infile);

    return 0;
}

void runQueries(ifstream &infile)
{
    input_text(infile);
    do
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        query_and_print(s);
    }while(true);
}

void input_text(ifstream &infile)
{
    string text;
    while (getline(infile, text))
    {
        file.push_back(text);
        int n = file.size() - 1;
        istringstream line(text);
        string word;
        while (cin >> word)
        {
            wm[remove_punc(word)].insert(n);
        }
    }
        
}

void query_and_print(const string &str)
{
    auto pos = wm.find(str);
    if (pos == wm.end())
    {
        cout << str << " occurs 0 times" << endl;
        return;
    }
    auto lines = pos->second; //pos->second是一个set<int>对象
    cout << str << " occurs " << lines.size() << " times" << endl;
    for (const auto &num : lines)
        cout << "\t(line " << num + 1 << ") " << file[num] << endl;
}

string remove_punc(string &s)
{
    string result;
    for (auto c : s)
    {
        if (!ispunct(c))
            result += c;
    }
    return result;
}