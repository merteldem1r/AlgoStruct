#include <iostream>

// LeetCode: 57. Insrt Interval
// https://leetcode.com/problems/insert-interval/description/

/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.
Note that you don't need to modify intervals in-place. You can make a new array and return it.

Example 1:
    Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    Output: [[1,5],[6,9]]

Example 2:
    Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    Output: [[1,2],[3,10],[12,16]]
    Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval) // Time: O(n) Space: O(n)
    {
        std::vector<std::vector<int>> res;
        int i = 0;

        // case 1: no overlap
        while (i < intervals.size() && newInterval[0] > intervals[i][1])
        {
            res.emplace_back(intervals[i++]);
        }

        // case 2: overlap case (merge intervals)
        while (i < intervals.size() && newInterval[1] >= intervals[i][0])
        {
            newInterval[0] = std::min(intervals[i][0], newInterval[0]);
            newInterval[1] = std::max(intervals[i][1], newInterval[1]);
            ++i;
        }
        res.emplace_back(newInterval);

        // case 3: no overlap after inserted new interval
        while (i < intervals.size())
        {
            res.emplace_back(intervals[i++]);
        }

        return res;
    } 
};