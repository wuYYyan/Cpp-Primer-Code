// 链接：https://mp.weixin.qq.com/s/PBXKKCjD2QfDUV45ESPkPg
#include <bits/stdc++.h>

using namespace std;

struct node {
    int x, y, t;
    node() {}
    node(int x_, int y_, int t_) : x(x_), y(y_), t(t_) {}
    bool operator<(const node &n) const {
        return t > n.t;
    }
};

void bfs(int x, int y);
void dfs1(int x, int y);
void dfs2(int x, int y);
void dfs3(int x, int y, int t);

const int N = 30;
int n, m, res = 0;
int g[N][N], vis[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            cin >> g[i][j];

    // 因为要进行函数调用，所以必须全部读取完成之后才能调用递归函数
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            if (g[i][j] == 2) {
                // bfs(i, j);
                // dfs1(i, j);
                // dfs2(i, j);
                dfs3(i, j, 0);
            }   

    cout << res << endl;

    return 0;
}

void bfs(int x, int y) {
    vis[x][y] = 1;
    priority_queue<node> q;
    q.push(node(x, y, 0));
    while (q.size()) {
        node cur = q.top();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int a = cur.x + dx[i], b = cur.y + dy[i];
            if (a < 0 || a > n || b < 0 || b > m || g[a][b] == 1 || vis[a][b] == 1)
                continue;
            if (g[a][b] == 3) {
                res = cur.t + 1;
                break;
            }
            vis[a][b] = 1;
            if (g[a][b] == 4)
                q.push(node(x, y, cur.t + 3));
            else if (g[a][b] == 6) {
                q.push(node(x, y, cur.t + 1));
                for (int j = 0; j < 4; j ++) {
                    int aa = a + dx[j], bb = b + dy[j];
                    if (aa >= 0 && aa < n && bb >= 0 && bb < m && g[aa][bb] == 1)
                        g[aa][bb] = 0;
                }
            } else
                q.push(node(a, b, cur.t + 1));
        }
    }
}

// 深度优先搜索做法没有调试成功，应该是需要恢复现场
void dfs1(int x, int y) {
    vis[x][y] = 1;
    // cout << "g[a][b] = 2" << endl;
    for (int i = 0; i < 4; i ++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a > n || b < 0 || b > m || vis[a][b] == 1 || g[a][b] == 1)
            continue;
        // 当迷宫有多种情况时，就需要使用这种枚举法
        if (g[a][b] == 3) {
            res += 1;
            return;
            // cout << "g[a][b] = 3" << endl;
        }
        vis[a][b] = 1;
        if (g[a][b] == 4) {
            res += 3;
            // cout << "g[a][b] = 4" << endl;
        } 
        else if (g[a][b] == 6) {
            res += 1;
            for (int j = 0; j < 4; j ++) {
                int aa = a + dx[j], bb = b + dy[j];
                if (aa >= 0 && aa < n && bb >= 0 && bb < m && g[aa][bb] == 1)
                    g[aa][bb] = 0;
            }
            // cout << "g[a][b] = 6" << endl;
        } else {
            res += 1;
            // cout << "g[a][b] = 0" << endl;
        }
        dfs1(a, b);
    }
}

void dfs2(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i ++) {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 0 && a < n && b <= 0 && b < m && vis[a][b] == 1) {
            if (g[a][b] == 0) {
                res += 1;
            } else if (g[a][b] == 4) {
                res += 3;
            } else if (g[a][b] == 6) {
                res += 1;
                for (int j = 0; j < 4; j ++) {
                    int aa = a + dx[j], bb = b + dy[j];
                    if (aa >= 0 && aa < n && bb >= 0 && bb < m && g[aa][bb] == 1)
                        g[aa][bb] = 0;
                }
            } else
                res += 1;
            dfs2(a, b);
        }
    }
}

void dfs3(int x, int y, int t) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i ++) {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 0 && a < n && b <= 0 && b < m && vis[a][b] == 1) {
            if (g[a][b] == 0) {
                res += 1;
                dfs3(a, b, t + 1);
            } else if (g[a][b] == 4) {
                res += 3;
                dfs3(a, b, t + 3);
            } else if (g[a][b] == 6) {
                res += 1;
                for (int j = 0; j < 4; j ++) {
                    int aa = a + dx[j], bb = b + dy[j];
                    if (aa >= 0 && aa < n && bb >= 0 && bb < m && g[aa][bb] == 1)
                        g[aa][bb] = 0;
                }
                dfs3(a, b, t + 1);
            } else {
                res += 1;
                dfs3(a, b, t + 1);
            }    
        }
    }
}