#include <iostream>

// LeetCode: 875. Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas/description/

/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:
    Input: piles = [3,6,7,11], h = 8
    Output: 4

Example 2:
    Input: piles = [30,11,23,4,20], h = 5
    Output: 30

Example 3:
    Input: piles = [30,11,23,4,20], h = 6
    Output: 23
*/

// WON'T WORK ON LEETCODE due to Time Limit Exceed
class SolutionBruteForce // Time: O(m * n) Space: O(1)
{
public:
    int minEatingSpeed(std::vector<int> &piles, int h)
    {
        const int max = *std::max_element(piles.begin(), piles.end());

        int k = 1;
        while (k <= max)
        {
            long long totalTime = 0;
            for (int pile : piles)
            {
                totalTime += (pile + k - 1) / k;
            }

            if (totalTime <= h)
            {
                return k;
            }
            k++;
        }

        return k;
    }
};

class SolutionBinarySearch // Time: O(m * logn) Space: O(1)
{
public:
    int minEatingSpeed(std::vector<int> &piles, int h)
    {
        const int n = piles.size();
        int max = *std::max_element(piles.begin(), piles.end());

        int l = 1, r = max, res = 0;
        while (l <= r)
        {
            long long time = 0;
            int k = l + (r - l) / 2;

            for (auto pile : piles)
            {
                time += (pile + k - 1) / k;
            }

            if (time <= h)
            {
                res = k;
                r = k - 1;
            }
            else
            {
                l = k + 1;
            }
        }

        return res;
    }
};

int main()
{
    return 0;
}