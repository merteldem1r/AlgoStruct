#include <iostream>

// LeetCode 543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/description/

/*
    Given the root of a binary tree, return the length of the diameter of the tree.

    The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

    The length of a path between two nodes is represented by the number of edges between them.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    int maxEdge = 0;

public:
    int dfsPostorder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftMaxEdge = dfsPostorder(root->left);
        int rightMaxEdge = dfsPostorder(root->right);

        if (leftMaxEdge + rightMaxEdge > maxEdge)
        {
            maxEdge = leftMaxEdge + rightMaxEdge;
        }

        return std::max(leftMaxEdge, rightMaxEdge) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        dfsPostorder(root);
        return maxEdge;
    }
};