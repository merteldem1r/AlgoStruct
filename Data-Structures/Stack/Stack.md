# Stack Data Structure

## Overview

A **Stack** is a linear data structure that follows the **Last In, First Out (LIFO)** principle. This means that the last element added to the stack will be the first one to be removed. Stacks are commonly used in various applications such as parsing expressions, managing function calls, and implementing undo mechanisms.

---

## Table of Contents

1. [Basic Operations](#basic-operations)
2. [Implementation](#implementation)
3. [Use Cases](#use-cases)
4. [Pros and Cons](#pros-and-cons)
5. [Complexity Analysis](#complexity-analysis)
6. [Example Code](#example-code)

---

## Basic Operations

A stack typically supports the following operations:

- **Push**: Adds an element to the top of the stack.
- **Pop**: Removes and returns the top element from the stack.
- **Peek (or Top)**: Returns the top element without removing it.
- **IsEmpty**: Checks if the stack is empty.
- **Size**: Returns the number of elements in the stack.

---

## Implementation

Stacks can be implemented using various underlying data structures, such as:

- **Arrays**: A fixed-size array can be used to implement a stack. However, it has a limitation on the maximum size.
- **Dynamic Arrays (Vectors)**: A dynamic array can resize itself when the stack grows beyond its initial capacity.
- **Linked Lists**: A singly linked list can be used to implement a stack, allowing for dynamic resizing and efficient operations.

---

## Use Cases

1. **Function Call Management**: Stacks are used to manage function calls in programming languages. When a function is called, its context is pushed onto the stack, and when the function returns, its context is popped off the stack.
2. **Expression Evaluation**: Stacks are used to evaluate expressions, such as infix, postfix, and prefix notations.
3. **Undo Mechanism**: Stacks can be used to implement undo functionality in applications like text editors. Each action is pushed onto the stack, and undoing an action involves popping the last action from the stack.
4. **Backtracking Algorithms**: Stacks are used in algorithms that require backtracking, such as depth-first search (DFS) in graph traversal.
5. **Syntax Parsing**: Stacks are used in compilers to check for balanced parentheses, brackets, and braces in code.

---

## Pros and Cons

### Pros

- **Simple and Efficient**: The basic operations (push, pop, peek) are efficient and have a time complexity of O(1).
- **LIFO Principle**: The LIFO principle is intuitive and useful in many real-world scenarios, such as managing function calls or undo operations.
- **Dynamic Size**: When implemented using linked lists or dynamic arrays, stacks can grow and shrink dynamically.

### Cons

- **Limited Access**: Stacks only allow access to the top element. Accessing elements in the middle of the stack is not possible without popping elements.
- **Fixed Size in Array Implementation**: If implemented using a fixed-size array, the stack has a maximum capacity, which can lead to stack overflow if exceeded.

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| --------- | --------------- | ---------------- |
| Push      | O(1)            | O(1)             |
| Pop       | O(1)            | O(1)             |
| Peek      | O(1)            | O(1)             |
| IsEmpty   | O(1)            | O(1)             |
| Size      | O(1)            | O(1)             |

---

## Example Code

Here is an example implementation of a stack using C++:

```cpp
#include <iostream>
#include <stdexcept>
#include <vector>

class Stack {
private:
    std::vector<int> stack;

public:
    // Push an element onto the stack
    void push(int item) {
        stack.push_back(item);
    }

    // Pop the top element from the stack
    int pop() {
        if (is_empty()) {
            throw std::out_of_range("Pop from an empty stack");
        }
        int topElement = stack.back();
        stack.pop_back();
        return topElement;
    }

    // Peek at the top element without removing it
    int peek() {
        if (is_empty()) {
            throw std::out_of_range("Peek from an empty stack");
        }
        return stack.back();
    }

    // Check if the stack is empty
    bool is_empty() const {
        return stack.empty();
    }

    // Get the size of the stack
    size_t size() const {
        return stack.size();
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.peek() << std::endl;  // Output: 30
    std::cout << "Stack size: " << stack.size() << std::endl;    // Output: 3

    stack.pop();
    std::cout << "Top element after pop: " << stack.peek() << std::endl;  // Output: 20
    std::cout << "Stack size after pop: " << stack.size() << std::endl;   // Output: 2

    return 0;
}
```


