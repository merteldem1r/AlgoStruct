#include <iostream>

// LeetCode: 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/

/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
Example 1:
    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]

Example 2:
    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]
*/

class SolutionBruteForce // Time: O(n^2) | Space: O(1) | TIME LIMIT EXCEEDED
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        std::vector<int> ans(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {
                if (i != j)
                {
                    ans[i] *= nums[j];
                }
            }
        }
        return ans;
    }
};

class SolutionDivision // Time: O(n) | Space: O(1)
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        int allProd = 1, zeroCount = 0;
        std::vector<int> ans(nums.size(), 0);

        for (int num : nums)
        {
            if (num != 0)
            {
                allProd *= num;
            }
            else
            {
                ++zeroCount;

                if (zeroCount > 1)
                {
                    return ans;
                }
            }
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (zeroCount > 0)
            {
                ans[i] = (nums[i] == 0) ? allProd : 0;
            }
            else
            {
                ans[i] = allProd / nums[i];
            }
        }
        return ans;
    }
};

// Solution without division using prefix and postfix products
class SolutionPrefixPostfix // Time: O(n) | Space: O(n)
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        int n = nums.size();

        std::vector<int> prefix(n);
        std::vector<int> postfix(n);
        std::vector<int> res(n);

        prefix[0] = 1;
        postfix[n - 1] = 1;

        // fill prefix
        for (int i = 1; i < n; ++i)
        {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }

        // fill postfix
        for (int i = n - 2; i >= 0; --i)
        {
            postfix[i] = nums[i + 1] * postfix[i + 1];
        }

        // fill result
        for (int i = 0; i < n; ++i)
        {
            res[i] = prefix[i] * postfix[i];
        }

        return res;
    }
};

int main()
{
    return 0;
}