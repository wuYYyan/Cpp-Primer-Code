#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<int>::iterator search_vector(vector<int>::iterator beg, vector<int>::iterator ed, int val);

int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << search_vector(ivec.begin(), ivec.end(), 100) - ivec.begin() << endl;
    cout << search_vector(ivec.begin(), ivec.end(), 5) - ivec.begin()<< endl;
    return 0;
}

vector<int>::iterator search_vector(vector<int>::iterator beg, vector<int>::iterator ed, int val)
{
    while(beg != ed)
    {
        if(*beg == val)
            return beg;
        beg++;
    }
    return ed;
}