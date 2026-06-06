#include <iostream>

// Re
// informative link: https://www.geeksforgeeks.org/dsa/recurrence-relations-a-complete-guide/
// course: https://www.udemy.com/course/datastructurescncpp/ by Abdul Bari

/*
A recurrence relation is a mathematical expression that defines a sequence in terms of its previous terms. In the context of algorithmic analysis, it is often used to model the time complexity of recursive algorithms.
*/

// T(n) = T(n - 1) + 1
void func1(int n) // TOTAL: T(n) - this is linear time
{
    if (n <= 0)
    {
        return; // base case
    }

    std::cout << n << std::endl; // time: 1
    return func1(n - 1);         // time: T(n - 1)
}

//

int main()
{
    return 0;
}