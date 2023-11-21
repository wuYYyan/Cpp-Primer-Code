#include <bits/stdc++.h>

using namespace std;

struct node {
    int x;
    node() {}
    node(int x_) : x(x_) {}
    bool operator<(const node &n) const {
        // ����trueʱ���ȼ��ϸ�
        // return x > n.x; 
        return x < n.x; 
    }
};

int main()
{
    priority_queue<node> q; // �����ȶ����У����ȼ��ϸߵ��³������ȼ��ϵ͵��ϸ�
    // Ĭ���Ǵ���ѣ�����ʵ�ڲ�������<�����������С�������ȼ��ϸ��³����ϴ��������ȼ��ϵ��ϸ�

    q.push(node(1));
    q.push(node(2));
    q.push(node(3));

    while (q.size()) {
        auto t = q.top();
        cout << t.x << " ";
        q.pop();
    } // 1 2 3

    cout << endl;

    set<node> s; // �ڹ�ϣ���У����ȼ��ϸߵ���ǰ�棬���ȼ��ϵ͵��ں���

    s.insert(node(1));
    s.insert(node(2));
    s.insert(node(3));

    for (auto it = s.begin(); it != s.end(); it ++)
        cout << it->x << " "; // 3 2 1
    cout << endl;
    
    return 0;
}