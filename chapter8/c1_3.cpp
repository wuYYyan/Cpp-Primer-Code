#include <iostream>
#include <fstream>

using namespace std;

//cin <---> ofstream
int main()
{
    ofstream ofs;
    ofs.open("c1_3.txt");
    cin.tie(&ofs);

    char c;
    while(cin >> c)
        ofs << c;

    ofs.close();

    return 0;
}