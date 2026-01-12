#include <iostream>

// LeetCode: 67. Add Binary
// https://leetcode.com/problems/add-binary/

/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:
    Input: a = "11", b = "1"
    Output: "100"

Example 2:
    Input: a = "1010", b = "1011"
    Output: "10101"
*/

class Solution // Time: O(max(n, m)) | Space: O(1)
{
public:
    std::string addBinary(std::string a, std::string b)
    {
        int maxLen = std::max(a.size(), b.size());
        std::string res;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry)
        {
            if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';

            res += carry % 2 + '0';
            carry /= 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    return 0;
}