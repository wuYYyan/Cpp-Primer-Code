// ���ӣ�https://mp.weixin.qq.com/s/PBXKKCjD2QfDUV45ESPkPg
#include <bits/stdc++.h>

using namespace std;

const int N = 30;

struct node {
    int x, y, t;
    node() { } // һ������£�ֻҪ�ṩ�˺��ι��캯����Ҫ�ֶ��ṩһ��Ĭ�Ϲ��캯��
    node(int x_, int y_, int t_) : x(x_), y(y_), t(t_) {}
    bool operator<(const node &a) const {
        return t > a.t; // ����Ϊtrue˵��ǰ�ߵ����ȼ��ϸߣ������ȶ��������ȼ��ϸߵ�Ԫ�ػ��³�
    }
    // �Ƚ���������غ������붨��Ϊconst��Ա����������ᱨ��
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
            // �����������漰�������ĵ��ã��չ黹��˳��ִ��
            // ���Կ���һ�߶�ȡһ�������
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
            } else // g[x][y] == 0 �����������ֱ���ߵ���һ��·��
                q.push(node(x, y, cur.t + 1));
        }
        if (res) // ֻ�������յ�Ż����res�����Ե���������ʱ���Ѿ������յ㲻������
            break;
    }
    cout << res << endl;
    return 0;
}