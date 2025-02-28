# Heap (Data Structure)

In computer science, a **Heap** is a specialized tree-based data structure that satisfies the **heap property**. A heap can be either a **Max Heap** or a **Min Heap**:

- **Max Heap**: For any given node `C`, if `P` is the parent node of `C`, then the key (value) of `P` is greater than or equal to the key of `C`.
- **Min Heap**: For any given node `C`, if `P` is the parent node of `C`, then the key (value) of `P` is less than or equal to the key of `C`.

The node at the "top" of the heap (with no parents) is called the **root node**.

---

## Heap Properties

1. **Complete Binary Tree**: A heap is always a complete binary tree, meaning all levels are fully filled except possibly the last level, which is filled from left to right. This ensures the height of the tree is always **log N**.
2. **Heap Property**:
   - **Max Heap**: Every node has a value greater than or equal to its descendants.
   - **Min Heap**: Every node has a value less than or equal to its descendants.
3. **Efficient Access**: The root node always contains the maximum (in a Max Heap) or minimum (in a Min Heap) element, allowing for efficient access to the largest or smallest element.
4. **Array Representation**: Heaps are usually represented as arrays:
   - The root element is at **`arr[0]`**.
   - For any node at index `i`:
     - Parent node: **`arr[(i - 1) / 2]`**
     - Left child node: **`arr[(2 * i) + 1]`**
     - Right child node: **`arr[(2 * i) + 2]`**

---

## Basic Operations

1. **Insert**: Adds a new element to the heap while maintaining the heap property.
2. **Delete**: Removes the root element (max in Max Heap or min in Min Heap) and restores the heap property.
3. **Peek**: Returns the root element without removing it.
4. **Heapify**: Converts an array into a heap.
5. **Size**: Returns the number of elements in the heap.
6. **IsEmpty**: Checks if the heap is empty.

---

## Use Cases

1. **Priority Queues**: Heaps are commonly used to implement priority queues, where elements are processed based on their priority (highest or lowest value).
2. **Heap Sort**: A sorting algorithm that uses a heap to sort elements in ascending or descending order.
3. **Dijkstra's Algorithm**: Heaps are used to efficiently extract the minimum distance node in graph traversal algorithms.
4. **K-th Largest/Smallest Element**: Heaps can efficiently find the K-th largest or smallest element in a dataset.
5. **Merge K Sorted Lists**: Heaps can merge multiple sorted lists into a single sorted list efficiently.

---

## Pros and Cons

### Pros

- **Efficient Operations**: Insertion and deletion operations take **O(log N)** time, and accessing the root element takes **O(1)** time.
- **Space Efficient**: Heaps are implemented using arrays, so they use minimal memory.
- **Dynamic Size**: Heaps can grow and shrink dynamically as elements are added or removed.
- **Versatile**: Can be used for both Max Heap and Min Heap implementations.

### Cons

- **Limited Access**: Only the root element can be accessed directly. Accessing other elements requires traversing the heap.
- **Not Ideal for Searching**: Searching for an element in a heap takes **O(N)** time, as it is not designed for random access.

---

## Complexity Analysis

| Operation     | Time Complexity | Space Complexity |
| ------------- | --------------- | ---------------- |
| Insert        | O(log N)        | O(1)             |
| Delete (Root) | O(log N)        | O(1)             |
| Peek (Root)   | O(1)            | O(1)             |
| Heapify       | O(N)            | O(1)             |
| Size          | O(1)            | O(1)             |
| IsEmpty       | O(1)            | O(1)             |

---


