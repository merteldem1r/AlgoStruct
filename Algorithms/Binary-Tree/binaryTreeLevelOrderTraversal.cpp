#include <iostream>

// LeetCode: 102. Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root) // Time: O(n) Space: O(n)
    {
        if (root == nullptr)
        {
            return {};
        }

        std::vector<std::vector<int>> res;
        std::queue<TreeNode *> treeQueue;
        treeQueue.push(root);

        while (!treeQueue.empty())
        {
            const int levelSize = treeQueue.size();
            std::vector<int> temp;
            temp.reserve(levelSize);

            for (int i = 0; i < levelSize; ++i)
            {
                auto front = treeQueue.front();
                treeQueue.pop();

                if (front->left != nullptr)
                {
                    treeQueue.push(front->left);
                }
                if (front->right != nullptr)
                {
                    treeQueue.push(front->right);
                }

                temp.emplace_back(front->val);
            }

            res.emplace_back(temp);
        }

        return res;
    }
};