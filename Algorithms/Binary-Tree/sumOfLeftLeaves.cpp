#include <iostream>

// LeetCode: 404. Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/description/

/*
Given the root of a binary tree, return the sum of all left leaves.
A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: 24
    Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:
    Input: root = [1]
    Output: 0
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
    int leftLeavesSum = 0;

    void dfs(TreeNode *root, bool isOnLeft)
    {
        if (root == nullptr)
        {
            return;
        }

        if (isOnLeft && root->left == nullptr && root->right == nullptr)
        {
            leftLeavesSum += root->val;
        }
        dfs(root->left, true);
        dfs(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        dfs(root, false);
        return leftLeavesSum;
    }
};

int main()
{
    return 0;
}