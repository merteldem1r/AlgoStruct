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

// Sum all the values insides of Nodes in Binary Tree

int sumOfNodes(Node *root) // Time: O(n) Space: O(n)
{
    if (root == nullptr)
        return 0;

    int left = sumOfNodes(root->left);
    int right = sumOfNodes(root->right);

    return left + right + root->val;
}

int main()
{
    std::vector<int> arr = {1, 2, 7, 12, 0, 21};
    Node *root = insertLevelOrder(arr, 0);

    int sum = sumOfNodes(root);
    std::cout << "Sum of all node values: " << sum << std::endl; // 43

    return 0;
}