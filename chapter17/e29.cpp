#include <iostream>
#include <random>

using namespace std;

unsigned int make_rand(unsigned int seek = 32767) {
    static default_random_engine e(seek);
    static uniform_int_distribution<unsigned int> u(0, 100);
    return u(e);

}

int main() {
    for (size_t i = 0; i < 10; ++ i)
        cout << make_rand() <<" ";
    cout << endl;
    for (size_t i = 0; i < 10; ++ i)
        cout << make_rand(i) <<" ";
    cout << endl;
    return 0;
}