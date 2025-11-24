#include <iostream>

// LeetCode: 74. Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/description/

/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:
    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true

Example 2:
    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    Output: false
*/

class SolutionBruteForce // Time O(m * n) Space: O(1)
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        for (int r = 0; r < matrix.size(); r++)
        {
            for (int c = 0; c < matrix[r].size(); c++)
            {
                if (matrix[r][c] == target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

class SolutionBinarySearch1 // Time: O(log(m * n)) Space: O(1)
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        const int rowSize = matrix.size(), colSize = matrix[0].size();

        // 1. find row
        int t = 0, b = rowSize - 1, mid;
        while (t <= b)
        {
            mid = t + (b - t) / 2;

            if (matrix[mid][0] > target)
            {
                b = mid - 1;
            }
            else if (matrix[mid][colSize - 1] < target)
            {
                t = mid + 1;
            }
            else
            {
                break;
            }
        }

        // 2. find col
        int row = mid, l = 0, r = colSize - 1;
        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (matrix[row][mid] == target)
            {
                return true;
            }
            else if (matrix[row][mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return false;
    }
};

class SolutionBinarySearch2 // Time: O(log(m * n)) Space: O(1)
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        const int rowSize = matrix.size(), colSize = matrix[0].size();
        int l = 0, r = rowSize * colSize - 1, mid, val;

        while (l <= r)
        {
            mid = l + (r - l) / 2;
            val = matrix[mid / colSize][mid % colSize];

            if (val == target)
            {
                return true;
            }
            else if (val < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return false;
    }
};

class SolutionStaircaseSearch // Time: O(m + n) Space: O(1)
{
public:
    bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
    {
        const int rowSize = matrix.size(), colSize = matrix[0].size();
        int r = 0, c = colSize - 1;

        while (r < rowSize && c >= 0)
        {
            if (matrix[r][c] > target)
            {
                --c;
            }
            else if (matrix[r][c] < target)
            {
                ++r;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}