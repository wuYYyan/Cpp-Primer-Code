#include <iostream>

using namespace std;

class Quote
{
    public:
        Quote() = default;
        Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) { }
        string isbn() const { return bookNo; }
        virtual double net_price(size_t n) const { return n * price; }
        virtual ~Quote() = default;
    private:
        string bookNo;
    protected:
        double price = 0.0;
};

class Bulk_quote : public Quote
{
    public:
        Bulk_quote() = default;
        Bulk_quote(const string &book, double p, size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) { }
        double net_price(size_t cnt) const override
        {
            if (cnt >= min_qty)
                return cnt * (1 - discount) * price;
            else
                return cnt * price;
        }
    private:
        size_t min_qty = 0;
        double discount = 0.0;
};

class Limited_quote : public Quote
{
    public:
        double net_price(size_t cnt) const override
        {
            if (cnt <= min_qty)
                return cnt * (1 - discount) * price;
            else
                return min_qty * (1 - discount) * price + (cnt - min_qty) * price;
        }
    private:
        size_t min_qty = 0;
        double discount = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n);

int main()
{
    Quote q("123", 10);
    Bulk_quote bq("123", 10, 10, 0.1);

    print_total(cout, q, 20);
    print_total(cout, bq, 20);
    
    return 0;
}

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() 
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}