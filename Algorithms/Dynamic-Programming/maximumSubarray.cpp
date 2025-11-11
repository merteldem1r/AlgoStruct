#include <iostream>

// LeetCode: 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/description/
/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:
    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
    Input: nums = [1]
    Output: 1
    Explanation: The subarray [1] has the largest sum 1.

Example 3:
    Input: nums = [5,4,-1,7,8]
    Output: 23
    Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
*/

// Kadane's Algorithm
class Solution // Time: O(n) Space: O(1)
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        int res = nums[0];
        int tempMax = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            tempMax = std::max(nums[i], nums[i] + tempMax);
            res = std::max(res, tempMax);
        }

        return res;
    }
};

// Divide and Conquer Approach
class Solution // Time: O(nlogN) Space: O(logN)
{
public:
    int helper(std::vector<int> &nums, int l, int h)
    {
        if (l > h)
        {
            return INT_MIN;
        }

        int leftMax = 0, rightMax = 0;
        int mid = l + (h - l) / 2;

        for (int i = mid - 1, sum = 0; i >= l; --i)
        {
            sum += nums[i];
            leftMax = std::max(sum, leftMax);
        }

        for (int i = mid + 1, sum = 0; i <= h; ++i)
        {
            sum += nums[i];
            rightMax = std::max(sum, rightMax);
        }

        int maxLeftRight = std::max(helper(nums, l, mid - 1), helper(nums, mid + 1, h));
        return std::max(maxLeftRight, leftMax + nums[mid] + rightMax);
    }

    int maxSubArray(std::vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }
};

int main()
{
    return 0;
}