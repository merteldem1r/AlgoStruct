#include <iostream>

// LeetCode: 572. Subtree of Another Tree
// https://leetcode.com/problems/same-tree/

// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time: (m * n) Space (m + n)
class Solution 
{
public:
    bool sameTree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
        {
            return true;
        }
        if (root != nullptr && subRoot != nullptr && root->val == subRoot->val)
        {
            return sameTree(root->left, subRoot->left) &&
                   sameTree(root->right, subRoot->right);
        }
        return false;
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (subRoot == nullptr)
        {
            return true;
        }
        if (root == nullptr)
        {
            return false;
        }

        if (sameTree(root, subRoot))
        {
            return true;
        }
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
