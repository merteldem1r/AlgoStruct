#include <iostream>
#include <unordered_map>

// Creating Binary Tree

/*

    Binary Tree common features:

    • Each node has at most two children (left and right).
    • The root is the topmost node in the tree.
    • Leaf nodes have no children (external nodes).
    • Height is the longest path from root to a leaf.
    • Depth of a node is its distance from the root.
    • Binary trees can be balanced or unbalanced.
    • Common types: Full, Complete, Perfect, Balanced, Degenerate.
    • Used in searching, sorting, and hierarchical data representation.

*/

struct Node
{
    Node *left;
    Node *right;
    int val;

    Node(int value) : left(nullptr), right(nullptr), val(value) {};
};

/*

Binary Tree:

       1
     /   \
    2     7
   / \   /
  12  0 1


Array Representation:

    {1, 2, 7, 12, 0, 1} n = 6

    Left: (i * 2) + 1
    Rigth: (i * 2) + 2

*/

void buildBinaryFromArray(const std::vector<int> &arr, Node *root, int currIndex)
{
    if (currIndex > arr.size())
        return;

    int leftIndex = (currIndex * 2) + 1;
    int rightIndex = (currIndex * 2) + 2;

    if (leftIndex < arr.size())
    {
        root->left = new Node(arr[leftIndex]);
        buildBinaryFromArray(arr, root->left, leftIndex);
    }

    if (rightIndex < arr.size())
    {
        root->right = new Node(arr[rightIndex]);
        buildBinaryFromArray(arr, root->right, rightIndex);
    }
}

void bfs(Node *root)
{
    std::queue<Node *> treeQueue;
    treeQueue.push(root);

    while (!treeQueue.empty())
    {
        auto front = treeQueue.front();
        treeQueue.pop();

        std::cout << front->val << " ";

        if (front->left)
            treeQueue.push(front->left);
        if (front->right)
            treeQueue.push(front->right);
    }
}

int main()
{
    Node *root = new Node(1);
    const std::vector<int> exampleArr = {1, 2, 7, 12, 0, 1};

    buildBinaryFromArray(exampleArr, root, 0);
    bfs(root);

    return 0;
}