#include <iostream>

// Binary Search Tree

/*

    Example Binary Search Tree:

        30
       /  \
     15    50
    /  \   / \
  10   20 40 60

    Some Properties:

    1) No duplicates
    2) Inorder traversal gives SORTED order

    3) Number of "n" nodes from which BST can be created:

        Number of Unique Binary Search Trees (BSTs) from 'n' distinct nodes:

        This is given by the nth Catalan Number (C_n), which counts the number of
        unique BSTs that can be constructed from 'n' distinct keys.

        Catalan Number Formula:
            Cn = (1 / (n + 1)) * (2n choose n)
            = (2n)! / [(n + 1)! * n!]

        --- What is (2n choose n)? ---
        This is the **combination formula**, written as:
            (2n choose n) = (2n)! / (n! * n!)

        It represents the number of ways to choose 'n' elements from a set of '2n'
        elements, without considering order.

        --- So, what is Cn doing? ---
        The Catalan number takes that combination and divides it by (n + 1),
        giving the number of unique BSTs (or valid parenthesis sequences, etc.)
        for a given 'n'.

        Example Catalan Values:
            C0 = 1
            C1 = 1
            C2 = 2
            C3 = 5
            C4 = 14
            C5 = 42
            C6 = 132
            C7 = 429

        For n = 7 (as in the example array {30, 15, 50, 10, 20, 40, 60}):
            Total Unique BSTs = C7 = 429
*/

// Let's implement Binary Search Tree from the scratch

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int value) : val(value), left(nullptr), right(nullptr) {};
};

class BinarySearchTree
{
private:
    Node *root;
    int nodeCount;

public:
    BinarySearchTree() : root(nullptr), nodeCount(0) {};
    BinarySearchTree(int value) : root(new Node(value)), nodeCount(1) {};

    int getNodeCount() const { return nodeCount; }

    Node *getRoot() const { return root; }

    void Insert(int value)
    {
        if (search(value) != nullptr)
        {
            std::cout << "Provided value already exists" << std::endl;
            return;
        }

        auto temp = root;
        Node *prev = nullptr;

        while (temp != nullptr)
        {
            prev = temp;

            if (temp->val > value)
                temp = temp->left;
            else
                temp = temp->right;
        }

        Node *newNode = new Node(value);

        if (prev == nullptr)
            root = newNode;
        else if (newNode->val > prev->val)
            prev->right = newNode;
        else
            prev->left = newNode;

        ++nodeCount;
        std::cout << "Inserted value: " << newNode->val << std::endl;
    }

    int Delete(int value)
    {
        auto temp = root;
        Node *foundNode = nullptr;
        Node *parentNodeOfFoundNode = nullptr;

        while (temp != nullptr)
        {
            if (temp->val == value)
            {
                foundNode = temp;
                break;
            }

            parentNodeOfFoundNode = temp;

            if (value > temp->val)
                temp = temp->right;
            else
                temp = temp->left;
        }

        if (foundNode == nullptr)
        {
            std::cout << "Value not found" << std::endl;
            return -1;
        }

        //  1. Case: Leaf Node
        /*
                Step 1: delete node from the Heap
                Step 2: Reassign the parent node of deleted node to nullptr
        */

        const int foundValue = foundNode->val;

        if (foundNode->left == nullptr && foundNode->right == nullptr)
        {
            if (parentNodeOfFoundNode->right == foundNode)
                parentNodeOfFoundNode->right = nullptr;
            else
                parentNodeOfFoundNode->left = nullptr;

            delete foundNode;

            return foundValue;
        }

        // 2. Case: Parent Node
        /*
            Step 1: Find the minimum of nodes that bigger than foundNode (which is right then leftmost)
            Step 2:
                a) if foundNode does not have right child: assign left child to the parentNodeOfFoundNode
                b) if foundNode do have right child: go to the leftmost of the right subtree to find minimum

        */

        // a) No right child
        if (foundNode->right == nullptr)
        {
            if (parentNodeOfFoundNode->right == foundNode)
                parentNodeOfFoundNode->right = foundNode->left;
            else
                parentNodeOfFoundNode->left = foundNode->left;

            delete foundNode;

            return foundValue;
        }

        // b) Right child
        Node *leftMostRightSubtreeNode = foundNode->right;
        Node *parentLeftMostRightSubtreeNode = foundNode;

        while (leftMostRightSubtreeNode->left != nullptr)
        {
            parentLeftMostRightSubtreeNode = leftMostRightSubtreeNode;
            leftMostRightSubtreeNode = leftMostRightSubtreeNode->left;
        }

        leftMostRightSubtreeNode->right = foundNode->right;
        leftMostRightSubtreeNode->left = foundNode->left;

        if (parentNodeOfFoundNode == nullptr) root = leftMostRightSubtreeNode;
        else if (parentNodeOfFoundNode->right == foundNode)
            parentNodeOfFoundNode->right = leftMostRightSubtreeNode;
        else
            parentNodeOfFoundNode->left = leftMostRightSubtreeNode;

        if (parentLeftMostRightSubtreeNode->right == leftMostRightSubtreeNode) 
            parentLeftMostRightSubtreeNode->right = nullptr;
        else 
            parentLeftMostRightSubtreeNode->left = nullptr;

        delete foundNode;

        return foundValue;
    }

    Node *search(int value) const
    {
        auto temp = root;

        while (temp != nullptr)
        {
            if (temp->val == value)
                return temp;
            else if (value > temp->val)
                temp = temp->right;
            else
                temp = temp->left;
        }

        return nullptr;
    }

    int max() const
    {
        if (root == nullptr)
        {
            std::cout << "Binary Search Tree is empty" << std::endl;
            return -1;
        }

        auto temp = root;
        for (; temp->right != nullptr; temp = temp->right)
        {
        }
        return temp->val;
    }

    int min() const
    {
        if (root == nullptr)
        {
            std::cout << "Binary Search Tree is empty" << std::endl;
            return -1;
        }

        auto temp = root;
        for (; temp->left != nullptr; temp = temp->left)
        {
        }
        return temp->val;
    }

    int height() const { return 0; }

    bool isBalanced() const { return false; }
};

void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    BinarySearchTree *BST = new BinarySearchTree();

    BST->Insert(30);
    BST->Insert(15);
    BST->Insert(50);
    BST->Insert(10);
    BST->Insert(20);
    BST->Insert(40);
    BST->Insert(60);

    /*

        30
       /  \
     15    50
    /  \   / \
  10   20 40 60

    */

    inorder(BST->getRoot());                               // 10 15 20 30 40 50 60
    std::cout << "Max value: " << BST->max() << std::endl; // 60
    std::cout << "Min value: " << BST->min() << std::endl; // 10

    BST->Delete(50);
    inorder(BST->getRoot());

    return 0;
}