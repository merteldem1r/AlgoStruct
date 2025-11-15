#include <iostream>

// LeetCode: 235. Lowest Common Ancestor of a Binary Search Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
    Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    Output: 6
    Explanation: The LCA of nodes 2 and 8 is 6.
*/

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// My solution (a little bit complicated)
class Solution1
{
public:
    void setDescending(Node *root, Node *node,
                       std::vector<Node *> &desc)
    {
        auto temp = root;
        while (temp != nullptr)
        {
            desc.emplace_back(temp);
            if (temp == node)
            {
                break;
            }
            else if (node->val > temp->val)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        std::cout << std::endl;
    }

    Node *lowestCommonAncestor(Node *root, Node *p, Node *q) // Time: O(h) Space: O(h)
    {
        std::vector<Node *> pDesc, qDesc;

        setDescending(root, p, pDesc);
        setDescending(root, q, qDesc);

        Node *res = root;

        for (int i = 0, j = 0; i < pDesc.size() && j < qDesc.size(); ++i, ++j)
        {
            if (pDesc[i] == qDesc[j])
            {
                res = pDesc[i];
            }
        }

        return res;
    }
};

// Optimal Solution
class Solution2
{
public:
    Node *lowestCommonAncestor(Node *root, Node *p, Node *q) // Time: O(h) Space: O(1)
    {
        auto temp = root;

        while (temp != nullptr)
        {
            if (p->val > temp->val && q->val > temp->val)
            {
                temp = temp->right;
            }
            else if (p->val < temp->val && q->val < temp->val)
            {
                temp = temp->left;
            }
            else
            {
                break;
            }
        }

        return temp;
    }
};

int main()
{
    return 0;
}