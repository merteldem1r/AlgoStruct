#include<iostream>

// Creating Binary Tree

/*

    Binary Tree common features:

    •	Each node has at most two children (left and right).
	•	The root is the topmost node in the tree.
	•	Leaf nodes have no children (external nodes).
	•	Height is the longest path from root to a leaf.
	•	Depth of a node is its distance from the root.
	•	Binary trees can be balanced or unbalanced.
	•	Common types: Full, Complete, Perfect, Balanced, Degenerate.
	•	Used in searching, sorting, and hierarchical data representation.

*/

struct Node {
    Node* left;
    Node* right;
    int val;

    Node(int value) : left(nullptr), right(nullptr), val(value) {};
};

int main() {
    return 0;
}