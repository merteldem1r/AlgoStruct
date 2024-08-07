#include <iostream>

using namespace std;

// Heaps are memory areas allocated to each program. Memory allocated to heaps can be dynamically allocated, unlike memory allocated to stacks.

// Program should have a pointer on the Stack to access anything in the Heap

/*
Advantages of heap memory:

* Heap doesn’t have any limit on memory size.
* It allows you to access variables globally.
* Garbage collection runs on the heap memory to free the memory used by the object.
* The heap method is also used in the Priority Queue.

Disadvantages of heap memory:

* It takes too much time to execute compared to the stack.
* It takes more time to compute.
* It can provide the maximum memory an OS can provide
* Memory management is more complicated in heap memory as it is used globally.
*/

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    int a = 10;

    int *p = &a; // pointer occupies memory on the Stack

    cout << p << endl;  // e.g: 0x43ca9ff....
    cout << *p << endl; // 10

    // pointer to an array
    int A[5] = {1, 2, 3, 4, 5};

    int *aPtr = A; // without ampersand(&) because the A is already a pointer to the first element of the array same with => int *aPtr = &A[0];

    // Traverse an array using pointer

    for (int i = 0; i < 5; ++i)
    {
        cout << "aPtr[i]: " << aPtr[i] << endl;
    }

    int *aEnd = A + 5;
    while (aPtr < aEnd)
    {
        cout << "*aPtr: " << *aPtr << endl;
        ++aPtr;
    }

    // sizeof pointers
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    Rectangle *p5;

    cout << "sizof int pointer: " << sizeof(p1) << endl;       // 8
    cout << "sizof char pointer: " << sizeof(p2) << endl;      // 8
    cout << "sizof float pointer: " << sizeof(p3) << endl;     // 8
    cout << "sizof double pointer: " << sizeof(p4) << endl;    // 8
    cout << "sizof Rectangle pointer: " << sizeof(p5) << endl; // 8

    // whenever the type of the pointer the size same which is 8 bytes (64-bit machines)

    // ******************

    // Allocate memory on Heap (malloc or new keyword)

    /*
    When you call malloc, the system's memory manager reserves a block of memory of the specified size from the heap and returns a pointer to the start of this block. This memory remains allocated until you explicitly free it with the free function.
    */

    int *ptr = (int *)malloc(5 * sizeof(int)); // C style

    if (ptr == nullptr)
    {
        cout << "Null pointer has been returned" << endl;
    }
    else
    {
        cout << "Memory has been allocated at address: " << ptr << endl;
    }

    free(ptr);

    int *ptr2 = new int[10]; // C++ style

    ptr2[0] = 1;
    ptr2[1] = 2;
    ptr2[2] = 3;
    ptr2[3] = 4;
    ptr2[4] = 5;

    cout << "ptr2[3] array inside Heap: " << ptr2[3] << endl; // 4

    if (ptr == nullptr)
    {
        cout << "ptr2 allocation failure" << endl;
    }
    else
    {
        cout << "ptr2 address: " << ptr2 << endl;
    }

    delete[] ptr2;

    return 0;
}