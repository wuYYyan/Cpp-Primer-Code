#include <iostream>

using namespace std;

class BTreeNode
{
private:
    int *keys; // 存储本节点所含关键字的数组
    int t;     // 最小度数
    BTreeNode **C; // 存储孩子节点指针的数组，
    int n;     // 本节点所含关键字的个数
    bool leaf; // 是否为叶子节点

public:
    BTreeNode(int _t, bool _leaf)
    {
        t = _t;
        leaf = _leaf;
        keys = new int[2 * t - 1]; // 最多可以包含2t-1个关键字
        C = new BTreeNode *[2 * t];
        n = 0;
    }
    void traverse();
    BTreeNode *search(int k); // 如果不存在，则返回NULL
    friend class BTree; // 友元类，可以访问BTreeNode的私有成员
};

class BTree
{
private:
    BTreeNode *root; // 根节点
    int t;           // 最小度数

public:
    BTree(int _t)
    {
        root = NULL;
        t = _t;
    }
    // 中序遍历B树
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
    // 找到第一个大于等于待查找关键k的关键字
    int i = 0;
    while (i < n && k > keys[i])
        i ++;

    // 如果找到的第一个关键字等于k，则返回本节点
    if (keys[i] == k)
        return this;

    // 如果没有找到关键字k且当前节点为叶子节点则返回NULL
    if (leaf == true)
        return NULL;

    // 递归访问恰当的子代
    return C[i]->search(k);
}

int main()
{
    return 0;
}