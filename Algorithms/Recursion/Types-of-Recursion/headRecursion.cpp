#include <iostream>

// HEAD RECURSION
// when the first statement is the recursion call

/*

    EXAMPLE 1:

    fun(int n) {
        if (n > 0) {
            fun(n - 1);
            ---
            ---    this operations will be performed at RETURNING time only
            ---
        }
    };

*/

void funRecursion(int n) // Time: O(n) || Space: O(n)
{
    if (n > 0)
    {
        funRecursion(n - 1);
        std::cout << n << " ";
    }
};

void funLoop(int n) // Time: O(n) || Space: O(1)
{
    int i = 1;

    while (i <= n)
    {
        std::cout << i << " ";
        ++i;
    }
}

// Head recursion can not be converted directly as it is into loop function
// if a recursion function has something to do at RETURNING time it can not be easily converted into loop function, but it CAN steal converted

int main()
{
    funRecursion(3); // 1 2 3
    std::cout << std::endl;
    funLoop(3); // 1 2 3

    return 0;
}