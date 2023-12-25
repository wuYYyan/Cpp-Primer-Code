#include <iostream>
#include <bitset>

using namespace std;

void change_bitset(bitset<10> &bt, int pos, bool val) {
    bt.set(pos, val);
}

int main() {
    bitset<10> bt;
    cout << bt << endl;

    change_bitset(bt, 1, 1);
    change_bitset(bt, 5, 1);
    cout << bt << endl;

    return 0;
}