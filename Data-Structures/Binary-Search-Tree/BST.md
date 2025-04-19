# Binary Search Trees (BST) - A Deep Dive

## Introduction
A Binary Search Tree (BST) is a data structure that facilitates fast lookup, addition, and removal of items. It maintains a dynamic set of numbers in a sorted manner, ensuring that search operations can be performed efficiently.

---

## Definition
A **Binary Search Tree** is a binary tree in which each node contains a key (value), and satisfies the following properties:

- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

---

## Basic Terminology
- **Node**: An element in the tree.
- **Root**: The topmost node of the tree.
- **Leaf**: A node with no children.
- **Parent**: A node that has branches to other nodes.
- **Child**: A node connected and under another node.
- **Subtree**: A tree formed by a node and its descendants.

---

## Binary Search Tree Properties
1. **Ordering Property**: All left descendants are less than the node; all right descendants are greater.
2. **Recursive Nature**: Left and right subtrees are also BSTs.
3. **No Duplicates**: A standard BST does not contain duplicate values.
4. **Dynamic Size**: BSTs can grow and shrink with insertions and deletions.

---

## Operations on BST

### Search
To find a value in a BST, start at the root:
```text
If value == root.key, return node
If value < root.key, search left subtree
If value > root.key, search right subtree
```

### Insertion
Follow the BST ordering property recursively and insert at the proper position as a new leaf node.

### Deletion
Deletion involves three cases:
1. Node has no children – simply remove it.
2. Node has one child – replace it with its child.
3. Node has two children – replace it with its in-order successor or predecessor.

---

## Time Complexity
| Operation | Best Case | Average Case | Worst Case |
|-----------|-----------|--------------|-------------|
| Search    | O(log n)  | O(log n)     | O(n)        |
| Insert    | O(log n)  | O(log n)     | O(n)        |
| Delete    | O(log n)  | O(log n)     | O(n)        |

> Note: Worst-case occurs in a skewed tree where the tree becomes a linked list.

---

## Visual Structure
### Example BST
```
        50
       /  \
     30    70
    /  \  /  \
  20  40 60  80
```

### Insertion of 25
```
        50
       /  \
     30    70
    /  \  /  \
  20  40 60  80
   \
    25
```

### Deletion of 70
```
        50
       /  \
     30    80
    /  \  /  
  20  40 60  
   \
    25
```

---

## Balanced vs Unbalanced BST
- **Balanced BST**: Height is approximately log(n), ensuring optimal operations.
- **Unbalanced BST**: Degenerates into a linked list in worst-case, reducing efficiency.
- Solutions: Self-balancing trees like AVL Tree, Red-Black Tree.

---

## Traversal Methods

### Inorder (LNR)
- Visit left subtree
- Visit node
- Visit right subtree
- Yields values in ascending order in BST.

### Preorder (NLR)
- Visit node
- Visit left subtree
- Visit right subtree

### Postorder (LRN)
- Visit left subtree
- Visit right subtree
- Visit node

### Level Order
- Breadth-First Search using a queue.

---

## Common Use Cases
- Symbol tables and dictionaries
- Priority queues (with additional balancing)
- Implementing sets and maps
- Autocompletion engines
- Memory management systems

---

## References
- Introduction to Algorithms by Cormen et al.
- Data Structures and Algorithm Analysis by Mark Allen Weiss
- [GeeksforGeeks: Binary Search Tree](https://www.geeksforgeeks.org/binary-search-tree-data-structure/)
- [Wikipedia: Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree)

