#include <iostream>

// AVL Tree Data Structure
// AUTHOR: Mert Eldemir

// Informative links for understanding the topic:
//  https://www.geeksforgeeks.org/introduction-to-avl-tree/
//  https://www.geeksforgeeks.org/insertion-in-an-avl-tree/
//  https://www.udemy.com/course/datastructurescncpp

/*

    AVL trees guarantee O(log n) time for insertion, deletion, and lookup, by ensuring that the tree remains balanced at all times.

        BALANCE FACTOR: height(left subtree) - height(right subtree)

        Valid balance factor values:
            -1: Right subtree is taller
            0: Both subtrees are equal
            +1: Left subtree is taller

        If the balance factor becomes less than -1 or greater than +1, the tree needs rebalancing.

        Depending on where the imbalance is, we apply different rotations:

          | SITUATION |                                              | CASE NAME |             | ROTATION NEEDED |
        * Insertion in left-left (left subtree of left child)        Left-Left (LL)            Right Rotation
        * Insertion in right-right (right subtree of right child)    Right-Right (RR)          Left Rotation
        * Insertion in left-right (right subtree of left child)      Left-Right (LR)           Left Rotation, then Right Rotation
        * Insertion in right-left (left subtree of right child)      Right-Left (RL)           Right Rotation, then Left Rotation


    How ROTATIONS have done in AVL Tree, ALL CASES (visualization):

        1) RIGHT ROTATION (LL):
                z
               /
             y
            /
           x

            -> Applied rotation:
                y
               / \
              x   z

        2) LEFT ROTATION (RR):

            z
             \
              y
                \
                 x

            -> Applied rotation:

                y
               / \
              z   x

        3) RIGHT-LEFT ROTATION (RL):
                z
                 \
                  y
                 /
                x

            -> Applied rotation:

                1. Step Right Rotation on y:
                    z
                     \
                      x
                       \
                        y

                2. Step Left Rotation on x:
                     x
                    / \
                   z   y

        4) LEFT-RIGHT ROTATION (LR):
                z
               /
              y
               \
                x

            -> Applied rotation:

                1. Step Left Rotation on y:
                    z
                   /
                  x
                 /
                y

                2. Step Left Rotation on x:
                     x
                    / \
                   y   z


        Summary of all Steps:
            1.	Insert as normal BST.
            2.	Update heights.
            3.	Check balance factors.
            4.	If unbalanced:
                •	LL → Right Rotate
                •	RR → Left Rotate
                •	LR → Left + Right Rotate
                •	RL → Right + Left Rotate
            5.	Keep repeating up to the root.

        IMPORTANT POINT: Rotations always done with the 3 nodes only, even Tree has thousands Nodes; rotations is performed ONLY OVER 3 NODES.
*/

class AVL
{
private:
    struct Node
    {
        int val;
        int height;
        Node *left;
        Node *right;

        Node(int value, int h) : val(value), left(nullptr), right(nullptr), height(h) {};
    };

    Node *Root = nullptr;

private:
    Node *rightRotation(Node *current)
    {
        /*
            Right Rotation

            Before:

                c
               /
             cl
               \
               clr

            After:

               cl
               / \
             ..   c
                 /
               clr
        */

        Node *currLeft = current->left;
        Node *currLeftRight = currLeft->right;

        currLeft->right = current;
        current->left = currLeftRight;

        // current and the currLeft height gonna change, we update them
        current->height = nodeHeight(current);
        currLeft->height = nodeHeight(currLeft);

        if (Root == current) // also check if the rotation was performing on the Root
            Root = currLeft;

        return currLeft;
    }

    Node *leftRotation(Node *current)
    {
        /*
            Left Rotation

            Before:

               c
                \
                cr
               /
             crl

            After:

               cr
              /  \
             c   ..
              \
             crl
        */

        Node *currRight = current->right;
        Node *currRightLeft = currRight->left;

        currRight->left = current;
        current->right = currRightLeft;

        // current and the currRight height gonna change, we update them
        current->height = nodeHeight(current);
        currRight->height = nodeHeight(currRight);

        if (Root == current) // also check if the rotation was performing on the Root
            Root = currRight;

        return currRight;
    }

