#include <iostream>

// 1448. Count Good Nodes in Binary Tree
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

// Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X. Return the number of good nodes in the binary tree.

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

// DFS Solution
class SolutionDFS
{
public:
    void dfs(Node *root, int &count, int pathMax) // Time: O(n) Space: O(n)
    {
        if (root == nullptr)
        {
            return;
        }

        int newPathMax = pathMax;
        if (root->val >= pathMax)
        {
            ++count;
            newPathMax = root->val;
        }

        dfs(root->left, count, newPathMax);
        dfs(root->right, count, newPathMax);
    }

    int goodNodes(Node *root)
    {
        int count = 0;
        dfs(root, count, root->val);

        return count;
    }
};

// BFS Solution
class Solution
{
public:
    int goodNodes(Node *root) // Time: O(n) Space: O(n)
    {
        int res = 0;

        std::queue<std::pair<Node *, int>> treeQueue;
        treeQueue.push({root, root->val});

        while (!treeQueue.empty())
        {
            auto [front, maxVal] = treeQueue.front();
            treeQueue.pop();

            int newMaxVal = maxVal;
            if (front->val >= maxVal)
            {
                ++res;
                newMaxVal = front->val;
            }

            if (front->left != nullptr)
            {
                treeQueue.push({front->left, newMaxVal});
            }

            if (front->right != nullptr)
            {
                treeQueue.push({front->right, newMaxVal});
            }
        }

        return res;
    }
};