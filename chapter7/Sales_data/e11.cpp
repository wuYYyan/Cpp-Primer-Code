#include <iostream>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data item1;
    print(cout, item1) << endl;

    Sales_data item2("11-22-33-44-55");
    print(cout, item2) << endl;

    Sales_data item3("66-77-88-99-00",10, 12.5);
    print(cout, item3) << endl;

    Sales_data item4(cin);
    print(cout, item4) << endl;

    return 0;
}