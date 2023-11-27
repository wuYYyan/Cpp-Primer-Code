#include <iostream>
#include <vector>

using namespace std;

struct Odd_Even {
    vector<int> odd;
    vector<int> even;
};

Odd_Even split_odd_even(const vector<int> &arr);

int main() {
    vector<int> arr {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> odd;
    vector<int> even;

    Odd_Even odd_even;
    odd_even = split_odd_even(arr);
    
    for (int i = 0; i < odd_even.odd.size(); i ++)
        cout << odd_even.odd[i] << " ";
    cout << endl;
    for (int i = 0; i < odd_even.even.size(); i ++)
        cout << odd_even.even[i] << " ";
    cout << endl;

    return 0;
}

// 使用容器，省去了手动开辟内存空间，更加方便
Odd_Even split_odd_even(const vector<int> &arr) {
    Odd_Even res;
    for (int i = 0; i < arr.size(); i ++) {
        if (arr[i] % 2 == 0) {
            res.even.push_back(arr[i]);
        } else {
            res.odd.push_back(arr[i]);
        }
    }
    return res;
}