#include <iostream>
using namespace std;

extern int globalVar; // 声明全局变量
// extern int staticGlobalVar; // 声明静态全局变量，链接时会报错：没有定义的指向

void printVars2() {
    cout << "globalVar: " << globalVar << endl;
    // cout << "staticGlobalVar: " << staticGlobalVar << endl;
}