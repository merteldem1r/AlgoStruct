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

// Count nodes in the given Binary Tree

// This countNodes function looks like the postorder POSTORDER, so actullay while dealing with the Binary Trees we most of the time gonna use POSTORDER procedure
int countNodes(Node *root)
{ // Time: O(n) Space: O(n)
    if (root == nullptr)
        return 0;

    int left = countNodes(root->left);
    int right = countNodes(root->right);

    return left + right + 1;
}

/*
        Tree structure:

                  1
                /   \
               2     7
              / \   /
             12  0 21

        Function works recursively (post-order):
        - Traverse left subtree
        - Traverse right subtree
        - Count current node

        Traversal Order:
        countNodes(1)
            → countNodes(2)
                → countNodes(12) → left = 0, right = 0 → return 1
                → countNodes(0) → left = 0, right = 0 → return 1
                → return 1 (12) + 1 (0) + 1 (2 itself) = 3
            → countNodes(7)
                → countNodes(21) → left = 0, right = 0 → return 1
                → return 1 (21) + 0 (null) + 1 (7 itself) = 2
            → return 3 (from 2) + 2 (from 7) + 1 (root 1) = 6

        Final result: 6 nodes
    */

// Addin the small condition will make that function to count only nodes with degree of 2 (which means they have both left and right children)
int countNodesWithDegreeTwo(Node *root) // Time: O(n) Space: O(n)
{
    if (root == nullptr)
        return 0;

    int left = countNodesWithDegreeTwo(root->left);
    int right = countNodesWithDegreeTwo(root->right);

    if (root->left != nullptr && root->right != nullptr)
        return left + right + 1;
    else
        return left + right;
}

// Count nodes only with degree on (which mean it has rather right or left child only)
int countNodesWithDegreeOne(Node *root)
{
    if (root == nullptr)
        return 0;

    int left = countNodesWithDegreeOne(root->left);
    int right = countNodesWithDegreeOne(root->right);

    if (root->left != nullptr ^ root->right != nullptr) // XOR operation (which means if only one is TRUE)
    {
        return left + right + 1;
    }
    else
    {
        return left + right;
    }
}

int countNodesLevelOrder(Node *root) // Time: O(n) Space: O(n)
{
    if (root == nullptr)
        return 0;

    std::queue<Node *> treeQueue;
    treeQueue.push(root);
    int res = 0;

    while (!treeQueue.empty())
    {
        auto front = treeQueue.front();
        treeQueue.pop();
        ++res;

        if (front->left != nullptr)
            treeQueue.push(front->left);
        if (front->right != nullptr)
            treeQueue.push(front->right);
    }

    return res;
}

// find HEIGHT of the binary tree
int heightOfTree(Node *root)
{ // Time: O(n) Space: O(n)
    if (root == nullptr)
        return 0;

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    if (left > right)
        return left + 1;
    else
        return right + 1;
}

int main()
{
    std::vector<int> arr = {1, 2, 7, 12, 0, 21};
    Node *root = insertLevelOrder(arr, 0);

    /*

                  1
                /   \
               2     7
              / \   /
             12  0 21

             Node count: 6
             Nodes with degree of TWO: 1, 2
             Nodes with degree of ONE: 7

    */

    std::cout << "Node count: " << countNodes(root) << std::endl;                                                                          // 6
    std::cout << "Node count (level order): " << countNodesLevelOrder(root) << std::endl;                                                  // 6
    std::cout << "Node count with degree of TWO (having left and right child): " << countNodesWithDegreeTwo(root) << std::endl;            // 2
    std::cout << "Node count with degree of ONE (having rather left or right child only): " << countNodesWithDegreeOne(root) << std::endl; // 1
    std::cout << "Height of a tree: " << heightOfTree(root) << std::endl;                                                                  // 3

    return 0;
}