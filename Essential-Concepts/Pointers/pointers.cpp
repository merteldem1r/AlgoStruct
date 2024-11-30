#include <iostream>

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    int a = 10;

    int *p = &a; // pointer occupies memory on the Stack

    std::cout << p << std::endl;  // e.g: 0x43ca9ff....
    std::cout << *p << std::endl; // 10

    // pointer to an array
    int A[5] = {1, 2, 3, 4, 5};

    int *aPtr = A; // without ampersand(&) because the A is already a pointer to the first element of the array same with => int *aPtr = &A[0];

    // Traverse an array using pointer

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "aPtr[i]: " << aPtr[i] << std::endl;
    }

    int *aEnd = A + 5;
    while (aPtr < aEnd)
    {
        std::cout << "*aPtr: " << *aPtr << std::endl;
        ++aPtr;
    }

    // sizeof pointers
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    Rectangle *p5;

    // whatever the type of the pointer the size same which is 8 bytes (64-bit machines)
    std::cout << "sizof int pointer: " << sizeof(p1) << std::endl;       // 8
    std::cout << "sizof char pointer: " << sizeof(p2) << std::endl;      // 8
    std::cout << "sizof float pointer: " << sizeof(p3) << std::endl;     // 8
    std::cout << "sizof double pointer: " << sizeof(p4) << std::endl;    // 8
    std::cout << "sizof Rectangle pointer: " << sizeof(p5) << std::endl; // 8

    // ******************

    // Allocate memory on Heap (malloc or new keyword)

    /*
    When you call malloc, the system's memory manager reserves a block of memory of the specified size from the heap and returns a pointer to the start of this block. This memory remains allocated until you explicitly free it with the free function.
    */

    int *ptr = (int *)malloc(5 * sizeof(int)); // C style

    if (ptr == nullptr)
    {
        std::cout << "Null pointer has been returned" << std::endl;
    }
    else
    {
        std::cout << "Memory has been allocated at address: " << ptr << std::endl;
    }

    free(ptr);

    int *ptr2 = new int[10]; // C++ style

    ptr2[0] = 1;
    ptr2[1] = 2;
    ptr2[2] = 3;
    ptr2[3] = 4;
    ptr2[4] = 5;

    std::cout << "ptr2[3] array inside Heap: " << ptr2[3] << std::endl; // 4

    if (ptr == nullptr)
    {
        std::cout << "ptr2 allocation failure" << std::endl;
    }
    else
    {
        std::cout << "ptr2 address: " << ptr2 << std::endl;
    }

    delete[] ptr2;

    // Pointer to Structure
    Rectangle r = {10, 5};
    Rectangle *rPtr = &r;

    // using -> or . to access r with pointer
    (*rPtr).breadth = 4; // C style
    rPtr->length = 2;    // C++ style

    std::cout << "r.length: " << r.length << std::endl;   // 2
    std::cout << "r.breadth: " << r.breadth << std::endl; // 4

    // Creating Rectangle dinamically in Heap
    Rectangle *dRec = new Rectangle; // allocacating memory in Heap
    dRec->length = 6;
    dRec->breadth = 3;

    std::cout << "dRec length: " << dRec->length << std::endl;   // 6
    std::cout << "dRec breadth: " << dRec->breadth << std::endl; // 3

    delete dRec;

    return 0;
}