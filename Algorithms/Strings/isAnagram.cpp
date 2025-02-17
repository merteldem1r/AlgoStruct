#include <iostream>
#include <unordered_set>

// Is Anagram
// An anagram of a string is another string that contains the same characters, only the order of characters can be different.

// using unordered map
// Time: O(n) Space: O(n + m)
bool isAnagram(char str1[], char str2[])
{ 
    if (strlen(str1) != strlen(str2))
        return false;

    std::unordered_map<char, int> letterMap;

    for (int i = 0; str1[i] != '\0'; ++i)
        ++letterMap[str1[i]];

    for (int i = 0; str2[i] != '\0'; ++i)
    {
        if (letterMap.count(str2[i]) == 0)
            return false;

        --letterMap[str2[i]];
        if (letterMap[str2[i]] < 0)
            return false;
    }

    return true;
}

// c style solution using hash map as array
// Time: O(n) Space: O(1)
bool isAnagram2(char str1[], char str2[])
{ 
    if (strlen(str1) != strlen(str2))
        return false;

    int charMap[128] = {0};

    for (int i = 0; str1[i] != '\0'; ++i)
    {
        const int position = str1[i];
        ++charMap[position];
    }

    for (int i = 0; str2[i] != '\0'; ++i)
    {
        const int position = str2[i];

        if (charMap[position] == 0)
            return false;

        --charMap[position];
        if (charMap[position] < 0) return false;
    }

    return true;
}

int main()
{
    char str1[] = "aab";
    char str2[] = "bba";
    char str3[] = "abb";

    std::cout << std::boolalpha;
    std::cout << str1 << " and " << str2 << " isAnagram(): " << isAnagram2(str1, str2) << std::endl; // false
    std::cout << str2 << " and " << str3 << " isAnagram(): " << isAnagram2(str2, str3) << std::endl; // true
    std::cout << std::noboolalpha;

    return 0;
}