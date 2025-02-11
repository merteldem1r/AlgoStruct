#include <iostream>
#include <cctype>
#include <regex>

// Validate String (valid string contain only alphabetic characters)

/*
    From ASCII Table:
        'A' = 65 ... 'Z' = 90
        'a' = 97 ... 'z' = 122
*/

bool isValidString(std::string str) // Time: O(n) Space: O(1)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!(str[i] >= 65 && str[i] <= 90) && !(str[i] >= 97 && str[i] <= 122))
            return false;
    }

    return true;
}

// Using std::isalpha
bool isValidString2(std::string str) // Time: O(n) Space: O(1)
{
    for (char c : str)
    {
        if (!std::isalpha(static_cast<unsigned char>(c)))
            return false;
    }

    return true;
}

// Using regex
bool isValidString3(std::string str) // Time: O(n) Space: O(1)
{
    std::regex pattern("^[A-Za-z]+$");
    return std::regex_match(str, pattern);
}

int main()
{
    std::string str1 = "Compiler";     // true
    std::string str2 = "Hello/ W0rld"; // false
    std::string str3 = "Hello World";  // false (because of space)

    std::cout << std::boolalpha; // enabling printing bool values

    std::cout << "Is str1 valid: " << isValidString(str1) << std::endl;  // true
    std::cout << "Is str2 valid: " << isValidString2(str2) << std::endl; // false
    std::cout << "Is str3 valid: " << isValidString3(str3) << std::endl; // false

    std::cout << std::noboolalpha; // disable printing bool values

    return 0;
}