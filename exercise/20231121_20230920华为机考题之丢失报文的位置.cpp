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
    // min_element�������ص���ָ�룬ָ����Сֵ��λ�ã���ָ����Ԫ�ص�ָ������õ��±�

    int l = -1, r = -1;
    for (int i = 0; i < n; i ++) {
        int q = (p + i) % n; // �������Сֵ��ʼ��������Ϊ�п��ܻ�����ؿ�ͷ������Ҫȡģ
        if (a[q] == x) {
            // ��˵�ֻ��Ҫȷ��һ�Σ��Ҷ˵������Ҫ���ϸ���
            if (l == -1)
                l = q;
            r = q;
        }
    }
    cout << l << " " << r << endl;

    return 0;
}