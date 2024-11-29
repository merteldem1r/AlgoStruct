#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// nCr -> Combination Formula

// C(n, r) = n! / [r! (n - r)!]
// n = total item count
// r = choose item count

// Combination Using Pascal Triangle

/*

    Pascal's Triangle visualization for n = 5

        Row 0:            1 (0C0)
        Row 1:          1   1 (1C0, 1C1)
        Row 2:        1   2   1 (2C0, 2C1, 2C2)
        Row 3:      1   3   3   1 (3C0, 3C1, 3C2, 3C3)
        Row 4:    1   4   6   4   1 (4C0, 4C1, 4C2, 4C3, 4C4)
        Row 5:  1   5  10  10   5   1 (5C0, 5C1, 5C2, 5C3, 5C4, 5C5)

        Example calculation:
        To calculate 5C3:
        Look at Row 5, Column 3 (0-indexed).
        Result: 5C3 = 10

 */

int combinationPascal(int n, int r) // Time: O(2^n) || Space: O(n)
{
    if (r == 0 || n == r)
        return 1;

    return combinationPascal(n - 1, r - 1) + combinationPascal(n - 1, r);
}

// Combination Using Factorial Formula

void factorial(int n, int factArr[])
{
    factArr[0] = 1;
    factArr[1] = 1;

    int res = 1;

    for (int i = 2; i <= n; ++i)
    {
        res *= i;
        factArr[i] = res;
    }
}

int combinationFactorial(int n, int r) // Time: O(n) || Space: O(n)
{
    if (r == 0 || r == n)
        return 1;

    int *factArr = new int[n];
    factorial(n, factArr);

    const int res = factArr[n] / (factArr[r] * factArr[n - r]);

    delete factArr;

    return res;
}

// Optimized Calculation Method

// Note: C(n, r) = C(n, n-r)
//     : C(7, 5) = C(7, 2)

// C(7, 2) = (7 * 6) / (1 * 2)

int numerDenumerCalculation(int n, int r) // Time: O(r) || Space: O(1)
{
    if (r == 0 || r == n || n - 1 == 1)
        return 1;

    int lowestR = min(r, n - r);

    int numer = 1;
    int denumer = 1;

    for (; lowestR >= 1; --lowestR)
    {
        numer *= n--;
        denumer *= lowestR;
    }

    return numer / denumer;
}

int main()
{
    // Using Factorial
    cout << "Combination Factorial: " << combinationFactorial(3, 2) << endl; // 3
    cout << "Combination Factorial: " << combinationFactorial(7, 3) << endl; // 35

    // Using Pascal Triangle
    cout << "Combination Pascal: " << combinationFactorial(8, 3) << endl; //

    // Using Numerator Denumerator Method
    cout << "combination Numerator Denumerator: " << combinationFactorial(5, 4) << endl;  // 5
    cout << "combination Numerator Denumerator: " << combinationFactorial(12, 4) << endl; // 495

    return 0;
}