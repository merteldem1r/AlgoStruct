#include <iostream>
#include <string>

// Compare Strings & Check is Palindrome

// Compare Two String

// (C style solution)
void compareString(const char str1[], const char str2[]) // Time: O(n) Spae: O(1)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
            break;
        ++i;
    }

    if (str1[i] == str2[i])
        std::cout << "EQUAL" << std::endl;
    else if (str1[i] < str2[i])
        std::cout << str1 << " is SMALLER" << std::endl;
    else
        std::cout << str1 << " is GREATER" << std::endl;
}

/*
    Is Palindrome
        A string is called a palindrome if the reverse of the string is the same as the original one.
        Example: “madam”, “racecar”, “12321”
 */

bool isPalindrome(std::string str) // Time: O(n) Space: O(1)
{
    for (int l = 0, r = str.length() - 1; l < r; ++l, --r)
    {
        if (str[l] != str[r])
            return false;
    }
    return true;
}

int main()
{
    // Compare two Strings
    const char str1[] = "Painter";
    const char str2[] = "Aainting";

    std::cout << std::boolalpha;

    std::cout << str1 << " & " << str2 << " when compare are: ";
    compareString(str1, str2);
    std::cout << " (alphabetically)";

    // Is Palindrome
    std::string str3 = "madam";
    std::string str4 = "Madam";

    std::cout << str3 << " isPalindrome: " << isPalindrome(str3) << std::endl; // true
    std::cout << str4 << " isPalindrome: " << isPalindrome(str4) << std::endl; // false

    std::cout << std::noboolalpha;
    return 0;
}