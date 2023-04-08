#include <iostream>
#include <fstream> 

using namespace std;

int main()
{
    //ofstream ofs("c2_2.txt", fstream::out); //以out形式打开文件会丢弃已有数据
    ofstream ofs("c2_2.txt", fstream::out | fstream::app); //模式为输出和追加

    return 0;
} 