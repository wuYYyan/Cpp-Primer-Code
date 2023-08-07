#include <iostream> 

using namespace std;

class Base
{
    public:
        inline virtual void who()
        {
                cout << "I am Base\n";
        }
        virtual ~Base() {}
};

class Derived : public Base
{
    public:
        inline virtual void who()  //��дinlineʱ��ʽ����
        {
                cout << "I am Derived\n";
        }
};

int main()
{
   // �˴����麯�� who()����ͨ����Base�ľ�����������õ�
   // �����ڼ����ȷ���ˣ������������������ģ��������Ƿ�����ȡ���ڱ�����
   Base b;
   b.who();

   // �˴����麯����ͨ��ָ����õģ����ֶ�̬�ԣ���Ҫ������ʱ�ڼ����ȷ����
   // ���Բ���Ϊ����  
   Base *ptr = new Derived();
   ptr->who();

   // ��ΪBase������������ (virtual ~Base() {})
   // ���� delete ʱ�����ȵ��������ࣨDerived����������
   // �ٵ��û��ࣨBase��������������ֹ�ڴ�й©
   delete ptr;
   ptr = nullptr;

   system("pause");
   return 0;
} 
