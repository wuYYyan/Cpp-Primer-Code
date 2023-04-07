#include <iostream>
#include <initializer_list>

using namespace std;

int sum(initializer_list<int> i);

int main()
{
    cout << "Add 1, 2, 3 all together: " << sum({1, 2, 3}) << endl;
    cout << "Add 1, 2, 3, 4, 5, 6 all together: " << sum({1, 2, 3, 4, 5, 6}) << endl;

    return 0;
}

int sum(initializer_list<int> i)
{
    int sum = 0;

    for(const auto &val : i)
    {
        sum += val;
        //val *= 2; //列表中的每个元素都是const
    }
        
    return sum;
}