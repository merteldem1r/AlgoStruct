#include <iostream>

// Re
// informative link: https://www.geeksforgeeks.org/dsa/recurrence-relations-a-complete-guide/
// course: https://www.udemy.com/course/datastructurescncpp/ by Abdul Bari

/*
A recurrence relation is a mathematical expression that defines a sequence in terms of its previous terms. In the context of algorithmic analysis, it is often used to model the time complexity of recursive algorithms.

General form of Reccurence Relation:

        T(n) = aT(n - b) + f(n)
            a:    number of recursive calls (how may tames it call itself in algorithm)
            b:    decreased value
            f(n): what we actually do in algorithm

*/

// Simle Decreasing Recursion | T(n) = T(n - 1) + 1
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
SOLUTION:
    1. T(n) = T(n - 1) + 1
    2. T(n - 1) = (T((n - 1) - 1) + 1) + 1 = T(n - 2) + 2
    3. T(n - 2) = T(n - 3) + 3
        ...

    Pattern: T(n - k) + k
    Base case = {1; n = 0} then,
    if k = n -> T(n - n) + n
    T(0) + n = 1 + n = n
    so T(n - 1) + 1 = n
*/

// ************************************************************************

//  Recurrence Relation | T(n) = T(n - 1) + n
void func2(int n) // TOTAL: T(n^2)
{
    if (n > 0)
    {
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << i << std::endl;
    }

    return func2(n - 1);
}

/*
SOLUTION:
    1. T(n) = T(n - 1) + n
    2. T(n - 1) = (T((n - 1) - 1) + n) + n = T(n - 2) + 2n
    3. T(n - 2) = T(n - 3) + 3n
        ...

    Pattern: T(n - k) + kn
    Base case: {1; n = 0}
    if k = n -> T(n - n) + n * n
    T(0) + n^2 = 1 + n^2 = n^2
    so T(n - 1) + n = n^2
*/

// ************************************************************************

int main()
{
    return 0;
}