#include <iostream>

// LeetCode: 43. Multiply Strings
// https://leetcode.com/problems/multiply-strings/description/

/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:
    Input: num1 = "2", num2 = "3"
    Output: "6"

Example 2:
    Input: num1 = "123", num2 = "456"
    Output: "56088"
*/

class Solution
{
public:
    std::string multiply(std::string num1, std::string num2) // Time: O(m * n) Space: O(m + n)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }

        std::vector<int> res(num1.length() + num2.length(), 0);

        for (int i = num1.length() - 1; i >= 0; --i)
        {
            for (int j = num2.length() - 1; j >= 0; --j)
            {
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
            }
        }

        std::string ans = "";
        int start = 0;
        while (res[start] == 0)
            ++start;
        for (int i = start; i < res.size(); ++i)
        {
            const char c = res[i] + '0';
            ans.push_back(c);
        }

        return ans;
    }
};

int main()
{
    return 0;
}