#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 10004;
int a[N], n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++)    
        cin >> a[i];

    int x;
    cin >> x;
    int p = min_element(a, a + n) - a;
    // min_element函数返回的是指针，指向最小值的位置，与指向首元素的指针相减得到下标

    int l = -1, r = -1;
    for (int i = 0; i < n; i ++) {
        int q = (p + i) % n; // 从序号最小值开始遍历，因为有可能会遍历回开头，所以要取模
        if (a[q] == x) {
            // 左端点只需要确定一次，右端点可能需要不断更新
            if (l == -1)
                l = q;
            r = q;
        }
    }
    cout << l << " " << r << endl;

    return 0;
}