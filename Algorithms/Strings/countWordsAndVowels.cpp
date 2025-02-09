#include <iostream>
#include <string>
#include <unordered_set>

// Count words in the sentences
// Count vowels in the sentences

int countWords(const std::string &str) // Time: O(n) Space: O(1)
{
    int words = 0;
    bool isWord = false;

    for (const char &c : str)
    {
        if (c != ' ' && !isWord)
        {
            ++words;
            isWord = true;
        }
        else if (c == ' ')
        {
            isWord = false;
        }
    }

    return words;
}

int countVowels(const std::string &str) // Time: O(n) Space: O(1)
{
    int vowelCount = 0;

    std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    for (const auto &c : str)
    {
        if (vowels.count(c) > 0)
            ++vowelCount;
    }

    return vowelCount;
}

int main()
{
    std::string str = "   This is an example   sentence";
    std::cout << countWords(str) << std::endl;  // 5
    std::cout << countVowels(str) << std::endl; // 9

    return 0;
}