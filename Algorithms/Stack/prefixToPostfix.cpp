#include <iostream>

// Convert Infix expression to Postfix expression

/*

Infix expression: The expression of the form “a operator b” (a + b) i.e., when an operator is in-between every pair of operands.

Postfix expression: The expression of the form “a b operator” (ab+) i.e., When every pair of operands is followed by an operator.

    Input: A + B * C + D
    Output: ABC*+D+

    Input: ((A + B) – C * (D / E)) + F
    Output: AB+CDE/*-F+  

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

    Symbol      Precedence      Associativity
    +, -            1               L - R
    *, /            2               L - R
    ^               3               R - L
    -               4               R - L
    ( )             5               L - R
*/

void inputToPostfix() {

}

int main()
{
    return 0;
}