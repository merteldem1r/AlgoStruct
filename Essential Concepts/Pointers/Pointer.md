# Pointers in C++

![PointersinC](https://github.com/user-attachments/assets/bf3505fa-fff8-4554-a299-7c3be85e55bc)

Pointers are symbolic representations of addresses. They enable programs to simulate call-by-reference as well as to create and manipulate dynamic data structures. Iterating over elements in arrays or other data structures is one of the main use of pointers.

The address of the variable you’re working with is assigned to the pointer variable that points to the same data type (such as an int or string).

# Memory in C++

![1724cf83-a8ad-4ad5-aeca-0311114a819c_memory_alloc_cpp](https://github.com/user-attachments/assets/136dd427-be29-44e6-8229-3e3e1f01a76e)


**Heaps are memory areas allocated to each program. Memory allocated to heaps can be dynamically allocated, unlike memory allocated to stacks.**

Program should have a pointer on the Stack to access anything in the Heap

**Advantages of heap memory:**

- Heap doesn’t have any limit on memory size.
- It allows you to access variables globally.
- Garbage collection runs on the heap memory to free the memory used by the object.
- The heap method is also used in the Priority Queue.

**Disadvantages of heap memory:**

- It takes too much time to execute compared to the stack.
- It takes more time to compute.
- It can provide the maximum memory an OS can provide
- Memory management is more complicated in heap memory as it is used globally.
