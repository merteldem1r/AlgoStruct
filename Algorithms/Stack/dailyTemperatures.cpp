#include <iostream>

// LeetCode: 739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/description/

// link to understand the Monotonic Stack concept: https://www.geeksforgeeks.org/dsa/introduction-to-monotonic-stack-2/

/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:
    Input: temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]

Example 2:
    Input: temperatures = [30,40,50,60]
    Output: [1,1,1,0]

Example 3:
    Input: temperatures = [30,60,90]
    Output: [1,1,0]
*/

// WON'T WORK ON LEETCODE due to Time Limit Exceed
class SolutionBruteForce // Time: O(n^2) Space: O(1)
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
    {
        const int n = temperatures.size();

        if (n == 1)
        {
            return {0};
        }

        std::vector<int> res(temperatures.size());

        for (int i = 0; i < n; ++i)
        {
            int days = 1;

            for (int j = i + 1; j < n; ++j)
            {
                if (temperatures[j] > temperatures[i])
                {
                    res[i] = days;
                    break;
                }
                ++days;
            }
        }

        return res;
    }
};

class SolutionMonotonicStack // Time: O(n) Space: O(n)
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
    {
        const int n = temperatures.size();

        if (n == 1)
        {
            return {0};
        }

        std::vector<int> res(n);
        std::stack<std::pair<int, int>> stack;

        stack.push({temperatures[0], 0});
        for (int i = 1; i < n; ++i)
        {
            int t = temperatures[i];

            while (!stack.empty() && t > stack.top().first)
            {
                auto [val, indx] = stack.top();
                stack.pop();
                res[indx] = i - indx;
            }
            stack.push({t, i});
        }

        return res;
    }
};

int main()
{
    return 0;
}