#include <iostream>
#include <set>

using namespace std;

struct Foo
{
    int val;
    Foo(int val_) : val(val_) {}

    // bool operator<(const Foo& f) const {
    //     return val < f.val;
    // }

    // bool operator>(const Foo& f) const {
    //     return val > f.val;
    // }
};

// struct Comp
// {
//     bool operator()(const Foo& f1, const Foo& f2) {
//         return f1.val < f2.val;
//     }
// };

bool compare2(const Foo& f1, const Foo& f2) {
    return f1.val < f2.val;
}

int main()
{
    // auto compare1 = [] (const Foo& f1, const Foo& f2) {
    //     return f1.val < f2.val;
    // };
    
    // set<Foo> s;
    // set<Foo, Comp> s; 
    // set<Foo, greater<Foo>> s;
    // set<Foo, decltype(compare1)> s(compare1);
    set<Foo, decltype(compare2)*> s(compare2);
    s.insert(Foo(1024));
    s.insert(Foo(102));
    s.insert(Foo(42));
    for (auto it = s.begin(); it != s.end(); it ++) {
        cout << it->val << " ";
    }
    cout << endl;
    return 0;
}