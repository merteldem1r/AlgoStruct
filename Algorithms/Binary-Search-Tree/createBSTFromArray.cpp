#include <iostream>

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int value) : val(value), left(nullptr), right(nullptr) {};
};

// Create the Binary Search Tree from the given array (insert in same order)

Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value > root->val)
    {
        root->right = insert(root->right, value);
    }
    else if (value < root->val)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        std::cout << "Duplicate detected, no insert" << std::endl;
    }

    return root;
}

Node *createBST(std::vector<int> arr) // Time Average: O(nlogn)
{
    if (arr.size() == 0)
        return nullptr;

    Node *root = new Node(arr[0]);

    for (int i = 1; i < arr.size(); ++i)
    {
        insert(root, arr[i]);
    }

    return root;
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

        if (front->left != nullptr)
            treeQueue.push(front->left);
        if (front->right != nullptr)
            treeQueue.push(front->right);
    }
}

int main()
{
    std::vector<int> arr = {9, 15, 5, 20, 16, 8, 12, 3, 6};
    Node *root = createBST(arr);

    /*
        Built Binary Search Tree: 
                  9
             /         \
           5             15
         /   \         /    \
        3     8      12      20
            /                /
           6               16

   */
    bfs(root); //

    return 0;
}