#include <map>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    map<string, list<int>> word_line;
    ifstream in(argv[1]);
    string line, word;
    int line_num = 0;
    while(getline(in, line))
    {
        ++line_num;
        istringstream record(line); //从字符串流中读取数据，C++ Primer P288
        while(record >> word)
            word_line[word].push_back(line_num);
    }
    for(const auto &r : word_line)
    {
        cout << r.first << " appears on line(s): ";
        for(const auto &r1 : r.second)
            cout << r1 << " ";
        cout << endl; 
    }
}