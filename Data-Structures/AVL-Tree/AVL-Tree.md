# AVL Tree - Data Structure

## Introduction
AVL Tree (Adelson-Velsky and Landis Tree) is a **self-balancing Binary Search Tree (BST) in which the difference between heights of left and right subtrees cannot be more than one for all nodes**. Named after its inventors, Georgy Adelson-Velsky and Evgenii Landis, it was the first dynamically balanced binary search tree introduced in 1962.

## What is an AVL Tree?
An AVL Tree is a binary search tree that maintains its height to be logarithmic in terms of the number of nodes it contains. It achieves this by maintaining a **balance factor** for each node, which helps in keeping the tree balanced during insertions and deletions.

## Why Use AVL Trees?
Binary Search Trees can degenerate into linked lists if not balanced, resulting in O(n) time complexity for operations. AVL trees guarantee **O(log n)** time for insertion, deletion, and lookup, by ensuring that the tree remains balanced at all times.

## Properties of AVL Trees
1. It is a binary search tree.
2. Balance factor of each node is either -1, 0, or +1.
3. Rotations are used to maintain the balance factor.
4. Height of an AVL tree with n nodes is strictly O(log n).

## Balancing Factor
The **balance factor** of a node in an AVL tree is defined as:
```
Balance Factor = height(left subtree) - height(right subtree)
```
Valid balance factor values:
- -1: Right subtree is taller
-  0: Both subtrees are equal
- +1: Left subtree is taller

If the balance factor becomes less than -1 or greater than +1, the tree needs rebalancing.

## Rotations in AVL Trees
To maintain balance, AVL trees use four types of rotations:

### Single Rotations
- **Right Rotation (LL Rotation)**: Performed when a node is inserted in the left subtree of the left child.
- **Left Rotation (RR Rotation)**: Performed when a node is inserted in the right subtree of the right child.

### Double Rotations
- **Left-Right Rotation (LR Rotation)**: Performed when a node is inserted in the right subtree of the left child.
- **Right-Left Rotation (RL Rotation)**: Performed when a node is inserted in the left subtree of the right child.

### Visual Examples
```
LL Rotation:
    z                       y
   / \                    /   \
  y   T4      =>         x     z
 / \                          / \
x   T3                      T3  T4

RR Rotation:
  z                         y
 / \                      /   \
T1   y        =>         z     x
    / \                  / \
   T2  x                T1 T2
```

## Insertion in AVL Trees
1. Perform standard BST insertion.
2. Update balance factors.
3. If a node becomes unbalanced:
   - Perform appropriate rotation(s) to rebalance the tree.

## Deletion in AVL Trees
1. Perform standard BST deletion.
2. Update balance factors.
3. If any node becomes unbalanced:
   - Perform appropriate rotation(s).
   - Rebalancing might be required all the way up to the root.

## Time and Space Complexity
| Operation | Time Complexity | Space Complexity |
|-----------|------------------|------------------|
| Search    | O(log n)         | O(n)             |
| Insert    | O(log n)         | O(n)             |
| Delete    | O(log n)         | O(n)             |

## Use Cases and Applications
- **Databases**: AVL trees are used to maintain indexes with fast insertions and deletions.
- **File Systems**: Used in file indexing systems where reads and writes must be fast and balanced.
- **Network Routing Algorithms**: Routing tables require balanced search trees for efficiency.
- **Memory Allocation**: AVL trees can be used for allocating and freeing memory blocks dynamically.
- **Gaming**: Used in game trees where quick access and balanced structure are essential.

## Real World Example
Imagine a multiplayer game server maintaining a leaderboard. When thousands of players are scoring in real-time, an AVL tree can maintain the sorted score list while allowing efficient updates (insert/delete scores) and fast lookups (find top N players).

## Comparison with Other Trees
| Feature        | AVL Tree       | Red-Black Tree  | Splay Tree     | Binary Heap     |
|----------------|----------------|------------------|----------------|------------------|
| Balance Strictness | More Strict  | Less Strict     | Adaptive       | Not BST         |
| Insertion Time | O(log n)       | O(log n)         | Amortized O(log n) | O(log n)     |
| Deletion Time | O(log n)       | O(log n)         | Amortized O(log n) | O(log n)     |
| Lookup Time   | O(log n)       | O(log n)         | Amortized O(log n) | N/A            |

## Conclusion
AVL Trees are powerful data structures designed to maintain balance in binary search trees. While they may be slightly more complex than other self-balancing trees like Red-Black Trees, they offer better balance and consistent performance for operations. They are widely used in systems where search, insert, and delete operations must be performed rapidly and predictably.

---

