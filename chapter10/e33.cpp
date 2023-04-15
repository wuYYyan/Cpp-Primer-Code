#include <iterator>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    ofstream out1(argv[2]);
    ofstream out2(argv[3]);

    istream_iterator<int> in_iter(in), eof;
    ostream_iterator<int> out1_iter(out1, " ");
    ostream_iterator<int> out2_iter(out2, "\n");

    while(in_iter != eof)
        if (*in_iter % 2)
            *out1_iter++ = *in_iter++;
        else
            *out2_iter++ = *in_iter++;

    return 0;
}