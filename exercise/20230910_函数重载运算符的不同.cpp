#include <bits/stdc++.h>

using namespace std;

struct node {
    int x;
    node() {}
    node(int x_) : x(x_) {}
    bool operator<(const node &n) const {
        return x > n.x;
    }
};

int main()
{
    priority_queue<node> q; // 在优先队列中，优先级较高的下沉，优先级较低的上浮

    q.push(node(1));
    q.push(node(2));
    q.push(node(3));

    while (q.size()) {
        auto t = q.top();
        cout << t.x << " ";
        q.pop();
    } // 3 2 1

    cout << endl;

    set<node> s;

    s.insert(node(1));
    s.insert(node(2));
    s.insert(node(3));

    for (auto it = s.begin(); it != s.end(); it ++)
        cout << it->x << " "; // 1 2 3
    cout << endl;
    
    return 0;
}