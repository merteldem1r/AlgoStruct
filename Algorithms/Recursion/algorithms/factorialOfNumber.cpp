#include <iostream>

using namespace std;

// Factorial

int factorial(int n) // Time: O(n) | Space: O(n)
{
    if (n <= 1)
    {
        return 1;
    }

    return factorial(n - 1) * n;
}

int factorialLoop(int n) // // Time: O(n) | Space: O(1)
{
    int res = 1;

    for (int i = n; i > 1; --i)
    {
        res *= i;
    }

    return res;
}

int main()
{

    cout << "factorial: " << factorial(5) << endl;         // 120
    cout << "factorialLoop: " << factorialLoop(4) << endl; // 24

    return 0;
}