#include <iostream>
#include <vector>

using namespace std;

void split_odd_even(const vector<int> &arr, vector<int> &odd_ref, vector<int> &even_ref);

int main() {
    vector<int> arr {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> odd;
    vector<int> even;

    split_odd_even(arr, odd, even);
    
    for (int i = 0; i < odd.size(); i ++)
        cout << odd[i] << " ";
    cout << endl;
    for (int i = 0; i < even.size(); i ++)
        cout << even[i] << " ";
    cout << endl;

    return 0;
}

// 使用容器，省去了手动开辟内存空间，更加方便
void split_odd_even(const vector<int> &arr, vector<int> &odd_ref, vector<int> &even_ref) {
    for (int i = 0; i < arr.size(); i ++) {
        if (arr[i] % 2 == 0) {
            even_ref.push_back(arr[i]);
        } else {
            odd_ref.push_back(arr[i]);
        }
    }
}