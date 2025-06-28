#include <iostream>

// Red Black Tree

/*
    Red Black Tree Properties:

    1. It's Height Balanced Binary Search Trees, similart to 2-3-4 Tree
    2. Node is either Read or Black
    3. Root of a Tree is always Black
    4. NULL is also taken as Black
    5. Number of Blacks on Path from Root to the leas are same
    6. No 2 consecutive Red; Parent and Children of Red is Black
    7. New Inserted node is Red
    8. Height is logN <= h <= 2logN
        * minimum logN, maximum is double of logN

    * Color (Red & Black) is only need to maintain the balancing rule of the tree,

    There is 2 methods to handle balance on the Red Black Tree:

        1) Recoloring Case

        RULE: If UNCLE is RED and the PARENT is RED use RECOLOR!

            G (Black)
            / \
         P(R) U(R)
         /
        n(R)

        G: Grandparent
        P: Parent
        U: Uncle
        n: New inserted node

        Problem:
        - New red node (n) has red parent (P)
        - P and U are both red -> violates property (no two reds in a row)

        Fix:
        - Recolor P and U to Black
        - Recolor G to Red
        - Move up to G and repeat fix if needed

        After recoloring:

            G (Red)
            / \
         P(B) U(B)
         /
        n(R)

        2) Rotation Case

        RULE: If PARENT is RED and UNCLE is BLACK or NULL (NULL also mean Black) use ROTATION!

        Example: Left-Left Case (needs Right Rotation)

            G (Black)
            /     \
          P(R)   U (Black or NIL)
          /
        n(R)


        Problem:
        - n and P are both red -> violates property
        - Uncle is Black -> must rotate

        Fix:
        - Perform Right Rotation around G
        - Recolor new root to Black, child to Red

        Before rotation:

            G(B)
            /
        P(R)
        /
        n(R)

        After Right Rotation:

            P(B)
            /  \
         n(R)   G(R)

        Result:
        - Tree structure changes
        - Red-Black properties restored

*/

enum Color
{
    RED,
    BLACK
};

struct RBNode
{
    int value;
    Color color;
    RBNode *left;
    RBNode *right;

    RBNode(int value) : value(value), color(RED), right(nullptr), left(nullptr) {};
};

class RedBlackTree
{
private:
    RBNode *Root;

public:
    RedBlackTree(int value) : Root(new RBNode(value)) {};
};

int main()
{
    return 0;
}