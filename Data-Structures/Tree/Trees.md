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


## Types of Binary Trees

### **Full (Strict) Binary Tree**
- A tree where **every node** has either **0 or 2 children**.
- Example:
```
       1
      / \
     2   3
    / \ 
   4  5 
```
- **Nodes (n) & Height (h) Relation:** `n = 2h+1 - 1`

### **Perfect Binary Tree**
- A full binary tree where **all leaf nodes are at the same level**.
- Example:
```
       1
      / \
     2   3
    / \ / \
   4  5 6  7
```
- **Nodes (n):** `2^(h+1) - 1`
- **Height (h):** `log2(n + 1) - 1`

### **Complete Binary Tree**
- A binary tree where **all levels except possibly the last are completely filled**, and all nodes in the last level are **as left as possible**.
- Example:
```
       1
      / \
     2   3
    / \  /
   4  5 6
```
- **Heap Data Structure** is based on complete binary trees.

### **Balanced Binary Tree**
- A tree where the **height difference** between left and right subtrees of any node is **at most 1**.
- Example (Balanced AVL Tree):
```
       10
      /  \
     5    15
    / \  /  \
   2   7 12  17
```
- **Height is O(log n)** for efficient searching.

### **Degenerate (Skewed) Binary Tree**
- A tree where **every node has only one child**.
- Can be **left-skewed** or **right-skewed**.
- **Worst-case height = O(n)** (like a linked list).
- Example:
```
       1        1
      /          \
     2            2
    /              \
   3                3
```

### **Binary Search Tree (BST)**
- A **sorted** binary tree where:
  - Left subtree contains **smaller** values.
  - Right subtree contains **greater** values.
- Example:
```
       8
      / \
     3   10
    / \    \
   1   6    14
      / \   /
     4   7 13
```
- **Search, Insert, Delete:** `O(log n)` (if balanced), `O(n)` (if skewed).

---

## Important Formulas
| Property | Formula |
|----------|---------|
| Max nodes at height h | `2^(h+1) - 1` |
| Min height for n nodes | `log2(n + 1) - 1` |
| Min nodes for height h | `h + 1` |
| Max nodes at level k | `2^(k-1)` |
| Leaf nodes in a full tree | `(n + 1) / 2` |

---

## Special Binary Trees

### **AVL Tree**
- A self-balancing BST where height difference between left & right subtrees is at most **1**.
- Operations like **insertion** & **deletion** trigger **rotations** to maintain balance.
- **Time Complexity:** `O(log n)`.

### **Red-Black Tree**
- A self-balancing BST with additional **color property (Red/Black)**.
- No path from root to a leaf is more than **twice as long** as any other.
- Used in **map, set, multiset, multimap** in **C++ STL**.

### **Heap (Min/Max Heap)**
- A complete binary tree where:
  - **Min-Heap:** Parent is smaller than children.
  - **Max-Heap:** Parent is larger than children.
- Used in **priority queues**.
- **Insertion & Deletion:** `O(log n)`.

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
