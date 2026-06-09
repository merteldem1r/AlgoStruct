#include <iostream>

// 0/1 Knapsack Problem - Dynamic Programming
// For reading: https://www.geeksforgeeks.org/dsa/0-1-knapsack-problem-dp-10/

/*
The 0/1 Knapsack Problem is an optimization problem.

    We have:

    * A bag/knapsack with a maximum weight capacity
    * Several items
    * Each item has:
        a weight
        a value/profit

    Goal is:

    Choose items to put into the knapsack so that the total value is maximized, but the total weight does not exceed the capacity.

    For each item, you either take it completely or you do not take it at all.
    So each item has only two choices:
        0 → do not take the item
        1 → take the item
*/

// Naive Approach - Recursive Solution
int knapsackRecursive(const std::vector<int> &values, const std::vector<int> &wt, int idx, int remainCap) // Time: O(2^n) Space: O(n)
{
    if (remainCap == 0 || idx >= wt.size())
    {
        return 0;
    }

    // case 1: skip item
    int skip = knapsackRecursive(values, wt, idx + 1, remainCap);

    // case 2: take item (if not exceed)
    int take = 0;

    if (wt[idx] <= remainCap)
    {
        // go to next value, reduce remain capacity
        take = values[idx] + knapsackRecursive(values, wt, idx + 1, remainCap - wt[idx]);
    }

    return std::max(skip, take);
}

int knapsackMemoization(const std::vector<int> &values, const std::vector<int> &wt, int idx, int remainCap, std::vector<int> &memo)
{
}

int main()
{
    std::vector<int> values = {1, 4, 5, 7};
    std::vector<int> weights = {1, 3, 4, 5};

    int cap = 7;

    // 1: Naive (recursive)
    int resRecursive = knapsackRecursive(values, weights, 0, cap);

    std::cout << "max value: " << resRecursive << std::endl;

    return 0;
}