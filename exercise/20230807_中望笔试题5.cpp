// ����һ��mxn�ľ��󣬾���ֻ��������Ԫ��: 0��ʾ�˴�Ϊɽ����1��ʾ�˴�Ϊũ�2��ʾ�˴�ΪˮԴ
// ˮֻ���������������ĸ�������������ũ�ɽ�����赲ˮ������
// ˮ��ˮԴ��������ũ����Ҫ����1��ʱ�䣬ˮ��ũ����������ũ��Ҳ��Ҫ����1��ʱ��
// ���ص�ͼ������ũ�ﶼ�õ���������ѵ����������򷵻�-1
// ʾ����[[2,0],[1,1]],���2
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
            vector<vector<int>> vis(m, vector<int>(n, 0)); //�������
            queue<pair<int, int>> q;
            int farmArea = 0;
            int res = -1;
            int temp = 0;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (mtx[i][j] == 2) {
                        // ����ˮԴ�����
                        q.emplace(i, j); //�ȼ��� q.push(make_pair(i, j)); �� q.push({i, j});
                        vis[i][j] = 1;
                    }
                    else if (mtx[i][j] == 1) farmArea++;
                    // ͳ��ũ�����������Ҫ�ж��Ƿ�������ũ��

            while (q.size())
            {
                res ++; //ֻ��һ�Σ���ʾ�ദˮԴ����ͬʱ����
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
                            continue; //���Ϸ���λ�ã������Ѿ����ʹ���ˮԴλ�ò�����������ɽ��λ���赲����
                        if (mtx[nx][ny] == 1)
                        {
                            vis[nx][ny] = 1; //���Ϊ�ѷ��ʣ���ʾ�Ѿ���ȹ�
                            q.emplace(nx, ny); //��ʾˮ���Ѿ��������ũ����Լ�����������ũ��
                            temp++; //ͳ���Ѿ���ȹ���ũ������
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