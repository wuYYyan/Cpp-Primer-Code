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

class Disc_quote : public Quote
{
    public:
        Disc_quote() = default;
        Disc_quote(const string &book, double sales_price, size_t qty, double disc) 
                    : Quote(book, sales_price),
                    quantity(qty), discount(disc) { }
        virtual double net_price(size_t n) const = 0;
        virtual ~Disc_quote() = default;
    protected:
        size_t quantity = 0;
        double discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
    public:
        Bulk_quote() = default;
        Bulk_quote(const string &book, double p, size_t qty, double disc) : 
                Disc_quote(book, p, qty, disc){ }
        double net_price(size_t cnt) const override
        {
            if (cnt >= quantity)
                return cnt * (1 - discount) * price;
            else
                return cnt * price;
        }
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