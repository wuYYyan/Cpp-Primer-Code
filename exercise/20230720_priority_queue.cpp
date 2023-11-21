#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    // 优先队列是一种容器适配器，它提供了常数时间的获取最大值和最小值的操作，但是不支持遍历操作
    priority_queue<int> heap1; //默认是大根堆，底层默认使用vector作为容器
    priority_queue<int, deque<int>> heap2; //使用deque作为底层实现结构，但还是大根堆

    priority_queue<int, vector<int>, greater<int>> heap3;
    // 第一个模板参数表示priority_queue中存放的元素类型
    // 第二个模板参数表示priority_queue的底层容器类型，可以是vector、deque
    // priority_queue是STL中的容器适配器，它接受一种已有的容器类型，但使自身的行为看起来像另一种容器类型
    // priority_queue默认使用vector作为底层容器，当然也可以使用deque作为底层容器
    // 第三个参数表示priority_queue对元素的比较方式，必须是一个返回值是bool类型的可调用对象
    // 可调用对象返回值为true表示第一个参数的优先级高于第二个参数，在优先队列中，优先级较高的元素下沉，优先级较低的元素上浮
    // 该可调用对象接受两个参数，返回值为true表示第一个参数的优先级高于第二个参数
    // 可用的可调用对象有：标准库定义的函数对象less<T>、greater<T>，以及自定义的函数对象
    // 如lambda表达式、函数指针、重载了【函数调用运算符operator()】的类等

    heap3.push(13);
    heap3.push(97);
    heap3.push(51);
    // 由于heap3底层是使用vector实现的，因此它不同于二叉搜索树需要存储指针索引左右子节点，而是通过下标的方式进行索引，
    // 对于在vector中的下标为i的节点，其左子节点下标为2i+1，右子节点下标为2i+2

    // priority_queue不适用范围for语句
    // for (const auto &i : h)
    //     cout << i << " ";
    // cout << endl;

    while (heap3.size()) {
        cout << heap3.top() << endl;
        heap3.pop();
    } // heap3是小根堆，所以输出顺序应该是13 51 97

    unordered_map<int, int> m;

    return 0;
}