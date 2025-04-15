#include <iostream>

/*

        Array: {1, 2, 7, 12, 0, 21}

        Left: (2 * i) + 1
        Right: (2 * i) + 2

        Visualization of Binary Tree from the above Array:

              1
            /   \
           2     7
          / \   /
         12  0 21

*/

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int value) : val(value), left(nullptr), right(nullptr) {};
};

Node *generateTree(std::vector<int> &arr, int indx) // Time: O(n) Space: O(n)
{
    if (indx >= arr.size())
        return nullptr;

    Node *root = new Node(arr[indx]);

    root->left = generateTree(arr, 2 * indx + 1);
    root->right = generateTree(arr, 2 * indx + 2);

    return root;
}

void preorder(Node *root)
{
    if (root == nullptr)
        return;

    std::cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    std::vector<int> arr = {1, 2, 7, 12, 0, 21};

    Node *root = generateTree(arr, 0);
    preorder(root); // 1 2 12 0 7 21

    return 0;
}