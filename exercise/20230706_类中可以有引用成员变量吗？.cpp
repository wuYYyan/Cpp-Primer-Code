#include <iostream>

using namespace std;

class node
{
    public:
        // 用户显式提供构造函数，且在初始化列表中初始化引用成员变量
        node(int &target) : st(target)
        {
            cout << "hello" << endl;
        }
        void Print()
        {
            cout << st << endl;
        }
    private:
        int &st;
};

int main()
{
	int op = 123;
	node bk(op);
	bk.Print();
    
	return 0;
}

