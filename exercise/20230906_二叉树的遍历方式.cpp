#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left_, TreeNode *right_) :
        val(x), left(left_), right(right_) {}
};

// 层序遍历
vector<vector<int>> func(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == NULL) return res;
    queue<TreeNode *> q;
    q.push(root);
    while (q.size()) {
        vector<int> level;
        int len = q.size();
        while (len --) {
            auto t = q.front();
            q.pop();
            level.push_back(t->val);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        res.push_back(level);
    }
    return res;
}

// 深度优先遍历
vector<int> func2(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> stk;
    while (root || stk.size()) {
        while (root) {
            /* 前序位置 */
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        /* 中序位置 */
        root = root->right;
    }
}

int main()
{
    return 0;
}