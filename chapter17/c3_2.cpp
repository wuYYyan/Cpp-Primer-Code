#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    string str = "I love you, 520 Rick!";
    regex reg("\\d+");

    smatch results;
    bool ret = regex_search(str, results, reg);
    if (ret == true) {
        cout << results.str() << endl;
        cout << results.prefix() << endl;
        cout << results.suffix() << endl;
    }

    return 0;
}