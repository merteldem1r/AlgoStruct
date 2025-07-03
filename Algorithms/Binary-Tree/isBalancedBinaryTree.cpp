#include <iostream>

// Balanced Binary Tree Leetcode Questiom
// link: https://leetcode.com/problems/balanced-binary-tree/description/

/*
    Problem:
        * Given a binary tree, determine if it is height-balanced.
        * A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

    Constraints:
        * The number of nodes in the tree is in the range [0, 5000].
        * -10^4 <= Node.val <= 10^4

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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

class Solution // Time: O(n) Space: O(n)
{
public:
    int helper(const TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int leftHeight = helper(root->left);
        if (leftHeight == -1)
        {
            return -1;
        }

        int rightHeight = helper(root->right);
        if (rightHeight == -1)
        {
            return -1;
        }

        int balanceFactor = leftHeight - rightHeight;
        if (std::abs(balanceFactor) > 1)
        {
            return -1;
        }

        return std::max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(const TreeNode *root)
    {
        return helper(root) != -1;
    }
};