#include <stdio.h>

struct student1{
    char no[20];    //ѧ��
    char name[20];  //����
    char sex[5];    //�Ա�
    int age;        //����
}; // �ȶ���ṹ�����ͣ�Ȼ����main�����ж���ṹ�����

struct student2{
    char no[20];    //ѧ��
    char name[20];  //����
    char sex[5];    //�Ա�
    int age;        //����
} stu2_1, stu2_2; // �ڶ���ṹ�����͵�ͬʱ����ṹ�����

struct{
    char no[20];    //ѧ��
    char name[20];  //����
    char sex[5];    //�Ա�
    int age;        //����
} stu3_1, stu3_2;   // ������ṹ���ͣ�ֻ����ṹ�����
// �Ժ��޷��ٶ������ƵĽṹ������ˣ���Ϊ�����ڽṹ��������

typedef struct student4{
	char no[20];    //ѧ��
    char name[20];  //����
    char sex[5];    //�Ա�
    int age;        //����
}STUDENT4; // ʹ��typedef����ṹ������

int main() {
    printf("Hello World!\n");

    struct student1 stu1_1, stu2_2;
    // ��ʱstu1,stu2Ϊstudent�ṹ�����

    STUDENT4 stu4_1 = {.no = "20240404", .name = "wuyan", .sex = "male", .age = 20}; // ֻ���ڳ�ʼ����ʱ��ʹ�����ַ�ʽ

    // STUDENT4 stu4_1; // ʹ��typedef����Ľṹ������
    // stu4_1 = {.no = "20240404", .name = "wuyan", .sex = "male", .age = 20};
    // ָ����ʼ������designated initializer��ֻ���ڳ�ʼ��ʱʹ�ã������ڸ�ֵʱʹ��
    // �����������л��ڱ���ʱ����

    return 0;
}