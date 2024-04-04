#include <stdio.h>

struct student1{
    char no[20];    //学号
    char name[20];  //姓名
    char sex[5];    //性别
    int age;        //年龄
}; // 先定义结构体类型，然后在main函数中定义结构体变量

struct student2{
    char no[20];    //学号
    char name[20];  //姓名
    char sex[5];    //性别
    int age;        //年龄
} stu2_1, stu2_2; // 在定义结构体类型的同时定义结构体变量

struct{
    char no[20];    //学号
    char name[20];  //姓名
    char sex[5];    //性别
    int age;        //年龄
} stu3_1, stu3_2;   // 不定义结构类型，只定义结构体变量
// 以后无法再定义类似的结构体变量了，因为不存在结构体类型名

typedef struct student4{
	char no[20];    //学号
    char name[20];  //姓名
    char sex[5];    //性别
    int age;        //年龄
}STUDENT4; // 使用typedef定义结构体类型

int main() {
    printf("Hello World!\n");

    struct student1 stu1_1, stu2_2;
    // 此时stu1,stu2为student结构体变量

    STUDENT4 stu4_1 = {.no = "20240404", .name = "wuyan", .sex = "male", .age = 20}; // 只能在初始化的时候使用这种方式

    // STUDENT4 stu4_1; // 使用typedef定义的结构体类型
    // stu4_1 = {.no = "20240404", .name = "wuyan", .sex = "male", .age = 20};
    // 指定初始化器（designated initializer）只能在初始化时使用，不能在赋值时使用
    // 所以上面两行会在编译时报错

    return 0;
}