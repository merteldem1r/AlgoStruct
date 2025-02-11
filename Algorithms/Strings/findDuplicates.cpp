#include <iostream>
#include <string>

// Find if duplicate characters contain in string

// C style solution
/*
    From ASCII Table:
        'A' = 65 ... 'Z' = 90
        'a' = 97 ... 'z' = 122
*/

bool isDuplicateCharacters(const char str[])
{
    int charTable[256] = {}; // support all ASCII characters

    for (int i = 0; str[i] != '\0'; ++i)
    {
        unsigned char ch = str[i];

        ++charTable[ch];
        if (charTable[ch] > 1)
            return true;
    }

    return false;
}

int main()
{
    const char str[] = "Hello";
    const char str2[] = "String";

    std::cout << std::boolalpha;
    std::cout << str << " isDuplicateCharacters(): " << isDuplicateCharacters(str) << std::endl;   // true
    std::cout << str2 << " isDuplicateCharacters(): " << isDuplicateCharacters(str2) << std::endl; // false

    return 0;
}