#include <iostream>
using namespace std;

extern int globalVar; // ����ȫ�ֱ���
// extern int staticGlobalVar; // ������̬ȫ�ֱ���������ʱ�ᱨ��û�ж����ָ��

void printVars2() {
    cout << "globalVar: " << globalVar << endl;
    // cout << "staticGlobalVar: " << staticGlobalVar << endl;
}