#include <iostream>

// TAIL RECURSION
// if the recursion call is the last statement in the function it names as Tail Recursion

/*

    EXAMPLE 1:

    fun(int n) {
        if (n > 0) {
            ---
            ---    this operations will be performed at CALLING time only
            ---
            fun(n - 1);
        }
    };

    EXAMPLE 2 (not Tail recursion):

    fun(int n) {
        if (n > 0) {
            ---
            ---    this operations will be performed at CALLING time only
            ---
            fun(n - 1) + n; // +n will be performed at RETURNING time
        }
    };

*/

void funRecursion(int n) // Time: O(n) || Space: O(n)
{
    if (n > 0)
    {
        std::cout << n << " ";
        funRecursion(n - 1);
    }
};

void funLoop(int n) // Time: O(n) || Space: O(1)
{
    while (n > 0)
    {
        std::cout << n << " ";
        --n;
    }
}

// if you have Tail Recursion it would be better to convert it into Loop because of efficiency. Also some code optimizations in compilers checks if you have Tail Recursion it converts it into Loop for better Space Complexity

int main()
{
    funRecursion(3); // 3 2 1
    std::cout << std::endl;
    funLoop(3); // 3 2 1

    return 0;
}