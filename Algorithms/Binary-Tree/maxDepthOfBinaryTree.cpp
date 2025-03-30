#include <iostream>
#include <queue>

// Find the Maximum Depth of the Binary Tree
// Find the Maximum Depth of the Binary Tree (https://leetcode.com/problems/maximum-depth-of-binary-tree/description/)

// HERE IS MY EXPLANATION:
// https://leetcode.com/problems/maximum-depth-of-binary-tree/solutions/5411377/bfs-without-recursion-example-dry-run-we-cfuf/


/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: 3

Example 2:
    Input: root = [1,null,2]
    Output: 2

    HERE IS MY EXPLANATION:
    https://leetcode.com/problems/maximum-depth-of-binary-tree/solutions/5411377/bfs-without-recursion-example-dry-run-we-cfuf/
*/

struct Node
{
    int val;
    Node *left;
    Node *right;
};


// Using Queue data structure, level order traversal
int maxDepthUsingQueue(Node *root) // Time: O(n) Space: O(n)
{
    if (root == nullptr)
    {
        return 0;
    }

    std::queue<Node *> treeQueue;
    int depth = 0;

    treeQueue.push(root);

    while (true)
    {
        int nodeCountAtLevel = treeQueue.size();

        if (nodeCountAtLevel == 0)
        {
            return depth;
        }

        while (nodeCountAtLevel > 0)
        {
            auto tempNode = treeQueue.front();
            treeQueue.pop();

            if (tempNode->left)
            {
                treeQueue.push(tempNode->left);
            }

            if (tempNode->right)
            {
                treeQueue.push(tempNode->right);
            }

            --nodeCountAtLevel;
        }

        ++depth;
    }

    return depth;
}

// Using Recursion
int maxDepth(Node* root) {
    if (root == nullptr)
        return 0;
    int maxLeft = maxDepth(root->left);
    int maxRight = maxDepth(root->right);

    return std::max(maxLeft, maxRight) + 1;
}

int main()
{
    return 0;
}
