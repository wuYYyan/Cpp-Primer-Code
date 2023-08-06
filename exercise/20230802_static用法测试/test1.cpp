#include <iostream>
using namespace std;

int globalVar = 42; // 全局变量
static int staticGlobalVar = 21; // 静态全局变量

void printVars1() {
    cout << "globalVar: " << globalVar << endl;
    cout << "staticGlobalVar: " << staticGlobalVar << endl;
}