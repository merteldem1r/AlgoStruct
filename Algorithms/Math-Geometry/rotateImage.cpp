#include <iostream>

// LeetCode: 48. Rotate Image
// https://leetcode.com/problems/rotate-image/description/

/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:
    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
    Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
    Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/

class SolutionBruteForce // Time: O(n^2) Space: O(n^2)
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        // Brute Force
        const int n = matrix.size();
        std::vector<std::vector<int>> res(n, std::vector<int>(n));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                res[j][n - i - 1] = matrix[i][j];
            }
        }

        matrix = res;
    }
};

class SolutionRotationCells // Time: O(n^2) Space: O(1)
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        int l = 0, r = matrix.size() - 1;

        while (l < r)
        {
            for (int i = 0; i < r - l; ++i)
            {
                int t = l, b = r;

                int tempTL = matrix[t][l + i];

                // bl -> tl
                matrix[t][l + i] = matrix[b - i][l];

                // br -> bl
                matrix[b - i][l] = matrix[b][r - i];

                // tr -> br
                matrix[b][r - i] = matrix[t + i][r];

                // tempTL -> tr
                matrix[t + i][r] = tempTL;
            }
            ++l, --r;
        }
    }
};

class SolutionReverseAndTranspose // Time: O(n^2) Space: O(1)
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        const int n = matrix.size();
        std::reverse(matrix.begin(), matrix.end());

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main()
{
    return 0;
}