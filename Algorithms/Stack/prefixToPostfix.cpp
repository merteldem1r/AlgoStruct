#include <iostream>
#include <stack>

// Convert Infix expression to Postfix expression

/*

Infix expression: The expression of the form “a operator b” (a + b) i.e., when an operator is in-between every pair of operands.

Postfix expression: The expression of the form “a b operator” (ab+) i.e., When every pair of operands is followed by an operator.

    Symbol      Precedence
    +, -            1
    *, /            2
    ( )             3

    - Compiler needs paratheses for all expressions, no expression should be outside of parantheses, if they are not compiler will logically paranthesyze it by using "precedence".

    Example (infix form): a + b * c

        To brackets:
            1. step: a + (b * c)
            2. step: (a + (b * c))
        To prefix (not much used):
            1. step: (a + [*bc])
            2. step: +a*bc
        To Postfix (which actually used):
            1. step: (abc*+)

    Example (infix form): a + b + c * d

        To prefix:
            1. step: a + b + [*cd]
            2. step: [+ab] + [*cd]
            3. step: ++ab*cd
        To postfix:
            1. step: a + b + [cd*]
            2. step: [ab+] + [cd*]
            3. step: ab+cd*+


    Associativity and Unary Operators

    Associativity:

    Symbol      Precedence      Associativity
    +, -            1               L - R
    *, /            2               L - R
    ^               3               R - L
    -               4               R - L
    ( )             5               L - R


    Unary Operators (most higher precedence):
        -a
        pre: -a     post: a-

        *p (pointer)
        pre: *p     post: p*

        n!
        pre: !n     post: n!

        logx
        pre: logx   post: xlog

    Example: -a + b * logn!

        To postfix:
            1. step: -a + b * log [n!]
            2. step: -a + b * [n!log]
            3. step: [a-] + b * [n!log]
            4. step: [a-] + [bn!log]
            5. step: a-bn!log+
*/

/*
    How to convert an Infix expression to a Postfix expression

    To convert infix expression to postfix expression, use the stack data structure. Scan the infix expression from left to right. Whenever we get an operand, add it to the postfix expression and if we get an operator or parenthesis add it to the stack by maintaining their precedence.

    Below are the steps to implement the above idea:

    1. Scan the infix expression from left to right.
    2. If the scanned character is an operand, put it in the postfix expression.
    3. Otherwise, do the following
        If the precedence of the current scanned operator is higher than the precedence of the operator on top of the stack, or if the stack is empty, or if the stack contains a ‘(‘, then push the current operator onto the stack.
        Else, pop all operators from the stack that have precedence higher than or equal to that of the current operator. After that push the current operator onto the stack.
    4. If the scanned character is a ‘(‘, push it to the stack.
    5. If the scanned character is a ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis.
    6. Repeat steps 2-5 until the infix expression is scanned.
    7. Once the scanning is over, Pop the stack and add the operators in the postfix expression until it is not empty.
    8. Finally, print the postfix expression.
*/

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

std::string infixToPostfix(const std::string &infix)
{
    std::string postfix;
    std::stack<char> operatorSt;

    for (char c : infix)
    {
        if (std::isalnum(c))
        {
            postfix.push_back(c);
        }
        else if (c == '(')
        {
            operatorSt.push(c);
        }
        else if (c == ')')
        {
            while (!operatorSt.empty() && operatorSt.top() != '(')
            {
                postfix.push_back(operatorSt.top());
                operatorSt.pop();
            }
            operatorSt.pop();
        }
        else
        {
            while (!operatorSt.empty() && precedence(c) <= precedence(operatorSt.top()))
            {
                postfix.push_back(operatorSt.top());
                operatorSt.pop();
            }

            operatorSt.push(c);
        }
    }

    while (!operatorSt.empty())
    {
        postfix.push_back(operatorSt.top());
        operatorSt.pop();
    }

    return postfix;
}

int performOperation(const char c, const int a, const int b)
{
    switch (c)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return b != 0 ? a / b : 0;
    default:
        std::cout << "Invalid Operation" << std::endl;
        return -1;
    }
}

// Findindg the actual result of the expression
int evaluatePostfix(const std::string &postfix)
{
    std::stack<int> resStack;

    for (char c : postfix)
    {
        if (std::isdigit(c))
        {
            short digit = c - '0';
            resStack.push(digit);
        }
        else if (!resStack.empty())
        {
            const int a = resStack.top();
            resStack.pop();

            const int b = resStack.top();
            resStack.pop();

            const int operationRes = performOperation(c, b, a); // first value poped out comes to the right hand side
            resStack.push(operationRes);
        }
    }

    return resStack.top();
}

int main()
{
    std::string example = "a+b*c-d/e";
    std::string example2 = "a+b*(c^d-e)^(f+g*h)-i";

    std::cout << "Postfix form of: " << example << " is: " << infixToPostfix(example) << std::endl;  // abc*+de/-
    std::cout << "Postfix form of: " << example << " is: " << infixToPostfix(example) << std::endl;  // abc*+de/-
    std::cout << "Postfix form of: " << example << " is: " << infixToPostfix(example2) << std::endl; // abcd^e-fgh*+^*+i-

    std::string example3 = "3*5+6/2-4";

    std::string example3PostFix = infixToPostfix(example3);
    const int result = evaluatePostfix(example3PostFix);

    std::cout << "Postfix form of: " << example3 << " is: " << example3PostFix << std::endl; // 35*62/+4-
    std::cout << "Result of: " << example3PostFix << " is: " << result << std::endl;         // 14

    return 0;
}