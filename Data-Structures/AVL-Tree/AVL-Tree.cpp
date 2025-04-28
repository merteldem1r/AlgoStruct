#include <iostream>

// AVL Tree Data Structure

/*

    AVL trees guarantee **O(log n)** time for insertion, deletion, and lookup, by ensuring that the tree remains balanced at all times.

        Balance Factor: height(left subtree) - height(right subtree)
s
        Valid balance factor values:
            -1: Right subtree is taller
            0: Both subtrees are equal
            +1: Left subtree is taller

        If the balance factor becomes less than -1 or greater than +1, the tree needs rebalancing.

    How to Balance AVL Tree:


*/

struct Node
{
    int val;
    Node *left;
    Node *right;
};

class AVL
{
private:
    Node *root;

public:
    int getMax() { return 1; };
    int getMin() { return -1; };

    void Insert(int value) {};
    void Delete(int value) {};
};

int height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = 1 + height(root->left);
    int right = 1 + height(root->right);

    return left - right;
}

int main()
{
    return 0;
}