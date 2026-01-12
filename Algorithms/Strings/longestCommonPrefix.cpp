#include <iostream>

// LeetCode: 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
    Input: strs = ["flower","flow","flight"]
    Output: "fl"

Example 2:
    Input: strs = ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.
*/

class Solution // Time: O(n*m) | Space: O(1)
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        std::string res;
        int charIndx = 0;

        while (charIndx < strs[0].length())
        {
            for (int i = 1; i < strs.size(); ++i)
            {
                if (strs[0][charIndx] != strs[i][charIndx])
                {
                    return res;
                }
            }

            res += strs[0][charIndx];
            ++charIndx;
        }

        return res;
    }
};

int main()
{
    return 0;
}