#include <iostream>

// LeetCode: 695. Max Area of Island
// https://leetcode.com/problems/max-area-of-island/description/

/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

Example 1:
    Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
    Output: 6
    Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:
    Input: grid = [[0,0,0,0,0,0,0,0]]
    Output: 0
*/

class SolutionBFS // Time: O(m * n) Space: O(m * n)
{
private:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    void bfs(std::vector<std::vector<int>> &grid, int r, int c,
             int &temp)
    {
        std::queue<std::pair<int, int>> q;

        grid[r][c] = 0;
        q.emplace(r, c);

        while (!q.empty())
        {
            auto [fr, fc] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                const int nr = fr + directions[i][0];
                const int nc = fc + directions[i][1];

                if (nr >= 0 && nc >= 0 && nr < grid.size() &&
                    nc < grid[0].size() && grid[nr][nc] == 1)
                {
                    ++temp;
                    grid[nr][nc] = 0;
                    q.emplace(nr, nc);
                }
            }
        }
    }

    int maxAreaOfIsland(std::vector<std::vector<int>> &grid)
    {
        int maxArea = 0, tempMax = 0;
        const int rowCount = grid.size(), colCount = grid[0].size();

        for (int i = 0; i < rowCount; ++i)
        {
            for (int j = 0; j < colCount; ++j)
            {
                if (grid[i][j] == 1)
                {
                    tempMax = 1;
                    bfs(grid, i, j, tempMax);
                    maxArea = std::max(maxArea, tempMax);
                }
                tempMax = 0;
            }
        }

        return maxArea;
    }
};

int main()
{
    return 0;
}