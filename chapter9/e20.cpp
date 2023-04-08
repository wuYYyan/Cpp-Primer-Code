#include <list>
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    list<int> il = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    deque<int> odd_id, even_id;

    for(const auto &r : il)
    {
        if(r % 2 == 0)
            even_id.push_back(r);
        else
            odd_id.push_back(r);
    }

    cout << "Odd_deque: ";
    for(const auto &r : odd_id)
        cout << r << " ";
    cout << endl;

    cout << "Even_deque: ";
    for(const auto &r : even_id)
        cout << r << " ";
    cout << endl;


    return 0;
}