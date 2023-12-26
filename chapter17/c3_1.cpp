#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string str;

    cout << "Please input your Email address: ";
    cin >> str;

    regex reg("^\\w([-+.]*\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$");
    // regex_match(str, reg) ? (cout << "Valid Email address" << endl) : (cout << "Invalid Email address, please input again" << endl);
    bool ret = regex_match(str, reg);
    if (ret == true)
        cout << "Valid Email address" << endl;
    else
        cout << "Invalid Email address, please input again" << endl;

    // cout << "Please input your password" << endl;
    // cin >>str;

    // regex reg("^[A-Za-z0-9]+$");
    // bool ret = regex_match(str, reg);
    // if (ret == true)
    //     cout << "Valid password" << endl;
    // else
    //     cout << "Invalid password, please input again" << endl;

    return 0;
}