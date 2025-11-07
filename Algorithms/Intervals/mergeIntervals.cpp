#include <iostream>

// LeetCode: 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/description/

/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
    Input: intervals = [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Example 3:
    Input: intervals = [[4,7],[1,4]]
    Output: [[1,7]]
    Explanation: Intervals [1,4] and [4,7] are considered overlapping.
*/

class SolutionSort // Time: O(nlogN) Space: O(n)
{
public:
    static bool comparator(const std::vector<int> &a, const std::vector<int> &b)
    {
        return a[0] < b[0];
    }

    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
    {
        std::sort(intervals.begin(), intervals.end(), comparator);
        std::vector<std::vector<int>> res;
        res.emplace_back(intervals[0]);

        int i = 1;
        while (i < intervals.size())
        {
            if (res.back()[1] < intervals[i][0])
            {
                // case 1: no overlap
                res.emplace_back(intervals[i]);
                ++i;
            }
            else
            {
                // case 2: overlap found
                res.back()[1] = std::max(intervals[i][1], res.back()[1]);
                ++i;
            }
        }

        return res;
    }
};

class SolutionSortInPlace // Time: O(nlogN) Space: O(1)
{
public:
    static bool comparator(const std::vector<int> &a, const std::vector<int> &b)
    {
        return a[0] < b[0];
    }

    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
    {
        std::sort(intervals.begin(), intervals.end(), comparator);
        std::vector<std::vector<int>> res;
        res.emplace_back(intervals[0]);

        int i = 1;
        int j = 0;
        while (i < intervals.size())
        {
            if (intervals[j][1] < intervals[i][0])
            {
                // case 1: no overlap
                ++j;
                intervals[j] = intervals[i];
            }
            else
            {
                // case 2: overlap found
                intervals[j][1] = std::max(intervals[i][1], intervals[j][1]);
            }
            ++i;
        }

        intervals.resize(j + 1);
        return intervals;
    }
};

int main()
{
    return 0;
}