#include <iostream>

// 169. Majority Element
// https://leetcode.com/problems/majority-element/description/

/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
    Input: nums = [3,2,3]
    Output: 3

Example 2:
    Input: nums = [2,2,1,1,1,2,2]
    Output: 2

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

class SolutionBruteForce // Time: O(n^2) | Space: O(1)
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        const int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int count = 0;

            for (int j = 0; j < n; ++j)
            {
                if (nums[j] == nums[i])
                {
                    ++count;
                }
            }

            if (count > n / 2)
            {
                return nums[i];
            }
        }
        return 0;
    }
};

class SolutionHashMap // Time: O(n) | Space: O(n)
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        const int n = nums.size();
        std::unordered_map<int, int> freqMap;

        for (auto &num : nums)
        {
            ++freqMap[num];

            if (freqMap[num] > n / 2)
            {
                return num;
            }
        }

        return 0;
    }
};

class SolutionSorting // Time: O(n log n) | Space: O(1)
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n / 2];
    }
};

class SolutionBoyerMooreVoting // Time: O(n) | Space: O(1)
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int res = nums[0];
        int count = 1;
        const int n = nums.size();

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] == res)
            {
                ++count;
            }
            else
            {
                --count;
                if (count == 0)
                {
                    res = nums[i];
                    count = 1;
                }
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}