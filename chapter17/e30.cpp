#include <iostream>
#include <random>

using namespace std;

unsigned int make_rand(unsigned int seek = 32767, int min = 0, int max = 100) {
    static default_random_engine e(seek);
    static uniform_int_distribution<unsigned int> u(min, max); // 在指定范围内生成随机整数
    return u(e);

}

int main() {
    for (size_t i = 0; i < 10; ++ i)
        cout << make_rand(i, 0, 10000) <<" ";
    cout << endl;
    return 0;
}