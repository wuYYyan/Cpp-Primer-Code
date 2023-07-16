#include <iostream>
#include <string>

using namespace std;

class Quote
{
    public:
        Quote() = default;
        Quote(const string &book = " ", double sales_price = 0.0) 
            : bookNo(book), price(sales_price) {
                cout << "Quote constructor is running" << endl;
        }
        string isbn() const { return bookNo; }
        virtual double net_price(size_t n) const { return n * price; }
        virtual void debug() const {
            cout << "bookNo: " << bookNo << endl;
            cout << "price: " << price << endl;
        }
        virtual ~Quote() {
            cout << "Quote destructor is running" << endl;
        }
        friend ostream& operator<<(ostream&, const Quote&);
    
    private:
        string bookNo;
    
    protected:
        double price = 0.0;
};

ostream& operator<<(ostream& os, const Quote& bq)
{
    os << "\tUsing operator<< (ostream&, Quote&)" << endl;
    return os;
}

class Bulk_quote : public Quote
{
    public:
        Bulk_quote() = default;
        Bulk_quote(const string &book = " ", double sales_price = 0.0, size_t qty = 0, double disc = 0.0) 
            : Quote(book, sales_price), min_qty(qty), discount(disc) {
                cout << "Bulk_quote constructor is running" << endl;
        }
        double net_price(size_t cnt) const override {
            if (cnt >= min_qty)
                return cnt * (1 - discount) * price;
            else
                return cnt * price;
        }
        ~Bulk_quote() override {
            cout << "Bulk_quote destructor is running" << endl;
        }
        friend ostream& operator<<(ostream&, const Bulk_quote&);
    
    private:
        size_t min_qty = 0;
        double discount = 0.0;
};

ostream& operator<<(ostream& os, const Bulk_quote& bq)
{
    os << "\tUsing operator<< (ostream&, Bulk_quote&)" << endl;
    return os;
}

int main()
{
    Quote base("C++ Primer 5th", 128.0);
    Bulk_quote bulk("Core Python Programming", 89, 5, 0.19);
    
    cout << base << endl;
    cout << bulk << endl;

    return 0;
}