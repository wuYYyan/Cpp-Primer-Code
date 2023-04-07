#include <iostream>
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
        Sales_data(const string &s, unsigned int n, double p) : bookNo(s), units_sold(n), price(p) {revenue = p * n; cout << "1) Hello World" << endl;}
        
        Sales_data() : Sales_data("11-22-33-44-55", 100, 10.5) {cout << "2) Good Morning" << endl;} //Sales_data() = default;
        Sales_data(const string &s) : Sales_data("66-77-88-99-00", 0, 20.5) {cout << "3) I love you" << endl;}
        Sales_data(istream &is) : Sales_data() {cout << "4) Heal The World" << endl; read(is, *this);}
        
        friend istream &read(istream &is, Sales_data &item);
};

istream &read(istream &is, Sales_data &item)
{
    is >> item.bookNo >> item.units_sold >> item.price;
    item.revenue = item.units_sold * item.price;
    return is;
}

int main()
{
    Sales_data s1; //先完整执行受委托构造函数，再执行委托构造函数
    Sales_data s2("AA-BB-CC-DD-EE");
    Sales_data s3(cin);

    return 0;
}
 