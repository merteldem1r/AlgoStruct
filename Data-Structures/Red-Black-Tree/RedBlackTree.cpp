#include <iostream>

// RED BLACK TREE
// AUTHOR: Mert Eldemir

/*
    Red Black Tree Properties:

    1. It's Height Balanced Binary Search Trees, similart to 2-3-4 Tree
    2. Node is either RED or BLACK Color
    3. Root of a Tree is always BLACK
    4. NULL is also taken as BLACK
    5. Number of Blacks on Path from Root to the leafes are same
    6. RED node must not have RED children
    7. New Inserted node is RED
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

        2.1) Left-Left (LL) Case (needs Right Rotation) also called ZIG-ZAG

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

        2.2) Right-Right (RR) Case (Needs Left Rotation) also called ZIG-ZIG

            G (Black)
                \
                P(R)
                \
                n(R)
            U (Black or NIL)

        Fix:
        - Left Rotate G
        - Swap colors of G and P

        Before rotation:

            G(B)
               \
               P(R)
                  \
                 n(R)

        After Left Rotation:

             P(B)
            /   \
          G(R)  n(R)

    IMPORTANT NOTES:

        * Recoloring is cheaper than rotating — so Red-Black Trees only rotate when necessary.
        That’s why they are more efficient for frequent insertions/deletions than AVL Trees.
        * Recoloring doesn’t fix structure, but it fixes the “black-height” property — the part that guarantees that no path from root to leaf can be more than twice as long as any other.

        Comparation with AVL Tree:

            AVL Tree
                *Tracks an explicit balance factor at every node.
                *Allows at most 1 height difference between left and right subtrees.
                *If that limit is broken, it must rotate immediately, no matter what.
                *This keeps the tree very close to perfect balance → minimal height.
                *But it means more rotations, especially for insert-heavy or delete-heavy workloads.

            Red-Black Tree
                *Doesn’t store or check numeric balance factors.
                *Uses color rules to approximate the same goal:
                *No two reds in a row.
                *Paths from a node to any leaf must have the same number of black nodes.
                *If inserting a node creates a problem, it tries recoloring first, only rotating when strictly needed.
                *This means it sometimes accepts a bit more imbalance.
                *Its height can be up to 2× log₂(n) vs. ~1.44× log₂(n) for AVL.
                *But it saves time by avoiding unnecessary rotations.

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

    int height(RBNode* current) {
        if (current == nullptr) {
            return 0;
        }

        int left = height(current->left);
        int right = height(current->right);

        return 1 + std::max(left, right);
    }

    RBNode *Search(const int val)
    {
        RBNode *temp = Root;

        while (temp != nullptr)
        {
            if (temp->value > val)
            {
                temp = temp->left;
            }
            else if (temp->value < val)
            {
                temp = temp->right;
            }
            else
            {
                return temp;
            }
        }

        return nullptr;
    }
};

int main()
{
    return 0;
}