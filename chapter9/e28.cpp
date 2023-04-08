#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

void search_insert(forward_list<string> &l, const string &s1, const string &s2);

int main()
{
    forward_list<string> list = {"Hello", "World", "Good", "Morning"};
    search_insert(list, "World", "Rick");

    for(const auto &r : list)
        cout << r << " ";
    cout << endl;

    return 0;
}

void search_insert(forward_list<string> &l, const string &s1, const string &s2)
{
    auto pre = l.before_begin(), cur = l.begin();
    bool flag = false;

    while(cur != l.end())
    {
        if(*cur == s1)
        {
            cur = l.insert_after(cur, s2);
            flag = true;
        }
        pre = cur;
        cur++;
    }

    if(flag == false)
        l.insert_after(pre, s2);

    return;
}