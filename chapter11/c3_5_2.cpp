#include <iostream>
#include <map>

using namespace std;

int main()
{
    multimap<string, string> authors;
    auto pos = authors.equal_range("str");

    return 0;
}