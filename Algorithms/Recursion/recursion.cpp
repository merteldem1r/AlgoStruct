#include <iostream>

// Simple difference between two Recursion functions:

// first PRINT then CALL itself || Time Complexity: O(n) Space Complexity: O(n)
void func1(int x)
{
    if (x > 0)
    {
        std::cout << x << std::endl;
        func1(x - 1);
    }
}

// first CALL itself then PRINT || Time Complexity: O(n) Space Complexity: O(n)
void func2(int x)
{
    if (x > 0)
    {
        func2(x - 1);
        std::cout << x << std::endl;
    }
}

/*
    Generalising Recursion

    * loops (for & while) has only Ascending phase rather than Recursion
    * there is two PHASES on Recursion -> Ascending and Descending

    void func(int n) {

        if (n > 0) {
            1. execute at CALLING time; (Ascending)

            2. RECURION func(n - 1);

            3. execute at RETURNING time; (Descending)
        }

    }

*/

// LOCAL STATIC VARIABLES RECURSION

// LOCAL variables of a function
int fun(int n)
{
    if (n > 0)
    {
        // n having its own value on each call
        return fun(n - 1) + n;
    }

    return 0;
}

/*

                        fun(5) = 15
                        /
                    fun(4) + 5 = 15
                    /
                fun(3) + 4 = 10
                /
            fun(2) + 3 = 6
            /
        fun(1) + 2 = 3
        /
    fun(0) + 1 = 1
        |
    fun(0) = 0
*/

// *************************************************************

// STATIC variable for X which has only one copy

int funStatic(int n)
{
    // each call will use same copy of x (it's the same as creating x in global scope)
    static int x = 0;

    if (n > 0)
    {
        x++;
        // this x will be added at RETURNING time of the function
        return funStatic(n - 1) + x;
    }

    return 0;
}

/*

                        fun(5) = 25 | x = 0
                        /
                    fun(4) + 5 = 25 | x = 1
                    /
                fun(3) + 5 = 20 | x = 2
                /
            fun(2) + 5 = 15 | x = 3
            /
        fun(1) + 5 = 10 | x = 4
        /
    fun(0) + 5 = 5 | x = 5
        |
    fun(0) = 0

*/

int main()
{
    int x = 3;

    std::cout << "func1 outputs: " << std::endl;
    func1(x); // 3 2 1

    std::cout << "func2 outputs: " << std::endl;
    func2(x); // 1 2 3

    // Local and StaticS

    int a = 5;

    std::cout << "fun: " << fun(a) << std::endl;             // 15
    std::cout << "funStatic: " << funStatic(a) << std::endl; // 25

    return 0;
}