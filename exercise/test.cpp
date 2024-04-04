#include <iostream>

using namespace std;

int func1(int x) {
    int cnt = 0;
    while (x) {
        cnt ++;
        x = x & (x - 1);
    }
    return cnt;
}

int func2(int x) {
    int cnt = 0;
    while (x) {
        int k = x & 1;
        if (k == 1)
            cnt ++;
        x = x >> 1;
    }
    return cnt;
}

int main() {
    int num;
    cin >> num;

    return 0;
}