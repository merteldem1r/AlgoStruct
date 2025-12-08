# AlgoStruct - Mastering DSA with C & C++

![Data Structures Algorithms](https://github.com/user-attachments/assets/9d7eda38-a40f-4673-bef2-960c03522266)

Mastering DSA in C & C++ • A complete guide up to 300+ algorithms (Recursion, Sorting, Hashing etc.) with common and advanced data structures (Array, Linked List, Stack, Queue, Trees, AVL, Heap, Graph etc.) implemented completely from scratch. Covers core programming concepts like Pointers, OOP, Structures, Memory Management etc. Besides that solving algorithm problems from LeetCode platform, with different space and time complexity solutions using DSA knowledge.

**AUTHOR**: [Mert Eldemir](https://github.com/merteldem1r)</br>
**SEARCH RESOURSES**:
[Abdul Bari](https://www.udemy.com/course/datastructurescncpp/) |
[CPlusPlus](https://cplusplus.com/doc/tutorial/) |
[GeeksforGeeks](https://www.geeksforgeeks.org/) |
[NeetCode](https://neetcode.io/roadmap) |
[NeetCode YouTube](https://www.youtube.com/@NeetCodeIO) |
[LeetCode](https://leetcode.com/) |
[Wikipedia](https://en.wikipedia.org/)

Project divided into **3 topics**. Here the table of **headings** and **subheadings**.
Each topic contain **code examples** with explained **comment lines** and **Readme files**.

## Table of Contents

### Essential Concepts

- [Array Basics](#array-basics) • [Structures](#structures) • [Pointers](#pointers) • [Reference](#reference)
- [Functions](#functions) • [Converting C to C++](#converting-c-code-to-c)
- [Scope Resolution](#scope-resolution) • [OOP](#object-oriented-programming)
- [Generics](#generics) • [Templates](#templates) • [Operator Overloading](#operator-overloading)

---

### Data Structures

- [Array Representations](#array-representations) • [Array ADT](#array-adt) • [Strings](#strings)
- [Linked Lists](#linked-list) • [Stack](#stack) • [Queue](#queue)
- [Trees](#trees) • [Binary Search Tree](#binary-search-tree) • [AVL Tree](#avl-tree) • [2-3 Tree](#2-3-tree) • [Red Black Tree](#red-black-tree) • [Heap](#heap)

---

### Algorithms

- [Recursion](#recursion) • [Sorting](#sorting-algorithms) • [Hashing](#hashing-algorithms) • [Array & Hashing](#array--hash-map-algorithms)
- [Bitwise](#bitwise-operations) • [Strings](#string-algorithms)
- [Linked List](#linked-list-algorithms) • [Stack](#stack-algorithms) • [Queue](#queue-algorithms)
- [Binary Search](#binary-search-algorithms) • [Binary Tree](#binary-tree-algorithms) • [Binary Search Tree](#binary-search-tree-algorithms) • [Heap](#heap-algorithms)
- [Backtracking](#backtracking) • [Math & Geometry](#math--geometry-algorihms) • [Intervals](#intervals)

Each section of this repository was created with **genuine passion**, **thorough research**, and **dedicated implementation**. I hope it proves helpful to others.

**NOTE:** **Time** and **space complexity** values are usually provided as **comments near the algorithms**. Unless otherwise specified (e.g., best, average, or worst case), you should assume that **the given complexities refer to the worst-case scenario**. Some of explanations in **.md** files are made by using AI for better understanding the topic.

**Let's get started! 🚀**

## Essential Concepts of C & C++

![2](https://github.com/user-attachments/assets/bbf5630d-c834-4b5a-8e1b-900b20252e96)

Essential concepts of C & C++ **before diving into DSA**. Arrays, Structures, OOP, Pointer and a lot more with explanation and example code.

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

  C Code: [c-code.c](Essential-Concepts/Converting-C-to-CPP/c-code.c)
  </br>
  C++ Code: [cpp-code.cpp](Essential-Concepts/Converting-C-to-CPP/cpp-code.cpp)

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
- **Runtime** vs **Compile Time** Polymorphism

  Code: [oop.cpp](Essential-Concepts/OOP/oop.cpp), [polymorphism.cpp](Essential-Concepts/OOP/polymorphism.cpp)
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

### Operator Overloading

**Operator Overloading** is a fundamental **feature of C++** that allows developers to redefine the behavior of operators for user-defined types (classes and structs). This powerful mechanism enhances the expressiveness and readability of code, making user-defined types behave more like built-in types.

- Operator overloading, use cases, examples

  Code: [OperatorOverloading.cpp](Essential-Concepts/Operator-Overloading/OperatorOverloading.cpp)
  <br/>
  Readme: [OperatorOverloading.md](Essential-Concepts/Operator-Overloading//OperatorOverloading.md)

## DATA STRUCTURES

![3](https://github.com/user-attachments/assets/a85a5b26-7660-4ec1-8281-1bd4b14f2029)

**Data structures** in programming are ways to _organize_, _store_, and _manage_ data efficiently for operations like searching, sorting, and modification. Examples include **arrays, strings, linked lists, stacks, queues, trees, graphs etc.** Each is designed for specific tasks to optimize performance.

### Array Representations

- Declaring & Initializing arrays on Stack and Heap
- Dimensional Arrays (2D & 3D)
- Row-Column Major formulas, Address Formulas for 1D, 2D, 3D and nD Arrays

  Folder: [Arrays-Representations](Data-Structures/Arrays-Representations)
  </br>
  Address Formulas: [Address-Formulas](Data-Structures/Arrays-Representations/Address-Formulas.md)

### ARRAY ADT

The array is a basic **abstract data type** that holds an ordered collection of items accessible by an integer index. These items can be anything from _primitive types_ such as integers to more complex types like instances of classes.

- Console program that create and manipulate with Array from scratch
- Functions like **Display, Append, Insert, Search, Get & Set, Max/Min, Reverse, Shift/Rotate**

  Code: [Array.c](Data-Structures/Array-ADT/Array.c)

### STRINGS

In computer programming, a string is traditionally a sequence of characters, either as a literal constant or as some kind of variable.

- Characters & Character Arrays
- Null-Termination & Mutability & Efficient Copying & Concatenation
- std::string

  Code: [Strings.cpp](Data-Structures/Strings/Strings.cpp)
  </br>
  Readme: [Strings.md](Data-Structures/Strings/Strings.md)
  </br>
  ASCII TABLE: [ASCII-Table.png](Data-Structures/Strings/ASCII-Table.png)

### LINKED LIST

**Linked list** is a **linear data structure** that allows the users to store data in **non-contiguous memory locations**. A linked list is defined as a **collection of nodes** where each node consists of two members which represents its value and a next pointer which stores the address for the next node.

- Linked List, Nodes
- Single & Double & Circular Linked Lists

  Folder: [Linked-Lists](Data-Structures/Linked-Lists)
  </br>
  Readme: [LinkedLists.md](Data-Structures/Linked-Lists/LinkedLists.md)

### STACK

A **Stack** is a linear data structure that follows the **Last In, First Out (LIFO)** principle. This means that the last element added to the stack will be the first one to be removed.

- Stack implementation using std::vector<>
- Stack implementation from scratch with manual memory management (on Heap)

  Folder: [Stack](Data-Structures/Stack/)
  </br>
  Readme: [Stack.md](Data-Structures/Stack/Stack.md)

### QUEUE

A **Queue** Data Structure is a fundamental concept in computer science used for storing and managing data in a specific order. It follows the principle of **"First in, First out" (FIFO)**, where the first element added to the queue is the first one to be removed.

- Queue implementation using array with circular two pointer approach
- Queue implementation using Linked List
- Deque (double-ended queue) implementation using Linked List

  Folder: [Queue](Data-Structures/Queue/)
  </br>
  Readme: [Queue.md](Data-Structures/Queue/Queue.md)

### TREES

**Tree data structure** is a hierarchical structure that is used to represent and organize data in the form of **parent-child** relationship. The following are some real world situations which are naturally a tree.

The topmost node of the tree is called the root, and the nodes below it are called the child nodes. Each node can have multiple child nodes, and these child nodes can also have their own child nodes, forming a recursive structure.

- General idea about trees; terminology, use cases, types etc.
- Binary Tree implementation (number of trees using n-nodes).
- N-ary Trees

  Folder: [Trees](Data-Structures/Trees/)
  </br>
  Readme: [Trees.md](Data-Structures/Trees/Trees.md)

### BINARY SEARCH TREE

A **Binary Search Tree (or BST)** is a data structure used in computer science for **organizing** and **storing** data in a **sorted manner**. Each node in a Binary Search Tree **has at most two children**, a left child and a right child, with the **left child containing values less than the parent node and the right child containing values greater than the parent node**. This hierarchical structure allows for efficient searching, insertion, and deletion operations on the data stored in the tree.

- Create Binary Search Tree class from scratch
- Undertand the main concepts and properties of BST (Catalan Number Formula, traversals, etc.)
- Implement common methods such as **search**, **insert**, **delete**, **successor** etc.

  Code: [BST.cpp](Data-Structures/Binary-Search-Tree/BST.cpp)
  </br>
  Readme: [BST.md](Data-Structures/Binary-Search-Tree/BST.md)

### AVL TREE

An **AVL tree** defined as a **self-balancing Binary Search Tree (BST)** where the **difference between heights of left and right subtrees for any node cannot be more than one**.

The absolute difference between the heights of the left subtree and the right subtree for any node is known as the balance factor of the node. The **balance factor** for all nodes **must be less than or equal to 1**.

**Every AVL tree is also a Binary Search Tree** (Left subtree values Smaller and Right subtree values greater for every node), but every BST is not AVL Tree. The main advantage of an AVL Tree is, the **time complexities of all operations (search, insert and delete, max, min, floor and ceiling) become O(Log n)**. **This happens because height of an AVL tree is bounded by O(Log n)**. In case of a normal BST, the height can go up to O(n).

An AVL tree **maintains its height by doing some extra work during insert and delete operations**. It mainly uses rotations to maintain both BST properties and height balance.

- **Inserting** & **Removing** nodes from AVL tree while taking care of **balance factor** and **heights** of each node
- **LL**, **LR**, **RR**, **RL** rotations explained and implemented for unbalanced cases of the nodes
- **Visualizations** for each functions with comment lines

  File: [AVL.cpp](Data-Structures/AVL-Tree/AVL.cpp)
  </br>
  Readme: [AVL.md](Data-Structures/AVL-Tree/AVL.md)

### 2-3 TREE

In binary search trees we have seen the average-case time for operations like search/insert/delete is O(log N) and the worst-case time is O(N) where N is the number of nodes in the tree.

Like other Trees include AVL trees, Red Black Tree, B tree, 2-3 Tree is also a height balanced tree.

The time complexity of search/insert/delete is O(log N) .

A 2-3 tree is a [B-tree](https://www.geeksforgeeks.org/introduction-of-b-tree-2/) of order 3.

- implementation coming soon...

  File: [2-3-Tree.cpp](Data-Structures/2-3-Tree/2-3-Tree.cpp)
  </br>
  Readme: [2-3-Tree.md](Data-Structures/2-3-Tree/2-3-Tree.md)

### RED BLACK TREE

**Red Black Trees** are a type of balanced binary search tree that use a set of rules to maintain balance, ensuring logarithmic time complexity for operations like **insertion**, **deletion**, and **searching**, regardless of the initial shape of the tree. Red Black Trees are self-balancing, using a simple **color-coding scheme** to adjust the tree after each modification.

The **Red-Black Trees** is less balanced compared to **AVL** trees, because **AVL** trees may cause more **rotations** during **insertion** and **deletion**. So if your application involves frequent insertions and deletions, then Red-Black trees should be preferred. And if the insertions and deletions are less frequent and **search** is a more frequent operation, then AVL tree should be preferred over the Red-Black Tree.

- 2 case of balancing: **Recoloring** & **Rotation**
- **Red** and **Black** Node properties
- **Insert** & **Delete** & **Search** methods with all case implementations

  File: [RedBlackTree.cpp](Data-Structures/Red-Black-Tree/RedBlackTree.cpp)
  </br>
  Readme: [RedBlackTree.md](Data-Structures/Red-Black-Tree/RedBlackTree.md)

### HEAP

A **Heap** is a [complete binary](https://www.geeksforgeeks.org/complete-binary-tree/) tree data structure that satisfies the heap property:

**Max Heap:** Every node should have the element greater or equal to it's all descendants.
**Min Heap:** Every node should have the element less or equal to it's all descendants.

Heaps are usually used to implement **priority queues**, where the smallest (or largest) element is always at the root of the tree.

- Max-Heap & Min-Heap Data Structure
- Heap functions such as: MaxHeapify, extractMax, Parent, Left, Right, insert
- Building and Sorting array using Heapify method

  Code: [Heap.cpp](Data-Structures/Heap/Heap.cpp)
  </br>
  Readme: [Heap.md](Data-Structures/Heap/Heap.md)
  </br>
  [Priority Queue using Binary Heap](https://www.geeksforgeeks.org/priority-queue-using-binary-heap/)

## ALGORITHMS

![4](https://github.com/user-attachments/assets/1daa6d18-c241-44b5-831a-c6e38bf89f84)

**Algorithm** is a step-by-step procedure for **solving a problem** or accomplishing a task. In the context of **data structures** and **algorithms**, it is a set of well-defined instructions for performing a specific computational task. **Algorithms** are fundamental to **Computer Science** and play a very important role in designing **efficient solutions** for various problems.

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

- [_Bubble Sort_](Algorithms/Sorting-Techniques/BubbleSort.cpp) - [_Selection Sort_](Algorithms/Sorting-Techniques/SelectionSort.cpp) - [_Insertion Sort_](Algorithms/Sorting-Techniques/InsertionSort.cpp)
- [_Merge Sort_](Algorithms/Sorting-Techniques/MergeSort.cpp) - [_Quick Sort_](Algorithms/Sorting-Techniques/QuickSort.cpp)
- [_Counting Sort_](Algorithms/Sorting-Techniques/CountingSort.cpp)
- [_Bin / Bucket Sort_](Algorithms/Sorting-Techniques/BucketSort.cpp)
- _Radix Sort_
- _Shell Sort_
- [_Heap Sort_](Algorithms/Sorting-Techniques/HeapSort.cpp)

  Folder: [Sorting-Techniques](Algorithms/Sorting-Techniques)

### Hashing Algorithms

Hashing refers to the process of **generating a small sized output** (that can be used as index in a table) from an input of typically large and variable size. Hashing uses **mathematical formulas** known as **hash functions** to do the transformation. This technique determines an **index** or **location** for the storage of an item in a data structure called Hash Table.

- Hashing functions
- Mapping types **one-one**, **one-many** etc.
- How to solve Hash Collision - **Open Hashing** & **Closed Hashing**

  Folder: [Hashing](Algorithms/Hashing)

### Array & Hash Map Algorithms

- _findDuplicates_ - _findMaxMinSingleScan_ - _findMultipleMissingElements_ - _findSingleMissingElement_ - _mergeSortedArrays_ - _rotateArray_ - _pairSum_ - _removeDuplicatesFromSortedArray_ - _topKFrequentElements_ - _validSudoku_ - _groupAnagrams_

  Folder: [Array-Algorithms](Algorithms/Arrays)

### Bitwise Operations

In C+, Bitwise Operators are the operators that are used to perform bit-level operations on the integers. While performing these operations, integers are considered as sequences of binary digits. These operators are useful for low-level programming, system programming, and optimizing performance.

- AND, OR, XOR, NOT, Left Shift, Right Shift
- _hammingWeight_ - _swapVariables_ - _convertBinaryInLinkedListToInt_ - _countingBits_ - _sumOfTwoIntegers_

  Folder: [Bitwise-Operations](Algorithms/Bitwise-Operations)
  </br>
  Readme: [Bitwise.md](Algorithms/Bitwise-Operations/Bitwise.md)

### String Algorithms

- _changingCase_ - _countWordsAndVowels_ - _findDuplicates_ - _findDuplicatesBitwise_ - _findStringLength_ - _isPalindrome_ - _reverseString_ - _validateString_ - _isAnagram_ - _firstUniqueCharacterInString_ - _stringToIntegerAtoi_

  Folder: [String-Algorithms](Algorithms/Strings)

### Linked List Algorithms

- _reverseLinkedList_ - _intersectionOfLinkedLists_ - _displayLinkedList_ - _countNodes_ - _findMaxMin_ - _isSorted_ - _removeDuplicates_ - _mergeLinkedLists_ - _midlleOfLinkedList_ - _convertBinaryInLinkedListToInt_ - _reorderList_ - _lruCache_

  Folder: [Linked-List-Algorithms](Algorithms/Linked-Lists/)

### Stack Algorithms

- _isValidParantheses_ - _prefixToPostfix_ - _minStack_ - _evaluateReversePolishNotation_

  Folder: [Stack-Algorithms](Algorithms/Stack/)

### Queue Algorithms

- _implementQueueUsingStack_

  Folder: [Queue-Algorithms](Algorithms/Queue/)

### Binary Search Algorithms

- _kokoEatingBananas_

  Folde: [Binary-Seach-Algorithms](Algorithms/Binary-Search/)

### Binary Tree Algorithms

- _TraversalMethods_ - _countNodesAndHeight_ - _sumOfNodes_ - _generateTreeFromTraversals_ - _createTreeFromArray_ - _catalanNumber_ - _minMaxNodesFromHeight_ - _countLeafAndNonleafNodes_ - _invertBinaryTree_ - isBalancedBinaryTree - _diameterOfBinaryTree_ - _isSameTree_ - _isSubtreeOfAnotherTree_ - _binaryTreePaths_ - _binaryTreeRightSideView_ - _countGoodNodesInBinaryTree_ - _generateBinaryTreeFromInorderPreorder_ - _sumOfLeftLeaves_

  Folder: [Binary-Tree-Algorithms](Algorithms/Binary-Tree/)

### Binary Search Tree Algorithms

- _generateBSTFromOneTraversal_ - _resursiveInsert_ - _createBSTFromArray_ - _lowestCommonAncestorBST_

  Folder: [Binary-Search-Tree-Algorithms](Algorithms/Binary-Search-Tree/)

### Heap Algorithms

Also known as **Priority Queues**

- _kthLargestElementInStream_ - _lastStoneWeight_ - _kthLargestElementInArray_ - _designTwitter_

  Folder: [Heap-Algorithms](Algorithms/Heap/)

### Backtracking

- _permutationString_

  Folder: [Backtracking](Algorithms/Backtracking/)

### Math & Geometry Algorihms

- _multiplyStrings_ - _plusOne_ - _emirpNumber_ - _rotateImage_

  Folder: [Math-Geometry](Algorithms/Math-Geometry/)

### Dynamic Programming

- _coinChange_ - _maximumSubarray_ - _longestPalindromicSubstring_

  Folder: [Dynamic-Programming](Algorithms/Dynamic-Programming/)

### Intervals

- _insertInterval_ - _mergeIntervals_

Folder: [Math-Geometry](Algorithms/Math-Geometry/)
