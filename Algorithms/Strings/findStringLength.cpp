#include <iostream>

// Find string length

int findStringLen(const char str[]) // Time: O(n) Space: O(1)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        ++len;

    return len;
}

int main()
{
    const char *str = "Mert Eldemir";

    std::cout << findStringLen(str) << std::endl; // 12

    return 0;
}