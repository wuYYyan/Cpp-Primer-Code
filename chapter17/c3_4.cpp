#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    /*
    string str = "I love you, 520 Rick! 1314 forever";
    regex reg("\\d+");

    cout << regex_replace(str, reg, "*") << endl; 
    */

    string str = "13812345678"; // 13812345678 -> 138****5678
    regex reg("(\\d{3})\\d{4}(\\d{4})"); // 正则表达式的书写只能边用边查
    cout << regex_replace(str, reg, "$1****$2");

    return 0;
}