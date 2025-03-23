# Tree Data Structure

## Introduction

A **Tree** is a hierarchical data structure that consists of nodes connected by edges. It is widely used in computer science for organizing data efficiently, enabling fast searching, insertion, and deletion operations.

Unlike linear data structures (e.g., arrays, linked lists), a tree follows a hierarchical approach where each node can have multiple children but only one parent (except for the root node, which has no parent).

---

## Terminology

### **Root**
The topmost node in a tree (e.g., `A` in the example below).

### **Parent & Child**
A **parent** node has one or more **children** nodes. Example: `A` is the parent of `B` and `C`.

### **Ancestors & Descendants**
- **Ancestors**: All nodes on the path from a given node to the root.
- **Descendants**: All nodes below a given node.
  
#### **Example:**
```
        A
       / \
      B   C
     / \   \
    D   E   F
```
- **Ancestors of D**: `B`, `A`
- **Descendants of B**: `D`, `E`

### **Internal & External (Leaf) Nodes**
- **Internal Nodes**: Nodes that have at least one child (e.g., `A`, `B`, `C`).
- **External Nodes (Leaf Nodes)**: Nodes that have no children (e.g., `D`, `E`, `F`).

### **Degree**
- The **degree of a node** is the number of children it has.
- The **degree of a tree** is the maximum degree of any node in the tree.

### **Depth & Height**
- **Depth of a node**: The number of edges from the root to that node.
- **Height of a node**: The number of edges in the longest path from that node to a leaf.
- **Height of a tree**: The height of the root node.

### **Forest**
A **forest** is a collection of disjoint trees.

#### **Example:**
If we remove the root `A` from the tree above, we get:
```
      B       C
     / \       \
    D   E       F
```
Now `{B → (D, E)}` and `{C → (F)}` form a **forest**.

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
