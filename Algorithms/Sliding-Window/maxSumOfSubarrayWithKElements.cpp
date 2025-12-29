#include <iostream>

// Example Problem - Maximum Sum of a Subarray with K Elements
// https://www.geeksforgeeks.org/dsa/window-sliding-technique/

/*
Given an array arr[] and an integer k, we need to calculate the maximum sum of a subarray having size exactly k.

Input  : arr[] = [5, 2, -1, 0, 3], k = 3
Output : 6
Explanation : We get maximum sum by considering the subarray [5, 2 , -1]

Input  : arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
Output : 39
Explanation : We get maximum sum by adding subarray [4, 2, 10, 23] of size 4.
*/

class SolutionNaive // Time: O(n*k) | Space: O(1)
{
public:
    int maxSumKElements(std::vector<int> &arr, int k)
    {
        int maxSum = INT_MIN;
        for (int i = 0; i <= arr.size() - k; ++i)
        {
            int currentSum = 0;
            for (int j = 0; j < k; ++j)
            {
                currentSum += arr[i + j];
            }
            maxSum = std::max(maxSum, currentSum);
        }
        return maxSum;
    }
};

class SolutionSlidingWindow // Time: O(n) | Space: O(1)
{
public:
    int maxSumKElements(std::vector<int> &arr, int k)
    {
        if (arr.size() < k)
            return -1; // Not enough elements for a subarray of size k

        int windowSum = 0;
        for (int i = 0; i < k; ++i) // Initialize the first window
        {
            windowSum += arr[i];
        }

        int maxSum = windowSum;
        for (int i = k; i < arr.size(); ++i) // Slide the window ahead by one element and update sums
        {
            windowSum += arr[i] - arr[i - k];
            maxSum = std::max(maxSum, windowSum);
        }
        return maxSum;
    }
};

int main()
{
    return 0;
}