#include <iostream>
#include <cmath>
#include <cmath>

// LeetCode: 973. K Closest Points to  Origin
// https://leetcode.com/problems/k-closest-points-to-origin/description/

/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).


Example 1:

    Input: points = [[1,3],[-2,2]], k = 1
    Output: [[-2,2]]
    Explanation:
    The distance between (1, 3) and the origin is sqrt(10).
    The distance between (-2, 2) and the origin is sqrt(8).
    Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
    We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
*/

class Compare
{
public:
    bool operator()(const std::pair<double, int> &a, const std::pair<double, int> &b) const
    {
        return a.first > b.first;
    }
};

class Solution
{
public:
    double originDistance(double x, double y)
    {
        return sqrt(x * x + y * y);
    }

    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points, int k) // Time: O(nlogN) Space: O(n)
    {
        if (points.size() == 1)
        {
            return {points[0]};
        }

        std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, Compare>
            pq;

        for (int i = 0; i < points.size(); ++i)
        {
            auto x = points[i][0], y = points[i][1];
            const auto distance =
                originDistance(static_cast<double>(x), static_cast<double>(y));

            pq.push({distance, i});
        }

        std::vector<std::vector<int>> res;
        res.reserve(k);

        for (int i = 0; i < k; ++i)
        {
            const auto [dis, idx] = pq.top();
            res.emplace_back(points[idx]);
            pq.pop();
        }

        return res;
    }
};