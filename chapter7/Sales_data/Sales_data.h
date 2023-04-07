#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

#include <string>

using namespace std;

class Sales_data
{
    private:
        string bookNo;
        unsigned int units_sold = 0;
        double price = 0.0;
        double revenue = 0.0;
    public:
        Sales_data() {} //Sales_data() = default;
        Sales_data(const string &s) : bookNo(s) {}
        Sales_data(const string &s, unsigned int n, double p) : bookNo(s), units_sold(n), price(p) {revenue = p * n;}
        Sales_data(istream &is);

        string isbn() const {return bookNo;}
        Sales_data &combine(const Sales_data &rhs);
        double avg_price() const;
        
        friend ostream &print(ostream &os, const Sales_data &item);
        friend istream &read(istream &is, Sales_data &item);
};

#endif
 