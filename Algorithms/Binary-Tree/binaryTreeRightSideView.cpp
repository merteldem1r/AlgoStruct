#include <iostream>

// LeetCode: 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/description/

// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

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
    // Breadth First Search Solution
    std::vector<int> rightSideViewBFS(TreeNode *root) // Time: O(n) Space: O(n)
    {
        if (root == nullptr)
        {
            return {};
        }

        std::deque<TreeNode *> treeDeque;
        std::vector<int> res;
        treeDeque.push_back(root);

        while (!treeDeque.empty())
        {
            const int nodeLevelCount = treeDeque.size();
            res.push_back(treeDeque.back()->val);

            for (int i = 0; i < nodeLevelCount; ++i)
            {
                auto front = treeDeque.front();
                treeDeque.pop_front();

                if (front->left != nullptr)
                {
                    treeDeque.push_back(front->left);
                }

                if (front->right != nullptr)
                {
                    treeDeque.push_back(front->right);
                }
            }
        }

        return res;
    }

    // Depth First Search
    std::vector<int> rightSideViewDFS(TreeNode *root) // Time: O(n) Space: O(n)
    {
        std::vector<int> res;
        dfs(root, res, 0);
        return res;
    }

    void dfs(TreeNode *node, std::vector<int> &res, int depth)
    {
        if (!node)
            return;

        if (res.size() == depth)
        {
            res.push_back(node->val);
        }

        dfs(node->right, res, depth + 1);
        dfs(node->left, res, depth + 1);
    }
};