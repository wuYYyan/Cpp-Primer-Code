#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val_) : val(val_), next(nullptr) {}
    ListNode(int val_, ListNode *next_) : val(val_), next(next_) {}
};

int main() {
    cout << "hello world!" << endl;
    return 0;
}