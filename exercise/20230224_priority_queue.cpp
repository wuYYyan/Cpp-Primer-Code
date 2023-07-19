#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    priority_queue<int> heap1; //优先队列默认定义是大根堆，即堆顶元素是其中最大元素
    priority_queue<int, vector<int>, greater<int>> heap2;
    // 通过传入第三个模板参数，可以实现小根堆，即堆顶元素是其中最小元素

    //向堆中插入元素
    heap1.push(1);
    heap1.push(4);
    heap1.push(2);
    heap1.push(3);

    cout << "heap1的堆顶元素为: " << heap1.top() << endl; //返回堆顶元素
    heap1.pop();
    cout << "heap1的堆顶元素为: " << heap1.top() << endl; //返回堆顶元素

    heap2.push(1);
    heap2.push(4);
    heap2.push(2);
    heap2.push(3);

    cout << "heap2的堆顶元素为: " << heap2.top() << endl; //返回堆顶元素
    heap2.pop();
    cout << "heap2的堆顶元素为: " << heap2.top() << endl; //返回堆顶元素

    cout << heap2.size() << endl;
    if (heap2.empty())
        puts("此时优先队列heap2为空");
    else
        puts("此时优先队列heap2不为空");

    return 0;
}