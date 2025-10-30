#include <iostream>

// LeetCode: 66. Plus One
// https://leetcode.com/problems/plus-one/description/

/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example 1:
    Input: digits = [1,2,3]
    Output: [1,2,4]
    Explanation: The array represents the integer 123.
    Incrementing by one gives 123 + 1 = 124.
    Thus, the result should be [1,2,4].

*/

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int> &digits) // Time: O(n) Space: O(1)
    {
        int carry = 1;

        for (int i = digits.size() - 1; i >= 0; --i)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i] += carry;
                carry = 0;
                break;
            }
        }

        if (carry)
        {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};