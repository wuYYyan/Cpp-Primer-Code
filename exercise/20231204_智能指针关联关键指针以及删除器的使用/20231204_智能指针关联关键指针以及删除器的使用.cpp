#include <iostream>
#include <memory>

using namespace std;

void close(FILE *fp) {
    if (fp == nullptr)
        return;
    else
        fclose(fp);

    cout << "close file" << endl; // 用于验证删除器是否执行
}

int main() {
    FILE *fp = fopen("word.txt", "w"); // 以只读方式打开文件
    shared_ptr<FILE> file_ptr(fp, close); // 用shared_ptr管理fp, 并指定删除器为函数close()
    // 智能指针关联文件指针fp，当智能指针销毁时，会自动调用函数close()
}