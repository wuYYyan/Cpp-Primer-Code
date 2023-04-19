#include <stdio.h>
#include <complex.h>
#include <math.h>

//内容来自数字信号处理导论-机械工业出版社 徐明星著 第五章

double complex DTFT(int L, double *x, double W);
void DTFTR(int L, double *x, int N, complex *X, double wa, double wb);
void DFT(int L, double *x, int N, complex *X);

int main(void) 
{
    return 0;
}

//求已加窗信号x(n)(n = 0, 1, 2, ..., L-1)在频率W处的的DTFT频谱密度值
//形参x是一个指针，指向一个长度为L的double型数组
double complex DTFT(int L, double *x, double W)
{
    complex z, X;

    //这里的I是complex.h中定义的虚数单位
    //z = cexp(cmplx(0, -W)); //z = e^(-jW)
    z = 0 - W * I; //正确的初始化复数z的方法
    //X = cmplx(0, 0);
    X = 0 + 0 * I; //正确的初始化复数X的方法

    int n; //循环计数变量
    for (n = L - 1; n >= 0; n --)
    {
        //X = cadd(cmplx(x[n], 0), cmul(z, X)); //cadd 与 cmul 根本不是库函数
        X = (x[n] + 0 * I) + (z * X); //复数的四则运算方法同实数
    }
    //从循环求解过程来看，加窗序列中的任何一点都会影响该点的频谱密度值

    return X;
}

//频率范围[wa, wb]均匀分布着的N个点的DTFT频谱密度值
//形参x是一个指针，指向一个长度为L的double型数组
//形参X是一个指针，指向一个长度为N的complex型数组
void DTFTR(int L, double *x, int N, complex *X, double wa, double wb)
{
    double dw = (wb - wa) / (N - 1); //在频率范围[wa, wb]均匀分布着的N个点的频率间隔

    int k; //循环计数变量
    for(k = 0; k < N; k ++)
        X[k] = DTFT(L, x, wa + k * dw);
}

//已加窗信号x(n)(n = 0, 1, 2, ..., L-1)的N点DFT定义为
//信号的DTFT在奈奎斯特区间[0, 2 * pi]上N个等间距点处的频谱密度值
void DFT(int L, double *x, int N, complex *X)
{
    double pi = 4 * atan(1.0); //以弧度表示的1的反正切，即π/4，因此最终结果为π

    int k; //循环计数变量
    for(k = 0; k < N; k ++)
        DTFTR(L, x, N, X, 0.0, 2 * pi);
}
