//日期：20221224
//内容：预处理器方式与关键字typedef方式建立别名的区别
#include <iostream>

using namespace std;

//预处理器方式建立别名，别名在前，类型在后，末尾不加分号
#define dps struct s*

//关键字typedef建立别名，别名在后，类型在前。末尾加分号
typedef struct s *tps; 

//上述两种方式都为指向结构体的指针建立了别名，但是第二种方式更好。同时要注意两种方式在末尾有无分号的区别
//因为预处理器只是将别名进行替换，别不做其他处理，因此当声明一系列变量时这种方法将不适用

struct s
{

};

int main()
{
    dps p1, p2; //--> struct s *p1, p2;
    tps p3, p4; //--> struct s *p3, *p4;
    //最终定义的结果是只有p1、p3、p4是指向结构体的指针，而p2是结构体变量

    return 0;
}