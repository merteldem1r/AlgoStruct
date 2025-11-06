#include <iostream>

//  LeetCode: 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/description/

/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]

Example 2:

    Input: nums = [1], k = 1
    Output: [1]

Example 3:

    Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
    Output: [1,2]
*/

// Using Min Heap
class SolutionMinHeap // Time: O(nlogK) Space: O(n)
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> freqMap;
        for (auto &num : nums)
        {
            ++freqMap[num];
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        for (auto &entry : freqMap)
        {
            pq.push({entry.second, entry.first});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        std::vector<int> ans;
        for (int i = 0; i < k; ++i)
        {
            auto top = pq.top();
            ans.emplace_back(top.second);
            pq.pop();
        }

        return ans;
    }
};

int main()
{
}