// ���ӣ�https://mp.weixin.qq.com/s/PBXKKCjD2QfDUV45ESPkPg
#include <bits/stdc++.h>

using namespace std;

map<string, int> m;

int idx = 0; // ��Ҫʹ��index��Ϊ��������

void change(string &str) {
    for (int i = 0; i < str.size(); i ++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32; // ��ASCII����У���ͬ��ĸ�Ĵ�Сдƫ��Ϊ32
    // �������ֱ��ʹ�ÿ⺯��toupper����дΪstr[i] = toupper(str[i]);
}

bool check(char c) {
    if (c >= 'A' && c <= 'Z') return true;
    if (c >= 'a' && c <= 'z') return true;
    return false;
}

int main()
{
    string line, word;
    getline(cin, line); // ��ʱgetline��string�⺯������ָ����cin�в������룬���ݴ�ŵ�line��
    // cout << line << endl;
    while ((cin >> word) && (word != "q")) { // ���ر������Ĳ��ԣ�����ֶ����ý�����־�������������֪��ʲôʱ���������
        change(word); // ���ھ����еĵ��ʶԴ�Сд�����У������Ƚ����뵥���б��еĵ���ȫ��ת��Ϊ��д
        // cout << word << endl;
        m[word] = idx; // ���ĳ�������ڵ����б����ظ����֣��µ�����ֵ�Ὣ�ɵ�����ֵ����
        // ͳһ�Դ�д��Ϊ��ϣ���еļ����Ժ��ڽ������еĵ����滻Ϊ��Ӧ�����֮ǰҲҪ��ת��Ϊ��д
        idx ++;
    }
    // ���� Ctrl + C ��������
    string res;
    int beg = 0;
    for (int i = 0; i < line.size(); i ++) {
        if (line[i] == '"') {
            i ++;
            while (i < line.size() && line[i] != '"') // ��˫���Ű����ĵ��ʲ������滻�����������ѭ��
                i ++;
        }
        while (i < line.size() && check(line[i])) // ����ж���Ҫ���������п��ܳ��ֵ���������
            i ++;
        // �������滻Ҫ��ĵ�����ȡ����
        string str = line.substr(beg, i - beg); // �����ַ���line��beg��ʼ��(i - beg)���ַ��Ŀ���
        // cout << str << endl;
        // cout << i << endl;
        beg = i + 1;
        string str_backup = str;
        change(str); // ��Ϊ�ڴ����ϣ��֮ǰȫ����Ϊ�˴�д�����Բ���֮ǰҲҪȫ��ɴ�д�ſ���
        if (m.find(str) != m.end()) // ����ʹ�� if(m[str] != 0) ���жϵ����Ƿ������������б��г��ֹ����������ܻᶪ������Ϊ��ĵ���
            res += to_string(m[str]); // �Ѷ�Ӧ������ֵ����ַ�����ʽ����������ʹ���ַ����ļӷ�
        else
            res += str_backup; // �����滻Ҫ��ĵ��������������б��в������ڣ�����ԭ����ӵ�resĩβ
        res += line[i]; // �ѿ��ܴ��ڵ���������Ҳԭ�������
        // if (i == line.size())
        //     break;
    }
    cout << res << endl;
    return 0;
}