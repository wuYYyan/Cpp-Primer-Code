#include "Sales_data.h"
#include <iostream>

Sales_data::Sales_data(istream &is)
{
    read(is, *this); //调用友元函数
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}

double Sales_data::avg_price() const
{
    if(units_sold)
        return revenue / units_sold;
    else
        return 0;
}

//友元函数只在声明时使用关键字friend，函数具体定义时不使用
ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price(); 

    return os;
}

istream &read(istream &is, Sales_data &item)
{
    is >> item.bookNo >> item.units_sold >> item.price;
    item.revenue = item.units_sold * item.price;
    return is;
}