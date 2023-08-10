#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
    public:
        int m, n;
        int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
        bool isLegal(int x, int y)
        {
            if (x < 0 || x >= m || y < 0 || y >= n) return false;
            return true;
        }
        int irrigateFarmland(vector<vector<int>>& map)
        {
            m = map.size(), n = map[0].size();
            vector<vector<bool>> vis(m, vector<bool>(n, false));
            queue<pair<int, int>> q;
            int res = -1;
            int farmArea = 0;
            int temp = 0;
            for (int i = 0; i < m; i ++)
                for (int j = 0; j < n; j ++)
                    if (map[i][j] == 2) {
                        q.push({i, j});
                        vis[i][j] = true;
                    } else if (map[i][j] == 1) {
                        farmArea ++;
                    }
            while (q.size()) {
                res ++;
                int len = q.size();
                for (int i = 0; i < len; i ++) {
                    auto x = q.front();
                    q.pop();
                    for (int i = 0; i < 4 ; i ++) {
                        int a = x.first + dir[i][0], b = x.second + dir[i][1];
                        if (!isLegal(a, b) || vis[a][b] || map[a][b] == 0) continue;
                        if (map[a][b] == 1) {
                            vis[a][b] = true;
                            q.push({a, b});
                            temp ++;
                        }
                    }
                }
            }
            return temp == farmArea ? res : -1;
        }
};

int main()
{
    vector<vector<int>> map = {{2, 0}, {1, 1}};
    Solution s;
    cout << s.irrigateFarmland(map) << endl;
    return 0;
}