#include <iostream>

using namespace std;

struct BSTNode
{
    int val;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int val_) : val(val_) { }
};

struct BSTNode *searchNode(struct BSTNode *root, int key)
{
    if (root == NULL || root->val == key)
        return root;
    if (root->val > key)
        return searchNode(root->left, key);
    return searchNode(root->right, key);
}

struct BSTNode *insertNode(struct BSTNode *root, int key)
{
    if (root == NULL)
        return new BSTNode(key);
    if (root->val > key)
        root->left = insertNode(root->left, key);
    else if (root->val < key)
        root->right = insertNode(root->right, key);
    
    return root;
}

struct BSTNode *deleteNode(struct BSTNode *root, int key)
{
    if (root == NULL)
        return root;
    if (root->val > key)
        root->left = deleteNode(root->left, key);
    else if (root->val < key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct BSTNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct BSTNode *temp = root->left;
            free(root);
            return temp;
        }
        struct BSTNode *temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

int main()
{
    return 0;
}