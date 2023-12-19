#include <iostream>
#include <memory>

using namespace std;

void close(FILE *fp) {
    if (fp == nullptr)
        return;
    else
        fclose(fp);

    cout << "close file" << endl; // ������֤ɾ�����Ƿ�ִ��
}

int main() {
    FILE *fp = fopen("word.txt", "w"); // ��ֻ����ʽ���ļ�
    shared_ptr<FILE> file_ptr(fp, close); // ��shared_ptr����fp, ��ָ��ɾ����Ϊ����close()
    // ����ָ������ļ�ָ��fp��������ָ������ʱ�����Զ����ú���close()
}