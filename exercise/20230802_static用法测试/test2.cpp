#include <iostream>
using namespace std;

extern int globalVar; // ����ȫ�ֱ���
// extern int staticGlobalVar; // ������̬ȫ�ֱ���

void printVars2() {
    cout << "globalVar: " << globalVar << endl;
    // cout << "staticGlobalVar: " << staticGlobalVar << endl;
}