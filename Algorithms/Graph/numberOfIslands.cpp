#include <iostream>

// LeetCode: 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/description/

/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
    Input: grid = [
    ["1","1","1","1","0"],
    ["1","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
    ]
    Output: 1

Example 2:
    Input: grid = [
    ["1","1","0","0","0"],
    ["1","1","0","0","0"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
    ]
    Output: 3

*/

// Depth First Search (DFS) Solution
class SolutionDFS // Time: O(m * n) || Space: O(m * n)
{
private:
    const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    void dfsUtil(std::vector<std::vector<char>> &grid, int r, int c)
    {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0')
        {
            return;
        }

        grid[r][c] = '0';
        for (int i = 0; i < 4; ++i)
        {
            dfsUtil(grid, r + directions[i][0], c + directions[i][1]);
        }
    }

    int numIslands(std::vector<std::vector<char>> &grid)
    {
        const int rowCount = grid.size(), colCount = grid[0].size();
        int res = 0;

        for (int i = 0; i < rowCount; ++i)
        {
            for (int j = 0; j < colCount; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++res;
                    dfsUtil(grid, i, j);
                }
            }
        }

        return res;
    }
};

// Breadth First Search (BFS) Solution
class SolutionBFS // Time: O(m * n) || Space: O(m * n)
{
private:
    const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    void bfsUtil(std::vector<std::vector<char>> &grid, int r, int c)
    {
        std::queue<std::pair<int, int>> q;

        q.push({r, c});
        grid[r][c] = '0';

        while (!q.empty())
        {
            auto [fr, fc] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                const int nr = fr + directions[i][0];
                const int nc = fc + directions[i][1];
                if (nr < grid.size() && nc < grid[0].size() && nr >= 0 &&
                    nc >= 0 && grid[nr][nc] == '1')
                {
                    grid[nr][nc] = '0';
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(std::vector<std::vector<char>> &grid)
    {
        const int rowCount = grid.size(), colCount = grid[0].size();
        int res = 0;

        for (int i = 0; i < rowCount; ++i)
        {
            for (int j = 0; j < colCount; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++res;
                    bfsUtil(grid, i, j);
                }
            }
        }

        return res;
    }
};

int main()
{
    return 0;
}