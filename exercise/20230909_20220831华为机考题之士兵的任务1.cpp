// 链接：https://mp.weixin.qq.com/s/PBXKKCjD2QfDUV45ESPkPg
#include <bits/stdc++.h>

using namespace std;

const int N = 30;

struct node {
    int x, y, t;
    node() { } // 一般情况下，只要提供了含参构造函数就要手动提供一个默认构造函数
    node(int x_, int y_, int t_) : x(x_), y(y_), t(t_) {}
    bool operator<(const node &a) const {
        return t > a.t; // 返回为true说明前者的优先级较高，在优先队列中优先级较高的元素会下沉
    }
    // 比较运算符重载函数必须定义为const成员函数，否则会报错
};

int n, m, res;
int g[N][N], vis[N][N];
priority_queue<node> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> g[i][j];
            if (g[i][j] == 2) {
                vis[i][j] = 1;
                q.push(node(i, j, 0));
            }
            // 这种做法不涉及到函数的调用，终归还是顺序执行
            // 所以可以一边读取一边入队列
        }
    }

    while (q.size()) {
        node cur = q.top();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int x = cur.x + dx[i];
            int y = cur.y + dy[i];
            if (x < 0 || x > n || y < 0 || y > m || g[x][y] == 1 || vis[x][y] == 1)
                continue;
            if (g[x][y] == 3) {
                res = cur.t + 1;
                break;
            }
            vis[x][y] = 1;
            if (g[x][y] == 4)
                q.push(node(x, y, cur.t + 3));
            else if (g[x][y] == 6) {
                q.push(node(x, y, cur.t + 1));
                for (int j = 0; j < 4; j ++) {
                    int xx = x + dx[j];
                    int yy = y + dy[j];
                    if (g[xx][yy] == 1)
                        g[xx][yy] = 0;
                }
            } else // g[x][y] == 0 成立的情况，直接走到下一个路上
                q.push(node(x, y, cur.t + 1));
        }
        if (res) // 只有遇到终点才会更新res，所以当条件成立时就已经到达终点不再走了
            break;
    }
    cout << res << endl;
    return 0;
}