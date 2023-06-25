#include <iostream>

using namespace std;

class nf 
{
    public:
        nf();
        ~nf();
    public:
        int * get();
        void set(int i);
    private:
        int * pi;
};

nf::nf()
{
       cout << "nf construction" << endl;
       pi = new int(0);
}

nf::~nf()
{
       cout << "nf destruction" << endl;
       delete pi;
}

int * nf::get()
{
           return pi;
}

void nf::set(int i)
{
        *pi = i;
}

int main()
{
    nf* pnf = new nf();
    pnf->set(100);
    int *pp = pnf->get();
    cout << *pp << endl;
    //delete pnf;
    free(pnf);
    cout << *pp << endl;
    return 0;
}

/*
1) : new运算符执行分配内存、构造对象，delete执行析构对象、释放内存两步
2) : 而如果用free释放delete开辟的内存，只会释放内存而不会析构对象 
    在构造函数里面申请的内存因为没有调用析构函数，所以该内存并没有被释放
*/