#include <stdio.h>

void fun(int i, int j);
typedef void (*p_fun)(int i, int j);
struct st {
    int i;
    int j;
    int k;
    p_fun pfun;
};

int main() {
  	struct st st_ = {0};
    st_.i = 1;
    st_.j = 2;
	st_.pfun = fun;
    st_.pfun(1, 2);
    printf("%p, %p\n", st_.pfun, &st_.pfun);

    struct st *pst_;
    pst_ = &st_;
    printf("%d, %d\n", pst_->i, pst_->j);

    int *pint = (int *)pst_;
    printf("1) %d, %p\n", *pint, pint);
	// *pint = 1;
    pint += 1; // ָ��ļӷ�������ָ�����͵��ֽڴ�С���
    printf("2) %d, %p\n", *pint, pint);
	// *pint = 2;
    pint += 1;
    *pint = 3;
    printf("3) %d, %p\n", *pint, pint);
    pint += 1;
    printf("4) %d, %p\n", *pint, pint);
    pint += 1; // ��Ϊ�ṹ���ڴ��������⣬����ָ����Ҫ��4�β���ָ����
    printf("5) %X, %p\n", *pint, pint);
    // printf("5) %X, %p, %p\n", *pint, pint, *(long *)pint); // ���Ծ���

    p_fun p = *(p_fun *)pint;
    p = fun;
    p(10, 20);

    // printf("%d", sizeof(st_)); // ���Ծ���
    
    return 0;
}

void fun(int i, int j) {
    printf("This is the function parameter: %d, %d\n", i, j);
}