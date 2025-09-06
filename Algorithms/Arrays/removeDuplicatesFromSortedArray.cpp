#include <iostream>

// LeetCode: 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums) // Time: O(n) Space: O(1)
    {
        int j = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[j] = nums[i];
                ++j;
            }
        }

        return j;
    }
};

int main()
{
    return 0;
}