    Node *insertUtility(Node *current, int value)
    {
        // Here is we insert as usual with recursion
        if (current == nullptr)
            return new Node(value, 1); // create new Node with val and height (setting as 1) properties

        if (value > current->val)
            current->right = insertUtility(current->right, value);
        else if (value < current->val)
            current->left = insertUtility(current->left, value);
        else
            std::cout << "Insertion skipped, value already exists" << std::endl;

        current->height = nodeHeight(current); // update every node height on returning phase

        // Get balance factor and handle rotations if unbalanced
        int balance = balanceFactor(current);

        if (balance > 1) // not balanced, left is taller
        {

            // 1. LL Rotation
            /*
                   z
                  /
                 y
                /
               x
            */
            if (balanceFactor(current->left) > 0)
            {
                return rightRotation(current);
            }

            // 2. LR Rotation
            /*
                 z
               /
              y
               \
                x
            */
            current->left = leftRotation(current->left);
            return rightRotation(current);
        }
        else if (balance < -1) // not balanced, right is taller
        {
            // 1. RR rotation
            /*
                z
                 \
                  y
                   \
                    x
            */
            if (balanceFactor(current->right) < 0)
            {
                return leftRotation(current);
            }

            // 2. RL rotation
            /*
                z
                 \
                  y
                 /
                x
            */
            current->right = rightRotation(current->right);
            return leftRotation(current);
        }

        return current;
    }

    // get smallest Node from the right subtree of given node (current)
    Node *successor(Node *current)
    {
        Node *temp = current->right;
        while (temp != nullptr && temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp;
    }

    Node *removeUtility(Node *current, int value)
    {
        if (current == nullptr)
        {
            std::cout << "Node not found" << std::endl;
            return nullptr;
        }

        // Start recursive traversal to find the Node
        if (value > current->val)
            current->right = removeUtility(current->right, value);
        else if (value < current->val)
            current->left = removeUtility(current->left, value);
        else // Node FOUND
        {
            if (current->left == nullptr) // 1) LEAF or has only RIGHT CHILD
            {
                Node *temp = current;
                current = current->right;
                delete temp;
            }
            else if (current->right == nullptr) // 2) has only LEFT CHILD
            {
                Node *temp = current;
                current = current->left;
                delete temp;
            }
            else // has BOTH RIGHT and LEFT CHILD
            {
                Node *successorNode = successor(current);
                current->val = successorNode->val;                                  // replace found node with successor value
                current->right = removeUtility(current->right, successorNode->val); // delete successor node as usual
            }
        }

        if (current == nullptr)
        {
            // if deleted node becomes the nullptr (in case of leaf)
            return nullptr;
        }

        current->height = nodeHeight(current); // update every node height on returning phase

        // Get balance factor and handle rotations if unbalanced
        int balance = balanceFactor(current);

        if (balance > 1) // not balanced, left is taller
        {

            // 1. LL Rotation
            /*
                   z
                  /
                 y
                /
               x
            */
            if (balanceFactor(current->left) > 0)
            {
                return rightRotation(current);
            }

            // 2. LR Rotation
            /*
                 z
               /
              y
               \
                x
            */
            current->left = leftRotation(current->left);
            return rightRotation(current);
        }
        else if (balance < -1) // not balanced, right is taller
        {
            // 1. RR rotation
            /*
                z
                 \
                  y
                   \
                    x
            */
            if (balanceFactor(current->right) < 0)
            {
                return leftRotation(current);
            }

            // 2. RL rotation
            /*
                z
                 \
                  y
                 /
                x
            */
            current->right = rightRotation(current->right);
            return leftRotation(current);
        }

        return current;
    }

    int nodeHeight(Node *current)
    {
        if (current == nullptr)
            return 0;

        return 1 + std::max(current->left->height, current->right->height);
    }

    int balanceFactor(Node *current)
    {
        if (current == nullptr)
            return 0;

        int leftHeight = nodeHeight(current->left);
        int rightHeight = nodeHeight(current->right);

        return leftHeight - rightHeight;
    }

    void levelOrderUtility(Node *current)
    {
        std::queue<Node *> treeQueue;
        treeQueue.push(current);

        while (!treeQueue.empty())
        {
            Node *front = treeQueue.front();
            treeQueue.pop();

            std::cout << front->val << " ";

            if (front->left != nullptr)
                treeQueue.push(front->left);
            if (front->right != nullptr)
                treeQueue.push(front->right);
        }
    }

    void inorderUtility(Node *current)
    {
        if (current == nullptr)
            return;

        inorderUtility(current->left);
        std::cout << current->val << " ";
        inorderUtility(current->right);
    }

public:
    void insert(int value)
    {
        insertUtility(Root, value);
    }

    void remove(int value)
    {
        removeUtility(Root, value);
    }

    void levelOrder()
    {
        levelOrderUtility(Root);
        std::cout << std::endl;
    }

    void inorder()
    {
        inorderUtility(Root);
        std::cout << std::endl;
    }
};

int main()
{
    return 0;
}