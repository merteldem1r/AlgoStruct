#include <iostream>

using namespace std;

// NESTED RECURSION
// recursive call taking parameter as recursive call
// recursion inside recursion

/*

    fun (int n) {
        if ( --- ) {
            ---
            ---
            fun(fun(n - 1)); // NESTED
        }
    };

*/

int fun(int n)
{
    if (n > 100)
    {
        return n - 10;
    }
    else
    {
        return fun(fun(n + 11));
    }
}

/*
fun(95)
└── fun(fun(106))                // Calls fun(106)
    └── return 106 - 10          // Returns 96
        └── fun(96)              // Calls fun(96)
            └── fun(fun(107))    // Calls fun(107)
                └── return 107 - 10 // Returns 97
                    └── fun(97)  // Calls fun(97)
                        └── fun(fun(108)) // Calls fun(108)
                            └── return 108 - 10 // Returns 98
                                └── fun(98) // Calls fun(98)
                                    └── fun(fun(99)) // Calls fun(99)
                                        └── fun(fun(100)) // Calls fun(100)
                                            └── fun(fun(101)) // Calls fun(101)
                                                └── return 101 - 10 // Returns 91
                                                    └── fun(91) // Calls fun(91)
                                                        └── fun(fun(102)) // Calls fun(102)
                                                            └── return 102 - 10 // Returns 92
                                                                └── fun(92) // Calls fun(92)
                                                                    └── fun(fun(103)) // Calls fun(103)
                                                                        └── return 103 - 10 // Returns 93
                                                                            └── fun(93) // Calls fun(93)
                                                                                └── fun(fun(104)) // Calls fun(104)
                                                                                    └── return 104 - 10 // Returns 94
                                                                                        └── fun(94) // Calls fun(94)
                                                                                            └── fun(fun(105)) // Calls fun(105)
                                                                                                └── return 105 - 10 // Returns 95
                                                                                                    └── fun(95) // Calls fun(95)
*/

int main()
{
    int a = fun(95);
    cout << a << endl; // 91

    return 0;
}