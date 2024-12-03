# Essential Concepts and DSA using C / C++

![Data Structures Algorithms](https://github.com/user-attachments/assets/9d7eda38-a40f-4673-bef2-960c03522266)

DSA | Data Structures and Algorithms using C & C++ Essential Concepts like Pointers, OOP, Structures, References, Templates etc. with well explained comment lines and Readme files. Implementing all commonly used Data Structure from scratch and their Algorithms.

**Project divided into 3 topics. Essential Concepts, Data Structures and Algorithms. Each topic contain code examples with explained comment lines and Readme files.**

## Essential Concepts of C / C++

![2](https://github.com/user-attachments/assets/bbf5630d-c834-4b5a-8e1b-900b20252e96)

Essential concepts of C / C++ **before diving into DSA**. Arrays, Structures, OOP, Pointer and a lot more with explanation and example code.

### Array Basics

- Representation of Arrays in C & C++
- Declaring and initializing dynamic and static arrays

  Code: [arrays.cpp](Essential-Concepts/Arrays/arrays.cpp)

### Structures

Structures in C++ are user defined data types which are used to store group of items of non-similar data types.

- Understanging the concept of Structure in C++ / Manipulating members of the structures
- Creating struct objects in Stack and heap.

  Code: [structures.cpp](Essential-Concepts/Structures/structures.cpp)

### Pointers

**Pointers are symbolic representations of addresses.** They enable programs to simulate call-by-reference as well as to create and manipulate dynamic data structures. Iterating over elements in arrays or other data structures is one of the main use of pointers.

The address of the variable you’re working with is assigned to the pointer variable that points to the same data type (such as an int or string).

- Difference between Heap and Stack / Allocating & Deallocating Memory on Heap
- Creating and allocating memory on Heap and seeing difference between C style and C++ style

  Code: [pointers.cpp](Essential-Concepts/Pointers/pointers.cpp)
  </br>
  Readme: [Pointers.md](Essential-Concepts/Pointers/Pointers.md)

### Reference

When a variable is declared as a reference, it becomes an **alternative name for an existing variable.** A variable can be declared as a reference by putting ‘&’ in the declaration.

- Creating & Manipulating references to variables
- Use cases of references in for each blocks

  Code: [reference.cpp](Essential-Concepts/Reference/reference.cpp)
  </br>
  Readme: [Reference.md](Essential-Concepts/Reference/Reference.md)

### Functions

- Creating and calling functions & Formal and Actual parameters
- Parameter passing methods (by Value, Address, Reference)
- Functions that using and returning pointers
- Passing Arrays/Structures as parameters & Callback functions
  
  Code: [functions.cpp](Essential-Concepts/Functions/functions.cpp)
  </br>
  Readme: [Functions.md](Essential-Concepts/Functions/Functions.md)

### Converting C code to C++

- Difference between writing C and C++ code
- Rewriting structure based C code into OOP based C++ code

  Code: [c-code.c](Essential-Concepts/Converting-C-to-CPP/c-code.c) [cpp-code.cpp](Essential-Concepts/Converting-C-to-CPP/cpp-code.cpp)

### Scope Resolution

In programming, scope refers to the **context within which a variable or function is accessible**. C++ has several scopes, such as **global scope, local scope, class scope, and namespace scope**. When a variable or function is declared, it exists within a specific scope, and that scope defines where it can be accessed.

- :: operator and Scope Resolution
- Accessing Global Variables / Static Members / Namespaces
- Defining Class Member Functions Outside the Class

  Code: [scope-resolution.cpp](Essential-Concepts/Scope-Resolution/scope-resolution.cpp)
  </br>
  Readme: [ScopeResolution.md](Essential-Concepts/Scope-Resolution/ScopeResolution.md)

### Object Oriented Programming

Object-oriented programming – As the name suggests uses objects in programming. Object-oriented programming aims to implement real-world entities like inheritance, hiding, polymorphism, etc. in programming. The main aim of OOP is to bind together the data and the functions that operate on them so that no other part of the code can access this data except that function.

- Classes and structs 
- Class Members / Definition of Memeber Functions / Classes defined with struct and union
- Constructors & Member initialization in constructors
- Pointers to classes
- OOP Concepts (Encapsulation, Inheritance, Polymorphism, Abstraction etc.)

  Code: [oop.cpp](Essential-Concepts/OOP/oop.cpp)
  </br>
  Readme: [Oop.md](Essential-Concepts/OOP/Oop.md)

### Generics

**Generics** is the idea to allow type (Integer, String, … etc and user-defined types) to be a **parameter to methods, classes and interfaces.** For example, classes like an array, map, etc, which can be used using generics very efficiently.

Before diving into **Templates** would be better to understand concept of Generics.

- Generic Functions using Template / Generic Class using Template
- Working with multi-type Generics

  Code: [generics.cpp](Essential-Concepts/Generics/generics.cpp)

### Templates

A **template** is a simple yet very powerful tool in C++. The simple idea is to pass the data type as a parameter so that we don’t need to write the same code for different data types.

- Function Templates & Class Templates

  Code: [templates.cpp](Essential-Concepts/Templates/templates.cpp)
  </br>
  Readme: [Templates.md](Essential-Concepts/Templates/Templates.md)

## Data Structures

![3](https://github.com/user-attachments/assets/a85a5b26-7660-4ec1-8281-1bd4b14f2029)

**Data structures** in programming are ways to _organize_, _store_, and _manage_ data efficiently for operations like searching, sorting, and modification. Examples include **arrays, strings, linked lists, stacks, queues, trees, graphs etc.** Each is designed for specific tasks to optimize performance.

### Array Representations

- Declaring & Initializing arrays on Stack and Heap
- Dimensional Arrays (2D & 3D)
- Row-Column Major formulas, Address Formulas for 1D, 2D, 3D and nD Arrays

  Folder: [Arrays-Representations](Data-Structures/Arrays-Representations)
  Address Formulas: [Address-Formulas](Data-Structures/Arrays-Representations/Address-Formulas.md)

### Array ADT

The array is a basic **abstract data type** that holds an ordered collection of items accessible by an integer index. These items can be anything from _primitive types_ such as integers to more complex types like instances of classes.

- Console program that create and manipulate with Array from scratch
- Functions like **Display, Append, Insert, Search, Get & Set, Max/Min, Reverse, Shift/Rotate**

  Array ADT: [Array-ADT](Data-Structures/Array-ADT/Array.c)

## Algorithms

![4](https://github.com/user-attachments/assets/1daa6d18-c241-44b5-831a-c6e38bf89f84)

The **algorithms** are used to **solve problems or provide functionality**. Algorithms work exclusively on values; they don't affect the size or storage of a container. Simple algorithms can be implemented within a function. Complex algorithms might require several functions or even a class to implement them.

### Recursion

**Generalising Recursion**

- Behaviour of Recursion
- Ascending & Descending Phases
- CALLING time & RETURNING time
- Local and Static variables in Recursion

  Code: [recursion.cpp](Algorithms/Recursion/recursion.cpp)

**Types Of Recursion**

- _Tail Recursion_ - _Head Recursion_ - _Tree Recursion_ - _Indirect Recursion_ - _Nested Recursion_

  Folder: [Types-of-Recursion](Algorithms/Recursion/Types-of-Recursion)

**Algorithms & Problems**

Common algorithm problems using **recursion** vs **iterative approach**.

- _nCr Combination_ - _Tower of Hanoi Problem_ - _Factorial_ - _Fibonacci_ - _Power_ - _Sum Of Natural Nums_ - _Taylor Series_

  Algorithms: [Recursion-Algorithms](Algorithms/Recursion/algorithms)

### Sorting Algorithms

A **Sorting Algorithm** is used to rearrange a given array or list of elements in an order. Selecting best sorting algoritms in a certain cases is crutial for system performans and stability.

- _Bubble Sort_ - _Selection Sort_ - _Insertion Sort_ - _Merge Sort_ - _Quick Sort_ - _Bin / Bucket Sort_ - _Radix Sort_ - _Shell Sort_

  Folder: [Sorting-Techniques](Algorithms/Sorting-Techniques)

Author: [Mert Eldemir](https://github.com/merteldem1r)</br>
Search Resourses:
[Abdul Bari](https://www.udemy.com/course/datastructurescncpp/),
[cplusplus](https://cplusplus.com/doc/tutorial/),
[geeksforgeeks](https://www.geeksforgeeks.org/)
