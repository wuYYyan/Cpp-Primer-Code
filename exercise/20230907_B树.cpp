#include <iostream>

using namespace std;

class BTreeNode
{
private:
    int *keys; // �洢���ڵ������ؼ��ֵ�����
    int t;     // ��С����
    BTreeNode **C; // �洢���ӽڵ�ָ������飬
    int n;     // ���ڵ������ؼ��ֵĸ���
    bool leaf; // �Ƿ�ΪҶ�ӽڵ�

public:
    BTreeNode(int _t, bool _leaf)
    {
        t = _t;
        leaf = _leaf;
        keys = new int[2 * t - 1]; // �����԰���2t-1���ؼ���
        C = new BTreeNode *[2 * t];
        n = 0;
    }
    void traverse();
    BTreeNode *search(int k); // ��������ڣ��򷵻�NULL
    friend class BTree; // ��Ԫ�࣬���Է���BTreeNode��˽�г�Ա
};

class BTree
{
private:
    BTreeNode *root; // ���ڵ�
    int t;           // ��С����

public:
    BTree(int _t)
    {
        root = NULL;
        t = _t;
    }
    // �������B��
    void traverse()
    {
        if (root != NULL)
            root->traverse();
    }
    BTreeNode *search(int k)
    {
        return (root == NULL) ? NULL : root->search(k);
    }
    void insert(int k);
};

BTreeNode *BTreeNode::search(int k)
{
    // �ҵ���һ�����ڵ��ڴ����ҹؼ�k�Ĺؼ���
    int i = 0;
    while (i < n && k > keys[i])
        i ++;

    // ����ҵ��ĵ�һ���ؼ��ֵ���k���򷵻ر��ڵ�
    if (keys[i] == k)
        return this;

    // ���û���ҵ��ؼ���k�ҵ�ǰ�ڵ�ΪҶ�ӽڵ��򷵻�NULL
    if (leaf == true)
        return NULL;

    // �ݹ����ǡ�����Ӵ�
    return C[i]->search(k);
}

int main()
{
    return 0;
}