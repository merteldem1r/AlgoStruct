#include <iostream>

// Invert the Binary Tree (https://leetcode.com/problems/invert-binary-tree/submissions/1591163276/)

/*

    Given the root of a binary tree, invert the tree, and return its root.

    Example 1
        Input: root = [4,2,7,1,3,6,9]
        Output: [4,7,2,9,6,3,1]

    Example 2
        Input: root = [2,1,3]
        Output: [2,3,1]

*/

struct Node
{
    int val;
    Node *left;
    Node *right;
};

Node *invertTree(Node *root) // Time: O(n) Space: O(n)
{
    if (root == nullptr)
        return root;

    std::swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

int main()
{
    return 0;
}