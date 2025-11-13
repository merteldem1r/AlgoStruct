#include <iostream>
#include <unordered_set>

// LeetCode: 36. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/description/

/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

1. Each row must contain the digits 1-9 without repetition.
2. Each column must contain the digits 1-9 without repetition.
3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

Example 1:
    Input: board =
        [["5","3",".",".","7",".",".",".","."]
        ,["6",".",".","1","9","5",".",".","."]
        ,[".","9","8",".",".",".",".","6","."]
        ,["8",".",".",".","6",".",".",".","3"]
        ,["4",".",".","8",".","3",".",".","1"]
        ,["7",".",".",".","2",".",".",".","6"]
        ,[".","6",".",".",".",".","2","8","."]
        ,[".",".",".","4","1","9",".",".","5"]
        ,[".",".",".",".","8",".",".","7","9"]]
    Output: true
*/

class Solution // Time: O(81) = O(1)  Space: O(243) = O(1)
{
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        std::unordered_set<int> rowSet[9];
        std::unordered_set<int> colSet[9];
        std::unordered_set<int> boxSet[9];

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                auto c = board[i][j];
                int boxIndex = (i / 3) * 3 + (j / 3);

                if (c == '.')
                {
                    continue;
                }

                if (rowSet[i].count(c) || colSet[j].count(c) || boxSet[boxIndex].count(c))
                {
                    return false;
                }

                rowSet[i].insert(c);
                colSet[j].insert(c);
                boxSet[boxIndex].insert(c);
            }
        }

        return true;
    }
};

int main()
{
    return 0;
}