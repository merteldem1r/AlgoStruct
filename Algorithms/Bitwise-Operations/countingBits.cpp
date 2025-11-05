#include <iostream>

// LeetCode: 338. Counting Bits
// https://leetcode.com/problems/counting-bits/description/

/*

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:

    Input: n = 2
    Output: [0,1,1]
    Explanation:
    0 --> 0
    1 --> 1
    2 --> 10

Example 2:

    Input: n = 5
    Output: [0,1,1,2,1,2]
    Explanation:
    0 --> 0
    1 --> 1
    2 --> 10
    3 --> 11
    4 --> 100
    5 --> 101
*/

class SolutionBit1 // Time: O(nlogn) Space: (n)
{
public:
    int bitCount(int num)
    {
        int count = 0;

        while (num != 0)
        {
            count += num & 1;
            num >>= 1;
        }

        return count;
    }

    std::vector<int> countBits(int n)
    {
        std::vector<int> ans(n + 1);

        for (int i = 0; i < n + 1; ++i)
        {
            const int count = bitCount(i);
            ans.emplace_back(count);
        }

        return ans;
    }
};

class SolutionDynamic // Time: O(n) Space: (n)
{
public:
    std::vector<int> countBits(int n)
    {
        std::vector<int> dp(n + 1);
        int offset = 1;

        for (int i = 1; i <= n; ++i)
        {
            if (offset * 2 == i)
            {
                offset = i;
            }

            dp[i] = 1 + dp[i - offset];
        }

        return dp;
    }
};

class SolutionBit2 // Time: O(n) Space: (n)
{
public:
    std::vector<int> countBits(int n)
    {
        std::vector<int> ans(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};

int main()
{
    return 0;
}