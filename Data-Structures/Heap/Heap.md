# Heap (Data Structure)

![Data Structures Algorithms](https://github.com/user-attachments/assets/6a5c9b96-95ac-4b61-8700-d05e1f509723)

In computer science, a **Heap** is a tree-based data structure that satisfies the heap property: In a max heap, for any given node C, if P is the parent node of C, then the key (the value) of P is greater than or equal to the key of C. In a min heap, the key of P is less than or equal to the key of C. The node at the "top" of the heap (with no parents) is called the root node.

## Heap Properties:

- It's complete binary tree which means always the height of the tree will be log N only
- Max Heap: Every node should have the element greater or equal to it's all descendants.
- Min Heap: Every node should have the element less or equal to it's all descendants.
- From the Heap you can only delete largest (for Max Heap) or smallets (for Min Heap), you can not delete other elements

- Heaps usually represented as arrays where:
  - Root element will be at **arr[0]**
  - **arr[(i - 1) / 2]** returns the PARENT node
  - **arr[(2 * i) + 1]** returns the LEFT child node
  - **arr[(2 * i) + 2]** return the RIGHT child node
