#include <iostream>
#include <memory>
#include <set>

using namespace std;

class Quote
{
    public:
        Quote() = default;
        Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) { }
        string isbn() const { return bookNo; }
        virtual double net_price(size_t n) const { return n * price; }
        virtual Quote* clone() const & { return new Quote(*this); }
        virtual Quote* clone() && { return new Quote(std::move(*this)); }
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
        Bulk_quote(const string &book, double p, size_t qty, double disc) : 
                Quote(book, p), quantity(qty), discount(disc) { }
        double net_price(size_t cnt) const override
        {
            if (cnt >= quantity)
                return cnt * (1 - discount) * price;
            else
                return cnt * price;
        }
        Bulk_quote* clone() const & override { return new Bulk_quote(*this); }
        Bulk_quote* clone() && override { return new Bulk_quote(std::move(*this)); }
    private:
        size_t quantity = 0;
        double discount = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() 
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

class Basket
{
    public:
        // void add_item(const shared_ptr<Quote> &sale) { items.insert(sale); }
        void add_item(const Quote& sale) { items.insert(shared_ptr<Quote>(sale.clone())); }
        void add_item(Quote&& sale) { items.insert(shared_ptr<Quote>(std::move(sale).clone())); }
        double total_receipt(ostream&) const;
    private:
        static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs)
        {
            return lhs->isbn() < rhs->isbn();
        }
        multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0;
    // c.upper_bound(v) 返回一个迭代器，指向第一个关键字大于v的元素
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
    {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << endl;
    return sum;
}

int main()
{
    
    return 0;
}

