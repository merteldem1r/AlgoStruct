#include <iostream>

// LeetCode: 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

/*
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?

Example 1:
    Input: nums = [3,2,1,5,6,4], k = 2
    Output: 5

Example 2:
    Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
    Output: 4

*/

class SolutionMinHeap // Time: O(nlogk) Space: O(k)
{
public:
    int findKthLargest(std::vector<int> &nums, int k)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (auto &num : nums)
        {
            pq.push(num);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        return pq.top();
    }
};

class SolutionMaxHeap // Time: O(nlogk) Space: O(k)
{
public:
    int findKthLargest(std::vector<int> &nums, int k)
    {
        std::priority_queue<int, std::vector<int>, std::less<int>> pq(nums.begin(), nums.end()); // Max Heapify Time: O(n)

        for (int i = k; i > 1; --i)
        {
            pq.pop();
        }

        return pq.top();
    }
};

class SolutionQuickSelect // Time Avg: O(n) Time Worst: O(n^2) Space: O(n)
{
public:
    int findKthLargest(std::vector<int> &nums, int k)
    {
        const int n = nums.size();
        int left = 0, right = n - 1, idx = n - k;

        while (true)
        {
            int pi = partition(nums, left, right);

            if (pi == idx)
                return nums[pi];

            if (pi > idx)
                right = pi - 1;
            else
                left = pi + 1;
        }

        return -1;
    }

    int partition(std::vector<int> &arr, int low, int high)
    {
        int pivot = arr[high];
        int i = low;

        for (int j = low; j < high; ++j)
        {
            if (arr[j] < pivot)
            {
                std::swap(arr[i], arr[j]);
                ++i;
            }
        }

        std::swap(arr[i], arr[high]);
        return i;
    }
};

int main()
{
    return 0;
}