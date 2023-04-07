#include <iostream>
#include <queue>
#include <deque> //deque = double-ended queue

using namespace std;

int main()
{
    queue<int> q;

    for (int i = 0; i < 5; i ++)
        q.push(3 * i - 2); //向队尾插入元素
    q.pop(); //弹出队头元素

    cout << "此时队头元素是: " << q.front() << endl; //返回队头元素
    cout << "此时队尾元素是: " << q.back() << endl;  //返回队尾元素

    q.pop();
    cout << "此时队列中有" << q.size() << "个元素" << endl;

    q = queue<int>(); //没有clear清空队列的函数，只能采用这种方法
    if (q.empty())
        puts("此时队列为空");
    else
        puts("此时队列不为空");

    return 0;
}