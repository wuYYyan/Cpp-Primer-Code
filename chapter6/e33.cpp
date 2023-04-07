#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> vint, int index);

int main(void)
{
    vector<int> vi = {1, 2, 3, 4, 5};
    print(vi, 0);

    return 0;
}

void print(vector<int> vint, int index)
{
    //必须设置终止条件
    if(index < vint.size())
    {
        cout << vint[index] << endl;
        print(vint, index + 1);
    } 
}