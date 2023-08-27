#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    // ������ umap ����
    unordered_map<string, string> umap;
   
    cout << "umap ��ʼͰ��: " << umap.bucket_count() << endl;
    cout << "umap ��ʼ��������: " << umap.load_factor() << endl;
    cout << "umap ���������: " << umap.max_load_factor() << endl;

    // ���� umap ʹ�����ʺϴ洢9����ֵ�Ե�Ͱ����ʹ��umap���Ա���9��Ԫ�ض�����rehash
    umap.reserve(9);
    cout << "*********************" << endl;
    cout << "umap ��Ͱ��: " << umap.bucket_count() << endl;
    cout << "umap �¸�������: " << umap.load_factor() << endl;

    // �� umap ������� 3 ����ֵ��
    umap["Python�̳�"] = "http://c.biancheng.net/python/";
    umap["Java�̳�"] = "http://c.biancheng.net/java/";
    umap["Linux�̳�"] = "http://c.biancheng.net/linux/";

    // ���� bucket() ��ȡָ����ֵ��λ��Ͱ�ı��
    cout << "��\"Python�̳�\"Ϊ���ļ�ֵ�ԣ�λ��Ͱ�ı��Ϊ: " << umap.bucket("Python�̳�") << endl;

    // ���м���ĳ��ֵ��λ���ĸ�Ͱ����ϣֵ����Ͱ��ȡ��
    auto fn = umap.hash_function();
    cout << "������\"Python�̳�\"Ϊ���ļ�ֵ�ԣ�λ��Ͱ�ı��Ϊ��" << fn("Python�̳�") % (umap.bucket_count()) << endl;

    return 0;
}