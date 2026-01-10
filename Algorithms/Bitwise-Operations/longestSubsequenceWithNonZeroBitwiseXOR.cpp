#include <iostream>

// LeetCode: 3702. Longest Subsequence With Non-Zero Bitwise XOR
// https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/description/

/*
You are given an integer array nums.

Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.

Example 1:
    Input: nums = [1,2,3]

    Output: 2

Explanation:
    One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 = 1, which is non-zero.

Example 2:
    Input: nums = [2,3,4]
    Output: 3

Explanation:
    The longest subsequence is [2, 3, 4]. The bitwise XOR is computed as 2 XOR 3 XOR 4 = 5, which is non-zero.
*/

class Solution // Time: O(n) | Space: O(1)
{
public:
    int longestSubsequence(std::vector<int> &nums)
    {
        int sum = 0;
        int zeroCount = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 0)
                ++zeroCount;

            sum ^= nums[i];
        }

        if (zeroCount == n)
        {
            return 0;
        }

        return sum != 0 ? n : n - 1;
    }
};

int main()
{
    return 0;
}