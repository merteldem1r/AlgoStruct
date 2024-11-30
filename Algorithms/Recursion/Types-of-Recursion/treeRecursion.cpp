#include <iostream>

// TREE RECURSION

/*

    LINEER RECURSION:
    * when the func calling itself only ONE TIME

    fun(int n) {
        if (n > 0) {
            ---
            ---
            fun(n - 1);
            ---
            ---
        }
    };

*/

/*

    TREE RECURSION:
    * when the func calling itself only MORE THAN ONE TIME

    fun(int n) {
        if (n > 0) {
            ---
            ---
            fun(n - 1);
            ---
            ---
            fun(n - 1);
            ---
            ---
        }
    };

*/

void fun(int n) // Time: O(2^n) || Space: O(n)
{
    if (n > 0)
    {
        std::cout << n << " ";
        fun(n - 1); // will be performed at CALLING time
        fun(n - 1); // will be performed at RETURNING time
    }
}

/*
fun(3)
├── fun(2)                  // First call at calling time
│   ├── fun(1)              // First call at calling time
│   │   ├── fun(0)          // Base case (returns)
│   │   └── fun(0)          // Base case (returns)
│   └── fun(1)              // Second call at returning time
│       ├── fun(0)          // Base case (returns)
│       └── fun(0)          // Base case (returns)
└── fun(2)                  // Second call at returning time
    ├── fun(1)              // First call at calling time
    │   ├── fun(0)          // Base case (returns)
    │   └── fun(0)          // Base case (returns)
    └── fun(1)              // Second call at returning time
        ├── fun(0)          // Base case (returns)
        └── fun(0)          // Base case (returns)
*/

// 0 1 1 2 3 5 8 13 ...
int fibonacci(int n) // Time: O(2^n) || Space: O(n)
{
    if (n < 2)
    {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    fun(3); // 3 2 1 1 2 1 1

    std::cout << std::endl;

    std::cout << "fibonacci: " << fibonacci(6) << std::endl; // 8

    return 0;
}