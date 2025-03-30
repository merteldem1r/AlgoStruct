#include <iostream>

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int value) : val(value), left(nullptr), right(nullptr) {};
};

// Function to insert nodes in level order
Node *insertLevelOrder(std::vector<int> arr, int index)
{
    if (index >= arr.size())
        return nullptr;

    Node *root = new Node(arr[index]);

    root->left = insertLevelOrder(arr, 2 * index + 1);
    root->right = insertLevelOrder(arr, 2 * index + 2);

    return root;
}

/*

    Possible Binary Tree Traversal Methods:

        1) PREORDER: visit(node), preorder(left), preorder(right)
        2) INORDER: inorder(left), visit(node), inorder(right)
        3) POSTORDER: postorder(left), postorder(right), visit(node)

        4) LEVEL ORDER: Level by level visit nodes

*/

void preorder(Node *root)
{
    if (root != nullptr)
    {
        std::cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if (root != nullptr)
    {
        preorder(root->left);
        std::cout << root->val << " ";
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != nullptr)
    {
        preorder(root->left);
        preorder(root->right);
        std::cout << root->val << " ";
    }
}

// 4) Level Order Traversal
void levelOrder(Node *root) // Time: O(n) Space: O(n)
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
    std::vector<int> arr = {1, 2, 7, 12, 0, 21};
    Node *root = insertLevelOrder(arr, 0);

    /*
              1
            /   \
           2     7
          / \   /
         12  0 21
    */

    std::cout << "preorder: ";
    preorder(root); // 1 2 12 0 7 21
    std::cout << std::endl;

    std::cout << "inorder: ";
    inorder(root); // 2 12 0 1 7 21
    std::cout << std::endl;

    std::cout << "postorder: ";
    postorder(root); // 2 12 0 7 21 1
    std::cout << std::endl;

    std::cout << "level order: ";
    levelOrder(root); // 1 2 7 12 0 21
    std::cout << std::endl;

    return 0;
}