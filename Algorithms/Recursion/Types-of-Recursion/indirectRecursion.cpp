#include <iostream>

using namespace std;

// INDERECT RECURSION
// when function call themself in circular form

/*

    fun A (int n) {
        if ( --- ) {
            ---
            ---
            fun B(n - 1);
        }
    };

    fun B (int n) {
        if ( --- ) {
            ---
            ---
            fun A(n - 3)
        }
    };

*/

void funB(int n); // prototy of function B before initialization

void funA(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        funB(n - 1);
    }
}

void funB(int n)
{
    if (n > 1)
    {
        cout << n << " ";
        funA(n / 2);
    }
}

/*
funA(20)
├── cout << 20                          // Prints 20
└── funB(19)                            // Calls funB(19)
    ├── cout << 19                      // Prints 19
    └── funA(9)                         // Calls funA(9)
        ├── cout << 9                   // Prints 9
        └── funB(8)                     // Calls funB(8)
            ├── cout << 8               // Prints 8
            └── funA(4)                 // Calls funA(4)
                ├── cout << 4           // Prints 4
                └── funB(3)             // Calls funB(3)
                    ├── cout << 3       // Prints 3
                    └── funA(1)         // Calls funA(1)
                        ├── cout << 1   // Prints 1
                        └── funB(0)     // Base case (returns)
*/

int main()
{
    funA(20); // 20 19 9 8 4 3 1

    return 0;
}