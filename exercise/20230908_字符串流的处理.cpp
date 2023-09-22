#include <iostream>
#include <sstream>
#include <vector>
#include <string>
// #include <bits/stdc++.h> // ����ͷ�ļ�

/*
char op[N];
scanf("%s", op + 1); // %s������\n���������������ָ�룬���ټ�ȡ��ַ��
*/

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool valid(string nums) {

}

string format(string nums) {

}

using namespace std;

int main()
{
    string line, word;
    vector<PersonInfo> people;
    while (getline(cin, line)) {
        PersonInfo info;
        istringstream record(line); // ���ַ������󶨵����ַ�����
        record >> info.name; // ��ʹ��cinһ��ʹ��record
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
        // ����������Ҳ������ȡ�ɿո�ָ�ĵ�����ɵľ���
    }

    for (const auto &entry : people) {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones) {
            if (!valid(nums)) // �ж��ַ�����ʽ�Ƿ���Ч
                badNums << " " << nums; // ��ʹ��coutһ��ʹ��badNums
            else
                formatted << " " << format(nums); // ��ʹ��coutһ��ʹ��formatted
        }
        if (badNums.str().empty())
            cout << entry.name << " " << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << endl;
    }

    return 0;
}