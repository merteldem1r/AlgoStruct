#include <iostream>
#include <string>

// Array Represantations

void printArr(std::string title, int arr[], int n)
{
    std::cout << title << std::endl;
    std::cout << "\t[ ";

    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";

    std::cout << "]" << std::endl;
}

int main()
{
    // Declarations of Array
    int A[5]; // declaration with garbage values

    printArr("Garbage A:", A, 5); // [...garbage values]

    int B[5] = {2, 3};                // initialize array with values
    printArr("Initialize B: ", B, 5); // [ 2 3 0 0 0 ]

    // Static vs Dynamic Arrays

    // Static
    int C[5] = {1, 2, 3, 4, 5}; // array created on STACK

    // Dynamic
    int *p;         // pointer created on STACK
    p = new int[5]; // array created on HEAP

    p[0] = 10;
    p[2] = 20;

    printArr("Dynamic Array:", p, 5); // [ 10 garbage 20 garbage garbage ]

    delete[] p; // deallocation in C++

    // HOW TO INCREASE ARRAY SIZE
    int *k = new int[5];
    int *q = new int[10];

    // copy from k to q
    for (int i = 0; i < 5; ++i)
        q[i] = k[i];

    delete[] k; // delete unused old array

    // make k point to q
    k = q;
    q = NULL; // undo q point to allocated array

    return 0;
}