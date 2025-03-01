#include <iostream>
#include <unordered_map>

// Valid Parentheses

/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

*/

bool isValidParentheses(std::string s) // Time: O(n) Space: O(1)
{
    std::unordered_map<char, char> closeBrack = {
        {')', '('},
        {'}', '{'},
        {']', '['},
    };

    std::stack<char> bStack;

    for (auto chr : s)
    {
        if (closeBrack.count(chr) > 0)
        {
            if (!bStack.empty() && bStack.top() == closeBrack[chr])
                bStack.pop();
            else
                return false;
        }
        else
        {
            bStack.push(chr);
        }
    }

    return bStack.empty();
}
int main()
{
    std::string example1 = "()[]{}";
    std::string example2 = "{}(";
    std::string example3 = "([])";

    std::cout << std::boolalpha;

    std::cout << isValidParentheses(example1) << std::endl; // true
    std::cout << isValidParentheses(example2) << std::endl; // false
    std::cout << isValidParentheses(example3) << std::endl; // true

    return 0;
}
