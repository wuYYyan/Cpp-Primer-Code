#include <iostream>

using namespace std;

class node
{
    public:
        // �û���ʽ�ṩ���캯�������ڳ�ʼ���б��г�ʼ�����ó�Ա����
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

