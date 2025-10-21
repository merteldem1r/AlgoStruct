#include <iostream>

// LeetCode 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left),
                                           right(right) {}
};

class SolutionDFS
{
private:
    int preorderIndex = 0;
    std::unordered_map<int, int> inorderMap;

public:
    void setInorderIndexes(std::vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
        {
            inorderMap[inorder[i]] = i;
        }
    }

    Node *generateTreePreIn(std::vector<int> &preorder, std::vector<int> &inorder, int low, int high) // Time: O(n) Space: O(n)
    {
        if (low > high)
        {
            return nullptr;
        }

        const int rootVal = preorder[preorderIndex++];
        const int mid = inorderMap[rootVal];
        Node *root = new Node(rootVal);

        root->left = generateTreePreIn(preorder, inorder, low, mid - 1);
        root->right = generateTreePreIn(preorder, inorder, mid + 1, high);

        return root;
    }

    Node *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
    {
        if (preorder.size() == 1)
        {
            return new Node(preorder[0]);
        }

        setInorderIndexes(inorder);
        Node *root = generateTreePreIn(preorder, inorder, 0, inorder.size() - 1);
        return root;
    }
};
