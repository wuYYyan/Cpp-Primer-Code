#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> alloc_mem();
void read_num(shared_ptr<vector<int>> pt);
void print_num(shared_ptr<vector<int>> pt);

int main()
{
    shared_ptr<vector<int>> pt = alloc_mem();
    read_num(pt);
    print_num(pt);
    return 0;
}

shared_ptr<vector<int>> alloc_mem()
{
    return make_shared<vector<int>>();
}

void read_num(shared_ptr<vector<int>> pt)
{
    int num;
    while (cin >> num)
        pt->push_back(num);
}

void print_num(shared_ptr<vector<int>> pt)
{
    for (const auto &r : *pt)
        cout << r << " ";
    cout << endl;
}