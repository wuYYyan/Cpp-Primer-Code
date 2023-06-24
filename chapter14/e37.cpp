#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Comp
{
    private:
        int a;
    public:
        Comp(int n_ = 0) : a(n_) { }
        bool operator()(int b) {
            return a == b;
        }
};

int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    replace_if(ivec.begin(), ivec.end(), Comp(2), 222);

    for (const auto &r : ivec)
        std::cout << r << ' ';
    std::cout << endl;

    return 0;
}