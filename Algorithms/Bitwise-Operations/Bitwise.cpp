// BitwiseOperations.cpp
// A tutorial on common bitwise operations in C++
#include <iostream>
using namespace std;

// Brief overview of bitwise operations: 
// (This small overview about bitwise operation I have created with AI)
// All operaritns run at O(1) time complexity

// Function to demonstrate AND operation
void bitwiseAND(int a, int b)
{
    cout << "\nAND Operation:\n";
    cout << a << " & " << b << " = " << (a & b) << endl;
}

// Function to demonstrate OR operation
void bitwiseOR(int a, int b)
{
    cout << "\nOR Operation:\n";
    cout << a << " | " << b << " = " << (a | b) << endl;
}

// Function to demonstrate XOR operation
void bitwiseXOR(int a, int b)
{
    cout << "\nXOR Operation:\n";
    cout << a << " ^ " << b << " = " << (a ^ b) << endl;
}

// Function to demonstrate NOT operation
void bitwiseNOT(int a)
{
    cout << "\nNOT Operation:\n";
    cout << "~" << a << " = " << (~a) << endl;
}

// Function to demonstrate Left Shift operation
void leftShift(int a, int shift)
{
    cout << "\nLeft Shift Operation:\n";
    cout << a << " << " << shift << " = " << (a << shift) << endl;
}

// Function to demonstrate Right Shift operation
void rightShift(int a, int shift)
{
    cout << "\nRight Shift Operation:\n";
    cout << a << " >> " << shift << " = " << (a >> shift) << endl;
}

int main()
{
    int a = 5, b = 3, shift = 1;
    cout << "Initial values: a = 5, b = 3, shift = 1\n";
    bitwiseAND(a, b);     // 1
    bitwiseOR(a, b);      // 7
    bitwiseXOR(a, b);     // 6
    bitwiseNOT(a);        // -6
    leftShift(a, shift);  // 10
    rightShift(a, shift); // 2
    return 0;
}
