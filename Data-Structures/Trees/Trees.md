# Tree Data Structure

## Introduction

A **Tree** is a hierarchical data structure that consists of nodes connected by edges. It is widely used in computer science for organizing data efficiently, enabling fast searching, insertion, and deletion operations.

Unlike linear data structures (e.g., arrays, linked lists), a tree follows a hierarchical approach where each node can have multiple children but only one parent (except for the root node, which has no parent).

---

## Terminology

- **Node**: A single element in a tree that contains data and references to child nodes.
- **Root**: The topmost node in a tree (has no parent).
- **Parent**: A node that has child nodes.
- **Child**: A node that descends from another node (parent).
- **Sibling**: Nodes that share the same parent.
- **Leaf Node**: A node that has no children.
- **Edge**: A connection between two nodes.
- **Depth**: The number of edges from the root node to a specific node.
- **Height**: The number of edges from a node to its deepest descendant.
- **Degree**: The number of children a node has.
- **Subtree**: A tree consisting of a node and its descendants.
- **Descendants**: descendants of a node refer to all the nodes that are directly or indirectly below it in the hierarchy. This includes its children, grandchildren, great-grandchildren, and so on.
- **Ancestors**: Ancestors of a node are all the nodes that come before it in the hierarchy, moving from the node upward toward the root.
- **Internal/External Nodes**: An internal node (also called a non-leaf node) is a node that has at least one child. In other words, it is not a leaf node. An internal node (also called a non-leaf node) is a node that has at least one child. In other words, it is not a leaf node.

---

## Types of Trees

1. **General Tree**: A tree where each node can have any number of children.
2. **Binary Tree**: A tree where each node has at most two children (left and right).
3. **Binary Search Tree (BST)**: A binary tree where the left child contains values less than the parent, and the right child contains values greater than the parent.
4. **Balanced Tree**: A tree where the height difference between the left and right subtrees is minimized.
5. **AVL Tree**: A self-balancing binary search tree where the difference in height between left and right subtrees is at most one.
6. **Red-Black Tree**: A self-balancing binary search tree with specific rules to maintain balance using red and black-colored nodes.
7. **Heap**: A tree-based structure satisfying the heap property (Min Heap, Max Heap).
8. **Trie (Prefix Tree)**: A tree used for storing strings efficiently, mainly in text search applications.
9. **B-Tree**: A self-balancing search tree optimized for databases and file systems.

---

## Use Cases

- **Hierarchical Data Representation**: Used to model hierarchical relationships, such as file systems.
- **Searching and Sorting**: Binary Search Trees (BST), AVL Trees, and Red-Black Trees optimize searching and sorting operations.
- **Databases**: B-Trees and B+ Trees are widely used in database indexing.
- **Artificial Intelligence**: Decision Trees are used in machine learning for classification.
- **Compilers**: Abstract Syntax Trees (AST) help in parsing expressions.
- **Networking**: Spanning Trees are used in network routing protocols.

---

## Real-World Examples

- **File System**: Directories and files are stored in a hierarchical tree structure.
- **HTML DOM (Document Object Model)**: Represents a webpage as a tree where each HTML element is a node.
- **Social Media Comments**: Nested comment threads are represented as a tree.
- **Organizational Hierarchy**: Employees and managers are structured in a tree format.
- **Routing Tables**: Used in networking to efficiently manage paths and connections.

---

## Tree Traversal Techniques

### 1. **Depth-First Search (DFS)**

DFS explores as far as possible along a branch before backtracking. There are three main types:

- **Preorder (Root, Left, Right)**
- **Inorder (Left, Root, Right)**
- **Postorder (Left, Right, Root)**

### 2. **Breadth-First Search (BFS) (Level Order Traversal)**

BFS explores all nodes at the present depth level before moving to the next level.

## Complexity Analysis

| Operation | Best Case | Average Case | Worst Case |
| --------- | --------- | ------------ | ---------- |
| Search    | O(log n)  | O(log n)     | O(n)       |
| Insert    | O(log n)  | O(log n)     | O(n)       |
| Delete    | O(log n)  | O(log n)     | O(n)       |

- For **balanced trees** (e.g., AVL, Red-Black), operations are **O(log n)**.
- For **unbalanced BSTs**, operations can degrade to **O(n)** in the worst case.

## References

- Introduction to Algorithms - Cormen et al.
- Data Structures and Algorithm Analysis - Mark Allen Weiss
- GeeksforGeeks, Wikipedia (for additional reading)
