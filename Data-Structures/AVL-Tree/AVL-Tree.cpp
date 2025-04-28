#include <iostream>

// AVL Tree Data Structure

// Informative links for reading and understanding the topic:
//  https://www.geeksforgeeks.org/introduction-to-avl-tree/
//  https://www.geeksforgeeks.org/insertion-in-an-avl-tree/

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

struct Node
{
    int val;
    Node *left;
    Node *right;
};

class AVL
{
private:
    //

public:
    //
};

int main()
{
    return 0;
}