#include <iostream>

/*
    LeetCode 226. Invert Binary Tree
    https://leetcode.com/problems/invert-binary-tree/description/

    Given the root of a binary tree, invert the tree, and return its root.

*/

struct Node
{
    int val;
    Node *left;
    Node *right;
};

class Solution
{
public:
    void invertHelper(Node *root)
    {
        if (root == nullptr)
            return;

        std::swap(root->left, root->right);
        invertHelper(root->left);
        invertHelper(root->right);
    }

    Node *invertTree(Node *root)
    {
        auto dummy = root;

        invertHelper(dummy);
        return root;
    }
};

int main()
{

    return 0;
}