#include <iostream>
#include <stack>
#include <string>

// LeetCode: 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.


Example 1:

    Input: tokens = ["2","1","+","3","*"]
    Output: 9
    Explanation: ((2 + 1) * 3) = 9
    Example 2:

    Input: tokens = ["4","13","5","/","+"]
    Output: 6
    Explanation: (4 + (13 / 5)) = 6

Example 3:

    Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    Output: 22
    Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
    = ((10 * (6 / (12 * -11))) + 17) + 5
    = ((10 * (6 / -132)) + 17) + 5
    = ((10 * 0) + 17) + 5
    = (0 + 17) + 5
    = 17 + 5
    = 22

*/

class Solution
{
private:
    std::stack<int> s;

public:
    bool isOperation(const char op)
    {
        return op == '+' || op == '-' || op == '*' || op == '/';
    }

    int operation(int a, int b, char op)
    {
        switch (op)
        {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        case '/':
            return b != 0 ? a / b : 0;
            break;
        }

        return 0;
    }

    int evalRPN(std::vector<std::string> &tokens) // Time: O(n) Space: O(n)
    {
        for (int i = 0; i < tokens.size(); ++i)
        {
            const std::string tokenStr = tokens[i];

            if (tokenStr.length() == 1 && isOperation(tokenStr[0]))
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();

                int opRes = operation(a, b, tokenStr[0]);
                s.push(opRes);
            }
            else
            {
                int num = std::stoi(tokenStr);
                s.push(num);
            }
        }

        return s.top();
    }
};