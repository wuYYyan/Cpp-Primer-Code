#include <iostream>
#include <vector>

using namespace std;

vector<int> *alloc_mem();
void read_num(vector<int> *pt);
void print_num(vector<int> *pt);

int main()
{
    vector<int> *pt = alloc_mem();
    read_num(pt);
    print_num(pt);

    delete pt;
    pt = nullptr;

    return 0;
}

vector<int> *alloc_mem()
{
    return new vector<int>;
}

void read_num(vector<int> *pt)
{
    int num;
    while (cin >> num)
        pt->push_back(num);
}

void print_num(vector<int> *pt)
{
    for (const auto &r : *pt)
        cout << r << " ";
    cout << endl;
}