#include <stdio.h>

#define N 20
// Ԥ����������治Ҫ�ӷֺ�

struct std
{
    char name[N];
    int score;
};

int main()
{
    struct std stu1[3] = {{"Tom", 80}, {"Jerry", 90}, {"Micheal", 100}};
    std stu2[3] = {{"Tom", 80}, {"Jerry", 90}, {"Micheal", 100}};
    // ����cpp���ԣ������Զ������͵Ķ�����Ŷ��������ʱ������ʡ��struct�ؼ���
    // ��ȻΪ�˼���C���ԣ�Ҳ���Ա���struct�ؼ���

    return 0;
}