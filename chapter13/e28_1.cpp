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

int main()
{
    return 0;
}