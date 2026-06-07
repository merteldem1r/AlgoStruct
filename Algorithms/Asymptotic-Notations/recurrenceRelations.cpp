#include <iostream>

// Recurrence Relations & Master Theorem
// Author: Mert Eldemir

// informative link: https://www.geeksforgeeks.org/dsa/recurrence-relations-a-complete-guide/
// course: https://www.udemy.com/course/datastructurescncpp/ by Abdul Bari - best instructor

/*
A recurrence relation is a mathematical expression that defines a sequence in terms of its previous terms. In the context of algorithmic analysis, it is often used to model the time complexity of recursive algorithms.
*/

//  ************** Recurrence Relations for DECREASING Functions  **************

// Simple Decreasing Recursion | T(n) = T(n - 1) + 1
void func1(int n) // TOTAL: T(n) = T(n) — linear time
{
    if (n <= 0)
    {
        return; // base case
    }

    std::cout << n << std::endl; // time: O(1)
    func1(n - 1);                // time: T(n - 1)
}

/*
SOLUTION:
    1. T(n) = T(n - 1) + 1
    2. T(n) = (T((n - 1) - 1) + 1) + 1 = T(n - 2) + 2
    3. T(n) = T(n - 3) + 3
        ...

    Pattern: T(n - k) + k
    Base case = {1; n = 0} then,
    if k = n -> T(n - n) + n
    T(0) + n = 1 + n = n
    so T(n - 1) + 1 = n
*/

// ************************************************************************

// Recurrence Relation | T(n) = T(n - 1) + n
void func2(int n) // TOTAL: T(n) = T(n^2)
{
    if (n <= 0)
    {
        return; // base case
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << i << std::endl;
    }

    func2(n - 1);
}

/*
SOLUTION:
    T(n) = T(n - 1) + n
    Expand:
      T(n) = T(n - 1) + n
           = (T(n - 2) + (n - 1)) + n
           = T(n - 2) + (n - 1) + n
           = T(n) = T(n - 3) + (n - 2) + (n - 1) + n
           = ...
           = T(n) = T(n - k) + (n - k + 1) + (n - k + 2) + ... + (n - 2) + (n - 1) + n

           Base case = {1; n = 0} then, let's pick k = n
           T(n) = T(0) + (n - n + 1) + (n - n + 2) + ... + (n - 2) + (n - 1) + n
                = 1 + [1 + 2 + 3 + ... + (n - 2) + (n - 1) + n]
                so here we have first n natural numbers is [] brackets
                = 1 + n(n + 1) / 2

            finally we have:

            T(n) = 1 + n(n + 1) / 2 = 1 + (n^2 + n) / 2
                 = O(n^2) Quadratic

    so T(n - 1) + n is T(n^2)
*/

// ************************************************************************

// Recurrence Relation | T(n) = 2T(n - 1) + 1
void func3(int n) // TOTAL: T(n) = T(2^n)
{
    if (n <= 0)
    {
        return; // base case
    }

    std::cout << n << std::endl; // O(1)
    func3(n - 1);                // T(n - 1)
    func3(n - 1);                // T(n - 1)
}

/*
SOLUTION:
    T(n) = 2T(n - 1) + 1
    Expand:
      T(n) = 2T(n - 1) + 1
           = 2(2T(n - 2) + 1) + 1 = 4T(n - 2) + 2 + 1
           = 4(2T(n - 3) + 1) + 3 = 8T(n - 3) + 4 + 2 + 1
           = ...
           = 2^k T(n - k) + (2^k - 1)

    Base case k = n ->
      T(n) = 2^n T(0) + (2^n - 1) = T(2^n)

    Therefore the recurrence solves to exponential time: T(n) = T(2^n) Exponential
*/

// ************************************************************************

// MASTER THEOREM for Decreasing Functions
// informative link: https://www.geeksforgeeks.org/dsa/master-theorem-subtract-conquer-recurrences/

/*
    From the previous solutions, what we found:
        * T(n )= T(n - 1) + 1     => O(n)    Linear
        * T(n) = T(n - 1) + n     => O(n^2)  Quadratic
        * T(n) = 2T(n - 2) + 1    => O(2^n)  Exponential

        then we can assume or some kind guess that:

        * T(n) = T(n - 2) + 1     => O(n)
        * T(n) = T(n - 1) + n^2   => O(n^2)
        * T(n) = T(n - 1) + logn  => O(nlogN)
        * T(n) = 3T(n - 1) + 1    => O(3^n)
        * T(n) = 2T(n - 1) + n    => O(n2^n)

        by successive substitution as we made it on previous examples we can get those results as well

        Bu we also can find the answer for a recurrence relation directly
        without following successive substitution with the general form and Master Theorem.


    MASTER THEOREM:

        Master theorem is used to determine the Big - O upper bound on functions which possess recurrence, i.e which can be broken into sub problems.

        General Form of Recurrence Relation for DECREASING functions:
        T(n) = aT(n - b) + f(n)
            a:    number of recursive calls (how many tames it call itself in algorithm)
            b:    decreased value
            f(n): what we actually do in algorithm

        1. CASE a = 1:
            T(n) = O(n * f(n))

                EX: T(n) = T(n - 2) + n
                    = O(n^2)

        2. CASE a > 1:
            T(n) = O(a^(n/b) * f(n))

                EX: T(n) = 2T(n - 3) + n
                    = O(n2^(n/3))

        3. CASE a < 1:
            Actually this is not possible, becuase recursive function should call itself at least 1 time, but mathematically the answer will be:

            T(n) = O(f(n))
*/

// ************************************************************************

//  ************** Recurrence Relations for DIVIDING Functions  **************

int main()
{
    return 0;
}