#include <iostream>
#include <string>

// Change string cases

// from ASCII table we see 'A': 65 'a': 97
// so -+ 32 we can get opposite case of the character

void changeToLowerCase(std::string &str) // Time: O(n) Space: O(1)
{
    for (int i = 0; i < str.length(); ++i)
    {
        str[i] += 32;
    }
}

void changeToLowerCase2(std::string &str) // Time: O(n) Space: O(1)
{
    for (auto &chr : str)
    {
        if (chr >= 'A' && chr <= 'Z')
            chr += 32;
    }
}

void changeCase(std::string &str) // Time: O(n) Space: O(1)
{
    for (auto &chr : str)
    {
        if (chr >= 'A' && chr <= 'Z')
            chr += 32;
        else if (chr >= 'a' && chr <= 'z')
            chr -= 32;
    }
}

int main()
{
    // Change to lower case
    std::string str = "HELLO"; // hello
    changeToLowerCase(str);
    std::cout << str << std::endl;

    std::string str2 = "C PLUS PLUs";
    changeToLowerCase2(str2);
    std::cout << str2 << std::endl; // c plus plus

    // Change string cases
    std::string str3 = "ThIs iS String ALGOrithms"; // tHiS Is sTRING algoRITHMS
    changeCase(str3);
    std::cout << str3 << std::endl;

    return 0;
}