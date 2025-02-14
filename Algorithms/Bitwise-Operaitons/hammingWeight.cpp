#include <iostream>

// Hamming Weight
// Count the Number of 1's in the Binary Representation of a Number

// Time: O(k), where k is the number of 1 bits in n. In the worst case, k can be at most 32 (since n is at most 10^9, which fits in a 32-bit integer).
// Space: O(1)
int hammingWeight(int num)
{
    int bitCount = 0;

    for (; num ;)
    {
        bitCount += num & 1;
        num >>= 1;
    }

    return bitCount;
}

int main()
{
    const int num1 = 2;
    const int num2 = 28;

    std::cout << "Bit count of " << num1 << " is: " << hammingWeight(num1) << std::endl; // 1
    std::cout << "Bit count of " << num2 << " is: " << hammingWeight(num2) << std::endl; // 3

    return 0;
}