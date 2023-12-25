#include <iostream>
#include <bitset>

using namespace std;

int main() {
    unsigned long long n = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 5) | (1 << 8) | (1 << 13) | (1 << 21);
    bitset<32> bt(n);
    cout << bt << endl;
    return 0;
}