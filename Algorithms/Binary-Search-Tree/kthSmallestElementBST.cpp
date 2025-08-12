#include <iostream>

// LeetCode: 230. Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution // Time: O(n) Space: O(n)
{
public:
    int smallest = 0;

    void helper(TreeNode *root, int &kth)
    {
        if (root == nullptr)
        {
            return;
        }

        helper(root->left, kth);
        if (--kth == 0)
        {
            smallest = root->val;
        }
        helper(root->right, kth);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int tempKth = k;
        helper(root, tempKth);

        return smallest;
    }
};