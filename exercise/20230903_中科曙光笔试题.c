#include <stdio.h>
#include <limits.h>

#define N 20
// 预处理命令后面不要加分号

struct student
{
    char name[N];
    int score;
};

void func(struct student stu[], struct student low[], struct student high[])
{
    // int min_score = stu[0].score, max_score = stu[0].score;
    int min_score = INT_MAX, max_score = INT_MIN; // 需要引入limits.h头文件
    for (int i = 0; i < 11; i++)
    {
        if (stu[i].score < min_score)
        {
            min_score = stu[i].score;
        }
        if (stu[i].score > max_score)
        {
            max_score = stu[i].score;
        }
    }
    printf("min_score = %d, max_score = %d\n", min_score, max_score);

    int low_index = 0, high_index = 0;
    for (int i = 0; i < 11; i ++)
    {
        if (stu[i].score == min_score)
            low[low_index ++] = stu[i]; 
        // 可以进行自定义类型的整体赋值，而不需要对每个结构体成员单独进行赋值
        if (stu[i].score == max_score)
            high[high_index ++] = stu[i];
    }
    for (int i = 0; i < low_index; i ++)
    {
        printf("%s %d\n", low[i].name, low[i].score);
    }
    for (int i = 0; i < high_index; i ++)
    {
        printf("%s %d\n", high[i].name, high[i].score);
    }

    // 最高分和最低分混杂在一起输出 
    // for (int i = 0; i < 11; i ++)
    // {
    //     if (stu[i].score == min_score)
    //     {
    //         printf("%s %d\n", stu[i].name, stu[i].score);
    //         low[low_index ++] = stu[i];
    //     }
    //     if (stu[i].score == max_score)
    //     {
    //         printf("%s %d\n", stu[i].name, stu[i].score);
    //         high[high_index ++] = stu[i];
    //     }
    // }
}

int main()
{
    struct student stu[11] = {{"Tom", 95}, {"Jerry", 90}, {"Micheal", 62}, {"Jack", 70},
                        {"Rose", 60}, {"Bob", 62}, {"Alice", 86}, {"John", 95},
                        {"Lily", 78}, {"Lucy", 83}, {"Mike", 60}};
    // std stu[3] = {{"Tom", 80}, {"Jerry", 90}, {"Micheal", 100}}; // error
    // 对于C语言来说，关键字struct不能省略

    struct student low[11], high[11];
    func(stu, low, high);

    return 0;
}