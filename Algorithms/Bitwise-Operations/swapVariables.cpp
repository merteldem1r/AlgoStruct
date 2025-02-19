#include <iostream>

// SWAP variables using XOR

/*
    A = 5
    B = 3

    step 1:
        A = 0101
        B = 0011
        ------------
        A = 0110   (A = 6)

    step 2:
        A = 0110
        B = 0011
        ------------
        B = 0101   (B = 5)

    step 3:
        A = 0110
        B = 0101
        ------------
        A = 0011   (A = 3)
*/

// Associative PROPERTY
// (A XOR B) XOR B = (B XOR B) XOR A -> now B = A 
// (A XOR B) XOR A = (A XOR A) XOR B -> now A = B


void swap(int *a, int *b) // Time: O(1) Space: O(1)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main()
{
    int a = 5;
    int b = 3;

    std::cout << "Before swap A: " << a << " B: " << b << std::endl; // A: 5 B: 7
    swap(&a, &b);
    std::cout << "After swap A: " << a << " B: " << b << std::endl; //  A: 7 B: 5

    return 0;
}