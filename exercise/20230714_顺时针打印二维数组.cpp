#include <iostream>
#include <vector>

using namespace std;

void printV(vector<vector<int>>& v);

int main()
{
    vector<vector<int>> v = {{1, 2, 3, 4, 5},
                             {6, 7, 8, 9, 10},
                             {11, 12, 13, 14, 15},
                             {16, 17, 18, 19, 20},
                             {21, 22, 23, 24, 25}};

    printV(v);

    return 0;
}

void printV(vector<vector<int>>& v)
{
    int m = v.size();
    if (!m) return; //一定要先判断这一步，再求列数时，如果m为0，会出现异常
    int n = v[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    int dx[4] = {0, 1, 0, -1}; // x轴方向
    int dy[4] = {1, 0, -1, 0}; // y轴方向

    for (int i = 0, x = 0, y = 0, d = 0; i < m * n; i++)
    {
        cout << v[x][y] << " ";
        visited[x][y] = true;
        int a = x + dx[d], b = y + dy[d];
        if (a < 0 || a >= m || b < 0 || b >= n || visited[a][b])
        {
            d = (d + 1) % 4;
            a = x + dx[d], b = y + dy[d];
        }
        x = a, y = b;
    }
}