#include <iostream>
using namespace std;

int globalVar = 42; // ȫ�ֱ���
static int staticGlobalVar = 21; // ��̬ȫ�ֱ���

void printVars1() {
    cout << "globalVar: " << globalVar << endl;
    cout << "staticGlobalVar: " << staticGlobalVar << endl;
}