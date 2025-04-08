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

/*

    Possible Binary Tree Traversal Methods:

        1) PREORDER: visit(node), preorder(left), preorder(right)
        2) INORDER: inorder(left), visit(node), inorder(right)
        3) POSTORDER: postorder(left), postorder(right), visit(node)

        4) LEVEL ORDER: Level by level visit nodes

*/

// 1) PREORDER RECURSIVE
void preorder(Node *root) // Time: O(n) Space: O(n)
{
    if (root != nullptr)
    {
        std::cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// 1.1) PREORDER ITERATIVE
void preorderIterative(Node *root)
{
    std::stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        auto top = st.top();
        std::cout << top->val << " ";
        st.pop();

        if (top->right != nullptr)
            st.push(top->right);
        if (top->left != nullptr)
            st.push(top->left);
    }
}

// 2) INORDER RECURSIVE
void inorder(Node *root) // Time: O(n) Space: O(n)
{
    if (root != nullptr)
    {
        preorder(root->left);
        std::cout << root->val << " ";
        preorder(root->right);
    }
}

// 2.1) INORDER ITERATIVE
void inorderIterative(Node *root)
{
    // code
}

// 3) POSTORDER
void postorder(Node *root) // Time: O(n) Space: O(n)
{
    if (root != nullptr)
    {
        preorder(root->left);
        preorder(root->right);
        std::cout << root->val << " ";
    }
}

// 4) LEVEL ORDER
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

    // 1) PREORDER
    std::cout << "preorder: ";
    preorder(root); // // 1 2 12 0 7 21
    std::cout << " preorder iterative: ";
    preorderIterative(root); // // 1 2 12 0 7 21
    std::cout << std::endl;

    // 2) INORDER
    std::cout << "inorder: ";
    inorder(root); // 2 12 0 1 7 21
    std::cout << " inorder iterative: ";
    inorderIterative(root);
    std::cout << std::endl;

    // 3) POSTORDER
    std::cout << "postorder: ";
    postorder(root); // 2 12 0 7 21 1
    std::cout << std::endl;

    // 4) LEVEL ORDER
    std::cout << "level order: ";
    levelOrder(root); // 1 2 7 12 0 21
    std::cout << std::endl;

    return 0;
}