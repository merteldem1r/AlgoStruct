#include <iostream>
#include <fmt/format.h>

// RED BLACK TREE
// AUTHOR: Mert Eldemir

// Look for visualization of Red Black Tree: https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
// Learning Resourses:
// * https://www.udemy.com/course/datastructurescncpp/?couponCode=LOCLZDOFFPTRCTRL
// * https://www.happycoders.eu/algorithms/red-black-tree-java/

/*
    Red Black Tree Properties:

    1. It's Height Balanced Binary Search Trees, similart to 2-3-4 Tree
    2. Node is either RED or BLACK Color
    3. Root of a Tree is always BLACK
    4. NULL is also taken as BLACK
    5. Number of Blacks on Path from Root to the leafes are same
    6. RED node must not have RED children
    7. New Inserted node must be RED
    8. Height is logN <= h <= 2logN
        * minimum logN, maximum is double of logN

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
            * So the color (Red & Black) is only need to maintain the balancing rule of the tree, it do not directly modify shape of the tree as Rotation does.

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

typedef enum Color
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
    RBNode *parent;

    // default created node is always RED
    RBNode(int value) : value(value), color(RED), right(nullptr), left(nullptr) {};
};

class RedBlackTree
{
private:
    RBNode *Root;

private:
    RedBlackTree(int value) : Root(new RBNode(value)) {};

    void rightRotation(RBNode *current)
    {
        /*
            Right Rotation
            Rotation performend on current (c), currentLeft (cl), currentLeftRight (clr)

            Before:

                p
                |
                c
               /
             cl
               \
               clr

            After:

                p
                |
               cl
               / \
             ..   c
                 /
               clr

            c, cl, clr parrents (p) are changed, we must update them
        */

        RBNode *parent = current->parent;
        RBNode *currLeft = current->left;
        RBNode *currLeftRight = currLeft->right;

        // rotation
        current->left = currLeftRight;
        currLeft->right = current;

        // update parents
        current->parent = currLeft;
        if (currLeftRight != nullptr)
        {
            currLeftRight->parent = current;
        }

        // there was a parrent (p) of current (c); it was on left or right we don't know yet. Now new child of parrent (p) is currentLeft (cl).
        replaceParentChild(parent, current, currLeft);
    }

    void leftRotation(RBNode *current)
    {
        /*
            Left Rotation
            Rotation performend on current (c), currentRight (cr), currentRightLeft (crl)

            Before:

               p
               |
               c
                \
                cr
               /
             crl

            After:

                p
                |
               cr
              /  \
             c   ..
              \
             crl

             c, cr, crl parents (p) are changed, we must update them
        */

        RBNode *parent = current->parent;
        RBNode *currRight = current->right;
        RBNode *currRightLeft = currRight->left;

        // rotation
        current->right = currRightLeft;
        currRight->left = current;

        // update parents
        current->parent = currRight;
        if (currRightLeft != nullptr)
        {
            currRightLeft->parent = current;
        }

        // there was a parrent (p) of current (c); it was on left or right we don't know yet. Now new child of parrent (p) is currentRight (cr).
        replaceParentChild(parent, current, currRight);
    }

    void replaceParentChild(RBNode *parent, RBNode *oldChild, RBNode *newChild)
    {
        if (parent == nullptr)
        {
            // oldChild was the Root
            Root = newChild;
        }
        else if (oldChild == parent->left)
        {
            // oldChild was on left from parent
            parent->left = newChild;
        }
        else if (oldChild == parent->right)
        {
            // oldChild was on right from parent
            parent->right = newChild;
        }
        else
        {
            throw std::logic_error("Did not find the node's parent");
        }
    }

    RBNode *searchUtil(const int val)
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

    RBNode *insertUtil(const int val)
    {
        RBNode *foundNode = searchUtil(val);

        if (foundNode != nullptr)
        {
            throw std::logic_error(fmt::format("Red Black Tree already contains node with value: {}", val));
        }
    }

    void levelOrderUtil(RBNode *root)
    {
        std::queue<RBNode *> treeQueue;
        treeQueue.push(root);

        while (!treeQueue.empty())
        {
            RBNode *front = treeQueue.front();
            treeQueue.pop();

            std::cout << front->value << " ";

            if (front->left != nullptr)
            {
                treeQueue.push(front->left);
            }

            if (front->right != nullptr)
            {
                treeQueue.push(front->right);
            }
        }
    }

    void inorderUtil(RBNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        inorderUtil(root->left);
        std::cout << root->value << " ";
        inorderUtil(root->right);
    }

public:
    RBNode *Search(const int val)
    {
        searchUtil(val);
    }

    RBNode *Insert(const int val)
    {
        insertUtil(val);
    }

    void levelOrder()
    {
        levelOrderUtil(Root);
    }

    void inorder()
    {
        inorderUtil(Root);
    }
};

int main()
{
    return 0;
}