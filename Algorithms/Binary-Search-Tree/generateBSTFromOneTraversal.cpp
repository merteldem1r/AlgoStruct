#include <iostream>

// Generate Binary Search Tree from POSTORDER traversal

/*
    Actually the procedure is the same as in the file: Algorithms/Binary-Tree/generateTreeFromTraversals.cpp

    As we know from above code to generat the Binary Tree we need either (Inorder + Postorder) OR (Inorder + Preorder)
    Same can be applied to the Binary Search Tree

    BUT! We can also generate Binary Search Tree only knowing one TRAVERSAL without knowing INORDER
    Either POSTORDER or PREORDER being only one can be enough to generate Binary Search Tree
*/

// Let's generate the BST Fromt the given PREORDER traversal array
// Here is some methods with great explanations: https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int value) : val(value), left(nullptr), right(nullptr) {};
};

Node *generateBSTFromPreorder(std::vector<int> preorderArr) // Time: O(n) Space: O(n)
{
    if (preorderArr.size() == 0)
        return nullptr;

    std::stack<Node *> st;
    Node *root = new Node(preorderArr[0]);
    Node *curr = root;
    int i = 1;

    while (i < preorderArr.size())
    {
        Node *newNode = new Node(preorderArr[i]);

        // if the the value if less than current NODE just put it on the left child
        if (newNode->val < curr->val)
        {
            curr->left = newNode;
            st.push(curr);
            curr = newNode;
        }
        else // if the current VALUE is greater than the current node ther is 2 conditions
        {
            // 1) if the stack is NOT EMPTY and the TOP NODE of the stack is less than current VALUE then it should just change current NODE to the TOP NODE without incrementin index of array
            if (!st.empty() && newNode->val > st.top()->val)
            {
                curr = st.top();
                st.pop();
                continue;
            }
            else // 2) if the stack is EMPTY and the current VALUE is greater than current NODE and less than stack TOP NODE then just put it on the right of the current NODE
            {
                curr->right = newNode;
                curr = newNode;
            }
        }

        ++i;
    }

    return root;
}

// generating Binary Search Tree from the postorder traversal is the same as preorder but we should now start from end of the array

void preorder(Node *root)
{
    if (root == nullptr)
        return;

    std::cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

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
    std::vector<int> preorderArr = {30, 20, 10, 15, 25, 40, 50, 45};
    auto root = generateBSTFromPreorder(preorderArr); // 10 15 20 25 30 40 45 50

    preorder(root);         // 30 20 10 15 25 40 50 45 (same as the preorderArr)
    std::cout << std::endl; // 10 15 20 25 30 40 45 50
    inorder(root);

    return 0;
}