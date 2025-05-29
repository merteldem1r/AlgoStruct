# 2-3 Trees - Data Structure

## What is a 2-3 Tree?

A **2-3 Tree** is a type of balanced search tree where every internal node can have either:

- **2 nodes (2-node)**: containing one data element and two children
- **3 nodes (3-node)**: containing two data elements and three children

It maintains strict **balance**, meaning that:

- All leaves are at the same depth (perfectly balanced)
- Insertion and deletion operations result in restructuring to maintain balance

### Node Types

- **2-node**: One data element, two children

  ```
     [10]
    /    \
  <10    >10
  ```

- **3-node**: Two data elements, three children

  ```
     [10 | 20]
    /   |    \
  <10 10-20  >20
  ```

---

## Properties of 2-3 Trees

- **Search Time Complexity**: O(log n)
- **Insertion/Deletion Time Complexity**: O(log n)
- **Height-balanced**: Ensures consistent performance
- **No skewing**: Nodes are merged or split uniformly

### Additional Properties

- **2-3 Trees are Multiway Search Trees with Degree 3**

  - Binary Search Tree (BST) has degree 2 (each node has 2 children)
  - Any structure with a degree greater than 2 is considered a Multiway Tree

- **B-Tree Relationship**

  - B-Trees are height-balanced search trees
  - A 2-3 Tree can be considered a B-Tree of degree 3
  - In a B-Tree, every node must have at least $degree / 2$ children

    - For example, a B-Tree of degree 5: $5 / 2$ = 2.5 → rounded up = 3 minimum children

---

## Rules of 2-3 Trees

- All leaf nodes must be at the same level
- Every internal node must have at least 2 children

  - As per the B-Tree rule with degree 3: $3 / 2$ = 1.5 → rounded up = 2 children minimum

- No duplicate keys are allowed (a property of all standard search trees)

### Node Structure

```
            |k1|k2|
          /    |    \
        l      m      n
```

- When 3 children are present, 2 keys are required: k1 and k2
- Keys within a node must be sorted: k1 < k2
- Tree ordering is defined as:

  - Keys in **l** < k1
  - Keys in **m** are between k1 and k2: k1 < m < k2
  - Keys in **n** > k2

Final ordered arrangement:

```
    l < k1 < m < k2 < n
```

---

## Example Insertions

Build a 2-3 Tree by inserting the values:

10, 20, 5, 6, 12

Step-by-step:

1. Insert 10 → Root becomes a 2-node \[10]
2. Insert 20 → Root becomes a 3-node \[10 | 20]
3. Insert 5 → Node \[10 | 20] splits into two 2-nodes and creates new root \[10]

```
       [10]
      /    \
   [5]    [20]
```

4. Insert 6 → Goes to left child \[5], becomes \[5 | 6]
5. Insert 12 → Goes to right child \[20], becomes \[12 | 20]

```
       [10]
      /    \
 [5 | 6] [12 | 20]
```

All leaves remain at the same level.

---

## Comparison With Other Trees

### 2-3 Tree vs AVL Tree

| Feature            | 2-3 Tree                   | AVL Tree                    |
| ------------------ | -------------------------- | --------------------------- |
| Balance Method     | Multi-way nodes            | Rotations                   |
| Insertion/Deletion | Simpler with splits/merges | Complex due to rotations    |
| Balance Guarantee  | Strict                     | Strict                      |
| Use Case           | Simpler implementations    | Faster search in some cases |

### 2-3 Tree vs Red-Black Tree

| Feature           | 2-3 Tree                 | Red-Black Tree         |
| ----------------- | ------------------------ | ---------------------- |
| Conceptual Match  | Equivalent to Red-Black  | Equivalent to 2-3 Tree |
| Implementation    | More intuitive structure | Efficient binary tree  |
| Balance Guarantee | Strict                   | Relaxed                |

### 2-3 Tree vs B-Tree

| Feature          | 2-3 Tree                | B-Tree (Order M)         |
| ---------------- | ----------------------- | ------------------------ |
| Branching Factor | 2 or 3                  | M (can be large)         |
| Used In          | Memory-based structures | Disk-based systems       |
| Node Capacity    | Fixed (2 or 3 children) | Variable (many children) |

---

## Use Cases of 2-3 Trees

- **Databases**: Internally in memory when predictable performance is needed
- **Functional programming**: Immutable and persistent data structures often use variants of 2-3 Trees
- **Compilers**: Symbol table management
- **Telecommunications**: Efficient routing table updates

---

## Strengths and Limitations

### Strengths

- Perfectly balanced tree structure
- Easy to implement conceptually
- Predictable performance

### Limitations

- Less cache-friendly than binary trees
- Can be less efficient in low-memory systems

---
