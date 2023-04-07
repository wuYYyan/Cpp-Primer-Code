//日期：20230101
//内容：const、指针、多级指针

//注意，本文件不能编译运行

char **p1; //p1是指向char类型的指针的指针

const char **p2; //p2是指向const char类型的指针的指针

char * const *p3; //p3是指向char类型的常量指针的指针

const char * const *p4; //p4是指向const char类型的常量指针的指针

char ** const p5; //p5是指向char类型的指针的常量指针

const char ** const p6; //p6是指向const char类型的指针的常量指针

char * const * const p7; //p7是指向char类型的常量指针的常量指针

const char * const * const p8; //p8是指向const char类型的常量指针的常量指针

/*总结：
1. const char 与 char const连用意义相同，都表示const char类型
2. 每一组 * const 都表示存在一级常量指针，但不存在 const * 组合
*/
