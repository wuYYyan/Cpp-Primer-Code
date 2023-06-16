#include <iostream>

using namespace std;

class Sales_data
{
    friend istream & operator>>(istream &, Sales_data &);
    friend ostream & operator<<(ostream &, const Sales_data &);
    friend Sales_data operator+(const Sales_data &, const Sales_data &);
    friend Sales_data operator-(const Sales_data &, const Sales_data &);

    public:
        Sales_data & operator+=(const Sales_data &);
        Sales_data & operator-=(const Sales_data &);
    
    private:
        int units_sold;
        int revenue;
};

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sub = rhs;
    sub -= rhs;
    return sub;
}

Sales_data & Sales_data::operator-=(const Sales_data & rhs)
{
    units_sold -= rhs.units_sold;
    revenue -= rhs.revenue;
}

int main()
{
    return 0;
}