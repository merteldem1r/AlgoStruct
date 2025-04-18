#include <iostream>

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int value) : val(value), left(nullptr), right(nullptr) {};
};

// Function to insert nodes in level order (to create bunary tree from the array of integers)
Node *insertLevelOrder(std::vector<int> arr, int index)
{
    if (index >= arr.size())
        return nullptr;

    Node *root = new Node(arr[index]);

    root->left = insertLevelOrder(arr, 2 * index + 1);
    root->right = insertLevelOrder(arr, 2 * index + 2);

    return root;
}

// Count the nodes that does not have left or right children

int countLeafNodes(Node *root) // Time: O(n) Space: O(n)
{
    if (root == nullptr)
        return 0;

    int left = countLeafNodes(root->left);
    int right = countLeafNodes(root->right);

    if (root->left == nullptr && root->right == nullptr)
        return left + right + 1;
    else
        return left + right;
}

int countNonLeafNodes(Node *root) // Time: O(n) Space: O(n)
{
    if (root == nullptr)
        return 0;

    int left = countNonLeafNodes(root->left);
    int right = countNonLeafNodes(root->right);

    if (root->left != nullptr || root->right != nullptr)
        return left + right + 1;
    else
        return left + right;
}

/*
             1
           /   \
          2     7
         / \
        12  0

        Leaf nodes: 12, 0, 7
        Non-leaf nodes: 1, 2,
*/

int main()
{
    std::vector<int> arr = {1, 2, 7, 12, 0};
    Node *root = insertLevelOrder(arr, 0);

    std::cout << "Leaf node count: " << countLeafNodes(root) << std::endl;        // 3
    std::cout << "Non-leaf node count: " << countNonLeafNodes(root) << std::endl; // 2

    return 0;
}