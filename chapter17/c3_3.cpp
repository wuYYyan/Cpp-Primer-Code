#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    string str = "I love you, 520 Rick! 1314 forever";
    regex reg("\\d+"); // ²éÕÒÊı×Ö
    
    /*
    smatch results;
    bool ret = regex_search(str, results, reg);
    if (ret == true) {
        cout << results.str() << endl;
        cout << results.prefix() << endl;
        cout << results.suffix() << endl;
    }
    */

    sregex_iterator it(str.begin(), str.end(), reg);
    sregex_iterator end_it;
    while (it != end_it) {
        cout << it->str() << endl;
        it ++;
    }

    return 0;
}