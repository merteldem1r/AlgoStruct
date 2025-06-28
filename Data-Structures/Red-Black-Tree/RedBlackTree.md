# Red-Black Tree Data Structure

## Introduction

A Red-Black Tree is a type of self-balancing binary search tree (BST).  
It keeps the tree approximately balanced by enforcing specific coloring rules.  
Because of this balance, operations such as search, insertion, and deletion have a guaranteed time complexity of O(log n).

A Red-Black Tree was invented by Rudolf Bayer in 1972 and later modified by Leonidas Guibas and Robert Sedgewick in 1978.  
It is widely used in the implementation of associative containers like maps and sets in various programming libraries.

## Why Use a Red-Black Tree

A normal binary search tree can degrade to a linked list in the worst case (for example, inserting sorted data into an unbalanced BST).  
This leads to poor performance: O(n) for search, insert, or delete.

A Red-Black Tree guarantees that the height of the tree is no more than 2*log₂(n + 1).  
Thus, the worst-case time complexity for basic dynamic set operations remains O(log n).

In summary, a Red-Black Tree provides:
- Good worst-case performance for insertion, deletion, and search
- Automatic balancing without requiring complete rebalancing on every operation
- Simpler implementation than some other balanced trees (like AVL)

## Properties

A Red-Black Tree must satisfy the following properties:

1. **Every node is either red or black.**
2. **The root is always black.**
3. **All leaves (NIL or null nodes) are black.**
4. **If a node is red, then both its children are black.**
   - This means no two red nodes can be adjacent.
5. **Every path from a given node to any of its descendant NIL nodes contains the same number of black nodes.**
   - This count is called the *black-height*.

These properties ensure that the longest path from the root to a leaf is no more than twice as long as the shortest path.

## How It Works

A Red-Black Tree works by applying color rules and structural rotations during insertion and deletion to maintain its balancing properties.

- If an insertion or deletion violates the properties, the tree is "fixed" using recoloring and tree rotations.
- Rotations change the structure locally but preserve the BST property.

This approach guarantees the tree remains balanced enough to ensure logarithmic performance.

## Operations

### Insertion

1. Insert the new node as a red leaf in the same way you would insert into a normal BST.
2. If the parent of the new node is black, the tree remains valid.
3. If the parent is red, this violates the Red-Black properties. Fixes are done using recoloring and rotations.
4. The fixing process moves up the tree until all properties are restored.

### Deletion

1. If the node to delete has at most one non-NIL child, remove it as in a BST.
2. If the node is black, its removal might violate the properties, leading to an imbalance in black heights.
3. Various cases are handled using recoloring and rotations to restore the properties.
4. Deletion fixes are more complex than insertion fixes due to more possible cases.

### Rotations

Red-Black Trees use two basic rotation operations:

- **Left Rotation**: pivots a node with its right child.
- **Right Rotation**: pivots a node with its left child.

Rotations are local operations that change the structure without violating the BST property.

## Comparison with Other Trees

### Red-Black Tree vs Binary Search Tree

| Feature            | Binary Search Tree | Red-Black Tree           |
|--------------------|--------------------|--------------------------|
| Balancing          | Not guaranteed     | Self-balancing           |
| Worst-case time    | O(n)               | O(log n)                 |
| Operations         | Simple to implement | Slightly more complex due to fixing |
| Use cases          | Static data sets   | Dynamic, frequently updated sets |

A plain BST is only efficient if the input data is random or if balancing is done manually.

### Red-Black Tree vs AVL Tree

Both are self-balancing BSTs but differ in their balancing approach.

| Feature            | AVL Tree               | Red-Black Tree             |
|--------------------|------------------------|----------------------------|
| Balance Strictness | Stricter balance       | Less strict balance        |
| Rebalancing Cost   | More rotations         | Fewer rotations on average |
| Search Performance | Faster lookups (tighter height) | Slightly slower due to looser balance |
| Insertion/Deletion | More costly balancing  | Less costly balancing      |
| Usage Preference   | Good for read-heavy operations | Good for write-heavy operations |

In practice, both trees offer O(log n) operations but trade off strict balance for performance of updates.

## Use Cases

Red-Black Trees are widely used in real-world systems.  
For example:
- The C++ STL `map` and `set` use Red-Black Trees for ordered containers.
- Java’s `TreeMap` and `TreeSet` are backed by Red-Black Trees.
- Many operating systems use them in scheduling and memory management.
