// �ο����ӣ�https://ujimatsu-chiya.github.io/EXAM/Huawei-20230920/
#include <bits/stdc++.h>

#define pi pair<int, int>

using namespace std;

typedef long long ll;
const int N = 44;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; // ��������
int s[N][N], d[N][N]; // ��ά����s��ʾĳ��λ��������ͬѧ����Ůͬѧ
// ��ά����d��ʾ����ĳ��λ�������ʱ��

int main() {
    int n, m;
    cin >> n >> m;
    memset(d, -1, sizeof(d));
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            cin >> s[N][N];
            assert(s[i][j] == 1 || s[i][j] == 0);
        }
    queue<pi> q;
    for (int i = 1; i <= n; i ++)
        if (s[i][1] == 1) {
            d[i][1] = 0;
            q.push({i, 1}); // ��ԴBFS�����Խ�����������������������
        }
    while (q.size()) {
        auto [sx, sy] = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int x = sx + dx[i], y = sy + dy[i];
            if (x < 1 || x > n || y < 1 || y > m || s[x][y] == 0 || d[x][y] != -1)
                continue;
            d[x][y] = d[sx][sy] + 1;
            q.push({x, y});
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i ++)
        if (s[i][m] == 1 && d[i][m] != -1)
            ans = min(ans, d[i][m]);
    if (ans == 1e9)
        ans = -1;
    cout << ans << endl;
    return 0;
}