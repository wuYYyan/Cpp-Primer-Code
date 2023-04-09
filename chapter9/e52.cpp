#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string str = "I love (ABCD)"; // --> I love (DCBA)
    stack<char> stk;
    bool flag = false;

    for(const auto &r : str)
    {
        if(r == '(')
        {
            flag = true;
            continue;
        }
        else if(r == ')')
            flag = false;

        if(flag == true)
            stk.push(r);
    }

    string replace_str;
    while(!stk.empty())
    {
        replace_str.push_back(stk.top());
        stk.pop();
    }

    cout << replace_str << endl;

    str.replace(str.find('(') + 1, replace_str.size(), replace_str);
    cout << str << endl;

    return 0;
}