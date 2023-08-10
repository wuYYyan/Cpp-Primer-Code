// 给你一个mxn的矩阵，矩阵只包含以下元素: 0表示此处为山脉，1表示此处为农田，2表示此处为水源
// 水只能沿着上下左右四个方向流向相邻农田，山脉会阻挡水的流动
// 水从水源流向相邻农田需要花费1天时间，水从农田流向相邻农田也需要花费1天时间
// 返回地图上所有农田都得到灌溉所花费的天数，否则返回-1
// 示例：[[2,0],[1,1]],输出2
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
    public:
        int m, n, res;
        int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

        bool islegal(int x, int y)
        {
            if (x < 0 || x >= m || y < 0 || y >= n) return false;
            return true;
        }

        int irrigateFarmland(vector<vector<int>>& mtx)
        {
            m = mtx.size(), n = mtx[0].size();
            vector<vector<int>> vis(m, vector<int>(n, 0)); //标记数组
            queue<pair<int, int>> q;
            int farmArea = 0;
            int res = -1;
            int temp = 0;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (mtx[i][j] == 2) {
                        // 所有水源入队列
                        q.emplace(i, j); //等价于 q.push(make_pair(i, j)); 或 q.push({i, j});
                        vis[i][j] = 1;
                    }
                    else if (mtx[i][j] == 1) farmArea++;
                    // 统计农田数量，最后要判断是否灌溉所有农田

            while (q.size())
            {
                res ++; //只加一次，表示多处水源可以同时流动
                int len = q.size();
                for (int i = 0; i < len; i++)
                {
                    auto x = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x.first + dir[k][0];
                        int ny = x.second + dir[k][1];
                        if (!islegal(nx, ny) || vis[nx][ny] || mtx[nx][ny] == 0) 
                            continue; //不合法的位置，或是已经访问过的水源位置不回流，或是山脉位置阻挡流动
                        if (mtx[nx][ny] == 1)
                        {
                            vis[nx][ny] = 1; //标记为已访问，表示已经灌溉过
                            q.emplace(nx, ny); //表示水流已经到达这块农田，可以继续流向相邻农田
                            temp++; //统计已经灌溉过的农田数量
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