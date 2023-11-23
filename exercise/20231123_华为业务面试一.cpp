#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    vector<int> res(n, 0);
    stack<int> stk;
    for (int i = n - 1; i >= 0; i --) {
        while (stk.size() && T[stk.top()] <= T[i]) stk.pop();
        if (stk.size()) res[i] = stk.top() - i;
        stk.push(i);
    }
    return res;
}

int main() {
    vector<int> T = {73,74,75,71,69,72,76,73};
    vector<int> res = dailyTemperatures(T);
    for (auto it = res.begin(); it != res.end(); it ++)
        cout << *it << " ";
    cout << endl;
    return 0;
}