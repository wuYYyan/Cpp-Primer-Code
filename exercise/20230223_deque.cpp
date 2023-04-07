#include <iostream>
#include <deque>

using namespace std;

int main()
{
    //deque相当于加强版的vector
    //创建对象
    deque<int> q1;        //创建一个没有任何元素的空双端队列
    deque<int> q2(5);     //创建一个拥有5个元素的双端队列，其中每个元素都采用对应类型的默认值
    deque<int> q3(5, 5);  //创建一个拥有5个元素的双端队列，并为每个元素都指定初始值
    deque<int> q4(q3);    //拷贝构造初始化
    deque<int> q5(q3);    //拷贝构造初始化

    q3.push_front(1); //在队头插入元素
    q3.push_back(6);  //在队尾插入元素

    //正序输出
    int len1 = q3.size();
    for (int i = 0; i < len1; i ++)
    {
        cout << q3.front() << ' '; //返回队头元素
        q3.pop_front(); //弹出队头元素
    }
    cout << endl;
    
    q4.push_front(2); //在队头插入元素
    q4.push_back(7);  //在队尾插入元素

    //逆序输出
    int len2 = q4.size();
    for (int i = 0; i < len2; i ++)
    {
        cout << q4.back() << ' '; //返回队尾元素
        q4.pop_back(); //弹出队尾元素
    }
    cout << endl;

    q5.push_front(3); //在队头插入元素
    q5.push_back(8);  //在队尾插入元素

    //使用迭代器正序输出
    for (auto i = q5.begin(); i != q5.end(); i ++) 
        cout << *i << ' ';
    cout << endl;

    q3.clear();
    cout << q3.size() << endl;
    if (q3.empty())
        puts("此时队列q3为空");
    else
        puts("此时队列q3不为空");

    
    return 0;
}