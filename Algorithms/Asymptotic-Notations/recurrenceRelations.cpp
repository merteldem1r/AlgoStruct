#include <iostream>

// Re
// informative link: https://www.geeksforgeeks.org/dsa/recurrence-relations-a-complete-guide/
// course: https://www.udemy.com/course/datastructurescncpp/ by Abdul Bari

/*
A recurrence relation is a mathematical expression that defines a sequence in terms of its previous terms. In the context of algorithmic analysis, it is often used to model the time complexity of recursive algorithms.

General form of Reccurence Relation:

        T(n) = aT(n - b) + f(n)
            a: number of recursive calls (how may tames it call itself in algorithm)
            b: decreased value

*/

// Decreasing Function | T(n) = T(n - 1) + 1
void func1(int n) // TOTAL: T(n) - this is linear time
{
    if (n <= 0)
    {
        return; // base case
    }

    std::cout << n << std::endl; // time: 1
    return func1(n - 1);         // time: T(n - 1)
}

/*
T(n) = T(n - 1) + 1
1. T(n - 1) = (T((n - 1) - 1) + 1) + 1 = T(n - 2) + 2
2. T(n - 2) = T(n - 3) + 3
    ...

Pattern: T(n - k) + k
Base case = {n = 0; 1} then,
if k = n -> T(n - n) + n equal to:
T(0) + n = 1 + n    =>    n
so T(n - 1) + 1 = n
*/

// ************************************************************************

//  RR | T(n) = T(n - 1) + n

// ************************************************************************

int main()
{
    return 0;
}