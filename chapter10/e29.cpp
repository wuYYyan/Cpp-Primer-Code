#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream ifile(argv[1]);
    if (!ifile) {
        cerr << "Can't open file " << argv[1] << endl; 
        return -1;
    }

    istream_iterator<string> if_it(ifile), eof;
    //vector<string> vec(if_it, eof);
    vector<string> vec;
    while(if_it != eof)
        vec.push_back(*if_it++);

    for(const auto &r : vec)
        cout << r << " ";
    cout << endl;

    return 0;
}