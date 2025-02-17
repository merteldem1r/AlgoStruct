#include <iostream>

// Find if duplicate characters contain in string using Bitwise Operations 
// for Bitwise algorithms and explanations got to [Algorithms/Bitwise-Operaitons]

// Use bitwise operations to check for duplicate string, it only works efficiently for lowercase English letters ('a' to 'z').
// integer is 32 bits, and there are 26 letters, we can store letter positionas as bits

bool isDuplicateCharactersBitwise(char str[]) 
{
    int bitmask = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        const int position = str[i] - 'a';

        int existBit = bitmask & (1 << position);
        if (existBit) return true;
        else bitmask |= 1 << position;
    }

    return false;
}

int main()
{
    char str[] = "finding";
    char str2[] = "abcd";

    std::cout << std::boolalpha;
    std::cout << str << " isDuplicateCharactersBitwise(): " << isDuplicateCharactersBitwise(str) << std::endl;   // true
    std::cout << str2 << " isDuplicateCharactersBitwise(): " << isDuplicateCharactersBitwise(str2) << std::endl; // false

    return 0;
}