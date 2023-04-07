#include <stack>
#include <iostream>

using namespace std;

int main()
{
    stack<int> stk;

    //向栈顶插入元素
    stk.push(3);
    stk.push(4);
    stk.push(1);
    stk.push(2);

    cout << stk.top() << endl; // 返回栈顶元素但不弹出
    stk.pop();                 // 弹出栈顶元素
    cout << stk.top() << endl; 

    cout << stk.size() << endl;
    if (stk.empty())
        puts("此时栈stk为空");
    else
        puts("此时栈stk不为空");


    return 0;
}