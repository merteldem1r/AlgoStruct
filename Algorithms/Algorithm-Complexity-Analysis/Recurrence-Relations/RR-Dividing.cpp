#include <iostream>

// Recurrence Relations & Master Theorem for DECREASING Functions
// AUTHOR: Mert Eldemir

// informative link: https://www.geeksforgeeks.org/dsa/recurrence-relations-a-complete-guide/
// course: https://www.udemy.com/course/datastructurescncpp/ by Abdul Bari - best instructor

//  ************** Recurrence Relations for DIVIDING Functions  **************

// Dividing Functions | T(n) = T(n / 2) + 1
void func4(int n) // TOTAL: T(n) = T(logN) Logarithmic
{
    if (n <= 1)
        return;

    std::cout << n << std::endl; // O(1)
    func4(n / 2);                // T(n / 2)
}

/*
SOLUTION (Successive Substitution):
     Recurrence: T(n) = T(n/2) + 1

     1. T(n) = T(n/2) + 1
     2. T(n/2) = T(n/4) + 1  -> substitute into (1):
         T(n) = (T(n/4) + 1) + 1 = T(n/4) + 2
     3. T(n/4) = T(n/8) + 1  ->
         T(n) = T(n/8) + 3
     ...

     After k substitutions:
         T(n) = T(n / 2^k) + k

     One the base case; n / 2^k = 1  =>  2^k = n  =>  k = log_2 n

     then:
         T(n) = T(1) + log_2 n = T(log n)

     So the function runs in logarithmic time = O(logN)
*/

// ************************************************************************

// RR | T(n) = T(n / 2) + n
void func5(int n) // TOTAL: T(n) = T(n) Linear
{
    if (n <= 1)
        return;

    for (int i = 0; i < n; ++i)
    {
        std::cout << i << std::endl; // O(1)
    } // O(n)

    func5(n / 2); // T(n / 2)
}

/*
SOLUTION (Successive Substitution):
     Recurrence: T(n) = T(n/2) + n

     1. T(n) = T(n/2) + n
     2. T(n/2) = T(n/4) + n/2  -> substitute into (1):
         T(n) = (T(n/4) + n/2) + n = T(n/4) + n + n/2
     3. T(n/4) = T(n/8) + n/4  ->
         T(n) = T(n/8) + n + n/2 + n/4
     ...

     After k substitutions:
         T(n) = T(n / 2^k) + n*(1 + 1/2 + 1/4 + ... + 1/2^{k-1})

     Stop when n / 2^k = 1  =>  2^k = n  =>  k = log_2 n

     The geometric series sums to < 2, so the sum term = T(n).
     Therefore:
         T(n) = T(1) + T(n) = T(n)

     So the recurrence solves to linear time = O(n)
*/

// ************************************************************************

// RR | T(n) = 2T(n / 2) + 1
void func6(int n) // TOTAL: T(n) = T(n) Linear
{
    if (n <= 1)
        return;

    std::cout << n << std::endl; // O(1)
    func6(n / 2);                // T(n / 2)
    func6(n / 2);                // T(n / 2)
}

/*
SOLUTION (Successive Substitution):
     Recurrence: T(n) = 2T(n/2) + 1

     1. T(n) = 2T(n/2) + 1
     2. T(n/2) = 2T(n/4) + 1  -> substitute into (1):
         T(n) = 2(2T(n/4) + 1) + 1 = 4T(n/4) + 2 + 1
     3. T(n/4) = 2T(n/8) + 1  ->
         T(n) = 8T(n/8) + 4 + 2 + 1
     ...

     After k substitutions:
         T(n) = 2^k T(n / 2^k) + (2^k - 1)

     Stop when n / 2^k = 1  =>  2^k = n  =>  k = log_2 n

     Then:
         T(n) = n T(1) + (n - 1) = T(n)

     So the recurrence solves to linear time = O(n)
*/

// ************************************************************************

// RR | T(n) = 2T(n / 2) + n
void func7(int n) // TOATAL: T(n) = T(nlogN)
{
    if (n <= 1)
        return;

    for (int i = 0; i < n; ++i)
    {
        std::cout << n << std::endl; // O(1)
    } // O(n)

    func7(n / 2); // T(n / 2)
    func7(n / 2); // T(n / 2)
}

/*
SOLUTION (Successive Substitution):
     Recurrence: T(n) = 2T(n/2) + n

     1. T(n) = 2T(n/2) + n
     2. T(n/2) = 2T(n/4) + n/2  -> substitute into (1):
         T(n) = 2(2T(n/4) + n/2) + n = 4T(n/4) + n + n = 4T(n/4) + 2n
     3. T(n/4) = 2T(n/8) + n/4  ->
         T(n) = 8T(n/8) + 3n
     ...

     After k substitutions:
         T(n) = 2^k T(n / 2^k) + k * n

     Stop when n / 2^k = 1  =>  2^k = n  =>  k = log_2 n

     Then:
         T(n) = n T(1) + n * log_2 n = T(n log n)

     So the recurrence solves to T(n) = T(nlogN)
*/

// ************************************************************************

// RR | T(n) = 2T(n / 2) + n^2
void func8(int n)
{
    if (n <= 1)
        return;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << i + j << std::endl; // O(1)
        }
    } // O(n^2)

    func8(n / 2); // T(n / 2)
    func8(n / 2); // T(n / 2)
}

/*
SOLUTION (Successive Substitution):
     Recurrence: T(n) = 2T(n/2) + n^2

     1. T(n) = 2T(n/2) + n^2
     2. T(n/2) = 2T(n/4) + (n/2)^2  -> substitute into (1):
         T(n) = 2(2T(n/4) + n^2/4) + n^2 = 4T(n/4) + n^2/2 + n^2
                = 4T(n/4) + 3n^2/2
     3. T(n/4) = 2T(n/8) + (n/4)^2  ->
         T(n) = 8T(n/8) + n^2 + n^2/2 + n^2/4
     ...

     After k substitutions:
         T(n) = 2^k T(n / 2^k) + n^2(1 + 1/2 + 1/4 + ... + 1/2^{k-1})

     Stop when n / 2^k = 1  =>  2^k = n  =>  k = log_2 n

     The geometric series is bounded by 2, so:
         T(n) = n * T(1) + T(n^2)

     Since n^2 dominates n, the final answer is:
         T(n) = T(n^2)

     So the recurrence solves to quadratic time = O(n^2)
*/

// ************************************************************************

// MASTER THEOREM for DIVIDING Functions

/*
    MASTER THEOREM:

        General form:

            T(n) = aT(n / b) + f(n)

            a:    number of recursive calls
            b:    input division factor
            f(n): work done outside recursion

        Practical method:
            Write f(n) as:
                f(n) = n^k * log^p(n)

            Then compare:
                log_b(a)  with  k


        1. CASE: Recursive part dominates
            If:
                log_b(a) > k

            Then:
                T(n) = O(n^(log_b(a)))


        2. CASE: Balanced case
            If:
                log_b(a) == k

            Then:
                T(n) = O(n^k * log^(p + 1)(n))

        3. CASE: Outside work dominates
            If:
                log_b(a) < k

            Then:
                T(n) = O(f(n))

        Quick examples:
            1.  T(n) = 4T(n / 2) + n
                log_2(4) = 2, k = 1
                2 > 1  =>  O(n^2)

            2.  T(n) = 2T(n / 2) + n
                log_2(2) = 1, k = 1
                1 == 1 =>  O(n log n)

            3.  T(n) = 2T(n / 2) + n^2
                log_2(2) = 1, k = 2
                1 < 2  =>  O(n^2)
*/

int main()
{
    return 0;
}