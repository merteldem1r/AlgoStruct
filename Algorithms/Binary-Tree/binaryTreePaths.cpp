#include <iostream>

// LeetCode: 257. Binary Tree Paths
// https://leetcode.com/problems/binary-tree-paths/description/

// Given the root of a binary tree, return all root-to-leaf paths in any order.

// A leaf is a node with no children.

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
public:
    std::vector<std::string> ans;

    void dfs(TreeNode *root, std::string tempStr = "")
    {
        if (root == nullptr)
        {
            return;
        }

        int val = root->val;
        tempStr += std::to_string(root->val);

        if (root->left == nullptr && root->right == nullptr)
        {
            ans.emplace_back(tempStr);
        }
        else
        {
            tempStr += "->";

            dfs(root->left, tempStr);
            dfs(root->right, tempStr);
        }
    }

    std::vector<std::string> binaryTreePaths(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};