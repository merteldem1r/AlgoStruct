#include <iostream>

// LeetCode: 303. Range Sum Query - Immutable
// https://leetcode.com/problems/range-sum-query-immutable/description/

/*
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

Example 1:

    Input
        ["NumArray", "sumRange", "sumRange", "sumRange"]
        [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
    Output
        [null, 1, -1, -3]
    Explanation
        NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
        numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
        numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
        numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
*/

class NumArray // Time: O(n) space: O(n)
{
private:
    std::vector<int> nums;

public:
    NumArray(std::vector<int> &nums)
    {
        this->nums = nums;
    }

    int sumRange(int left, int right)
    {
        int res = 0;
        for (int i = left; i <= right; ++i)
        {
            res += nums[i];
        }

        return res;
    }
};

class NumArrayOptmal // Time: O(1) space: O(n)
{
private:
    std::vector<int> numsArr;

public:
    NumArrayOptmal(std::vector<int> &nums)
    {
        numsArr = nums;
        for (int i = 1; i < nums.size(); ++i)
        {
            numsArr[i] = numsArr[i - 1] + numsArr[i];
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
        {
            return numsArr[right];
        }

        return numsArr[right] - numsArr[left - 1];
    }
};

int main()
{
    return 0;
}