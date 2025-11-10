#include <iostream>

// LeetCode: 322. Coin Change
// https://leetcode.com/problems/coin-change/description/

/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:
    Input: coins = [1,2,5], amount = 11
    Output: 3
    Explanation: 11 = 5 + 5 + 1

Example 2:
    Input: coins = [2], amount = 3
    Output: -1

Example 3:
    Input: coins = [1], amount = 0
    Output: 0
*/

// THIS Solution WON'T WORK ON LEETCODE due to Time Limit Exceeded
class SolutionRecursion // Time: O(n^t) Space: O(t)
{
public:
    int dfs(std::vector<int> &coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }

        int res = INT_MAX;

        for (auto &coin : coins)
        {
            if (amount - coin >= 0)
            {
                int tempRes = dfs(coins, amount - coin);
                if (tempRes != INT_MAX)
                {
                    res = std::min(res, 1 + dfs(coins, amount - coin));
                }
            }
        }

        return res;
    }

    int coinChange(std::vector<int> &coins, int amount)
    {
        int minCoins = dfs(coins, amount);
        return minCoins == INT_MAX ? -1 : minCoins;
    }
};

class SolutionDynamicProgramming
{
public:
    std::unordered_map<int, int> memo;

    int dfs(std::vector<int> &coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }

        if (memo.count(amount) > 0)
        {
            return memo[amount];
        }

        int res = INT_MAX;

        for (auto &coin : coins)
        {
            if (amount - coin >= 0)
            {
                int tempRes = dfs(coins, amount - coin);

                if (tempRes != INT_MAX)
                {
                    res = std::min(res, 1 + dfs(coins, amount - coin));
                }
            }
        }

        memo[amount] = res;
        return res;
    }

    int coinChange(std::vector<int> &coins, int amount)
    {
        int minCoins = dfs(coins, amount);
        return minCoins == INT_MAX ? -1 : minCoins;
    }
};

int main()
{

    return 0;
}