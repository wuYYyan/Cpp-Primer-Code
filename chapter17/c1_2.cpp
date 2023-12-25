#include <iostream>
#include <string>
#include <tuple>

using namespace std;

tuple<int, string> return_tuple() {
    return make_tuple(10, string("tuple"));

}

int main() {
    auto item = return_tuple();
    for (int i = 0; i < get<0>(item); ++ i)
        cout << get<1>(item) << endl;
    return 0;
}