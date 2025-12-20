#include <iostream>

// LeetCode: 342. Power of Four
// https://leetcode.com/problems/power-of-four/description/

/*
Given an integer n, return true if it is a power of four. Otherwise, return false.
An integer n is a power of four, if there exists an integer x such that n == 4^x.

Example 1:
    Input: n = 16
    Output: true
    Explanation: 4^2 = 16

Example 2:
    Input: n = 5
    Output: false
    Explanation: There is no x where 4^x = 5

Follow up: Could you solve it without loops/recursion?
*/

class SolutionBruteForce // Time: O(log n) Space: O(1)
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        while (n % 4 == 0)
        {
            n /= 4;
        }
        return n == 1;
    }
};

class SolutionMath // Time: O(1) Space: O(1)
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        double logBase4 = log10(n) / log10(4); // Change of base formula
        return logBase4 == static_cast<int>(logBase4);
    }
};

class SolutionBitwise // Time: O(1) Space: O(1)
{
public:
    bool isPowerOfFour(int n)
    {
        int oddBits = 0x55555555;

        return (n > 0) && ((n & (n - 1)) == 0) && ((n & oddBits) == n);
    }
};

int main()
{
    return 0;
}