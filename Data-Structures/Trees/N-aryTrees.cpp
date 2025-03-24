#include <iostream>

/*
    Generic Trees (N-ary Trees)

    Generic trees are a collection of nodes where each node is a data structure that consists of records and a list of references to its children(duplicate references are not allowed). Unlike the linked list, each node stores the address of multiple nodes. Every node stores address of its children and the very first node’s address will be stored in a separate pointer called root.

    The Generic trees are the N-ary trees which have the following properties:

        1. Many children at every node.
        2. The number of nodes for each node is not known in advance.

    Info take from: https://www.geeksforgeeks.org/generic-treesn-array-trees/
*/

// Node with at most 6 children
struct Node
{
    int val;
    Node *firstchild;
    Node *secondchild;
    Node *thirdchild;
    Node *fourthchild;
    Node *fifthchild;
    Node *sixthchild;
};

/*

Disadvantages of the above representation are:

    Memory Wastage – All the pointers are not required in all the cases. Hence, there is lot of memory wastage.
    Unknown number of children – The number of children for each node is not known in advance.

*/

// Better Approach (using Dynamic Array)
struct Node
{
    int val;
    std::vector<int> children;

    Node(int value) : val(value);
};

/*
    We can use Dynamic Arrays for storing the address of children. We can randomly access any child’s address and the size of the vector is also not fixed.
*/

// Efficient Approach
struct Node
{
    int data;
    Node *firstChild;
    Node *nextSibling;
};

/*
First child / Next sibling representation

In the first child/next sibling representation, the steps taken are:

At each node-link the children of the same parent(siblings) from left to right.

Remove the links from parent to all children except the first child.
Since we have a link between children, we do not need extra links from parents to all the children. This representation allows us to traverse all the elements by starting at the first child of the parent.

Advantages: 

    Memory efficient – No extra links are required, hence a lot of memory is saved.
    Treated as binary trees – Since we are able to convert any generic tree to binary representation, we can treat all generic trees with a first child/next sibling representation as binary trees. Instead of left and right pointers, we just use firstChild and nextSibling.
    Many algorithms can be expressed more easily because it is just a binary tree.
    Each node is of fixed size ,so no auxiliary array or vector is required.

*/

int main()
{
    return 0;
}