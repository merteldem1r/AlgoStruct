#include <iostream>
#include <string>

// Reverse String

// In-Place Reverse
void reverseInPlace(std::string &str) // Time: O(n) Space: O(1)
{
    int l = 0, r = str.length() - 1;

    while (l < r)
        std::swap(str[l++], str[r--]);
}

int main()
{
    std::string str1 = "Mert Eldemir";
    std::string str2 = "Hello World";

    reverseInPlace(str1);
    reverseInPlace(str2);

    std::cout << str1 << std::endl; // rimedlE treM
    std::cout << str2 << std::endl; // dlroW olleH

    return 0;
}