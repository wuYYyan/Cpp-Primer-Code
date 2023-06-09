#include <iostream>
#include <string>

using namespace std;

class TreeNode
{
    private:
        string value;
        int *count;
        TreeNode *left;
        TreeNode *right;
    public:
        TreeNode() : value(string()), count(new int(1)), left(nullptr), right(nullptr) { }
        TreeNode(const TreeNode &tn) : value(tn.value), count(tn.count), left(tn.left), right(tn.right) { ++*count; }
        TreeNode &operator=(const TreeNode &tn)
        {
            ++*tn.count;
            if (--*count == 0)
            {
                delete count;
                delete left;
                delete right;
            }
            value = tn.value;
            count = tn.count;
            left = tn.left;
            right = tn.right;
            return *this;
        }
        ~TreeNode()
        {
            if (--*count == 0)
            {
                delete count;
                delete left;
                delete right;
            }
        }
};

class BinStrTree
{
    private:
        TreeNode *root;
    public:
        BinStrTree() : root(new TreeNode()) {}
        // 拷贝控制成员函数均采用深拷贝方式
        BinStrTree(const BinStrTree &bst)
        {
            root = new TreeNode(*bst.root);
        }
        BinStrTree &operator=(const BinStrTree &bst)
        {
            if (this == &bst)
                return *this;
            delete root;
            root = new TreeNode(*bst.root);
            return *this;

            // 两种检查自我赋值的不同方法
            /*
            TreeNode n_root = new TreeNode(*bst.root)
            delete root;
            root = n_root;
            return *this;
            */
        }
        ~BinStrTree()
        {
            delete root;
        }
};

int main()
{
    return 0;
}