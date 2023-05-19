#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <memory>
#include <map>
#include <set>

using namespace std;

void runQueries(ifstream &infile);

vector<string> file;
map<string, set<int>> wm;

class QueryResult;

class TextQuery
{
    public:
        TextQuery(ifstream &infile);
        QueryResult query(const string &str) const;
    private:
        shared_ptr<vector<string>> file;
        map<string, shared_ptr<set<int>>> wm;
        string remove_punc(string &s);
};

class QueryResult
{
    public:
        QueryResult(string s, shared_ptr<set<int>> p, shared_ptr<vector<string>> f) : str(s), lines(p), file(f) {}
        friend ostream &print(ostream &os, const QueryResult &qr);
        set<int>::iterator begin() const { return lines->begin(); }
        set<int>::iterator end() const { return lines->end(); }
        shared_ptr<vector<string>> get_file() const { return file; }
    private:
        string str;
        shared_ptr<set<int>> lines;
        shared_ptr<vector<string>> file;
};

TextQuery::TextQuery(ifstream &infile) : file(new vector<string>)
{
    string text;
    while (getline(infile, text))
    {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word)
        {
            auto &lines = wm[remove_punc(word)]; //返回值是一个智能指针
            if (!lines) //当一个单词第一次出现时需要分配一个新的set(开辟内存空间)
                lines.reset(new set<int>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &str) const
{
    static shared_ptr<set<int>> nodata(new set<int>);
    auto loc = wm.find(str);
    if (loc == wm.end())
        return QueryResult(str, nodata, file);
    else
        return QueryResult(str, loc->second, file);
}

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.str << " occurs " << qr.lines->size() << " times" << endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    return os;
}

int main(int argc, char *argv[]) // ./a.exe book.txt
{
    ifstream infile;
    infile.open(argv[1]);

    runQueries(infile);

    return 0;
}

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}

string TextQuery::remove_punc(string &s)
{
    string result;
    for (auto c : s)
    {
        if (!ispunct(c))
            result += c;
    }
    return result;
}