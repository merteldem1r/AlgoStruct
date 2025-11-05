#include <iostream>

// LeetCode:
// https://leetcode.com/problems/sum-of-two-integers/description/

/*
Given two integers a and b, return the sum of the two integers without using the operators + and -.

Example 1:

    Input: a = 1, b = 2
    Output: 3

Example 2:

    Input: a = 2, b = 3
    Output: 5
*/

class Solution // Time: O(1) Space: O(1)
{
public:
    int getSum(int a, int b)
    {
        int carry;

        while (b != 0)
        {
            carry = a & b;
            a ^= b;
            b = carry << 1;
        }

        return a;
    }
};

int main()
{
    return 0;
}