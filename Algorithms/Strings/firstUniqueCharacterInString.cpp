#include <iostream>

// LeetCode: 387. First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/description/

/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
    Input: s = "leetcode"

    Output: 0

Explanation:
    The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:
    Input: s = "loveleetcode"

    Output: 2

Example 3:
    Input: s = "aabb"

    Output: -1


*/

class Solution // Time: O(n) Space: O(n)
{
public:
    int firstUniqChar(std::string s)
    {
        std::unordered_map<char, int> map;

        for (auto &c : s)
        {
            ++map[c];
        }

        for (int i = 0; i < s.length(); ++i)
        {
            auto c = s[i];
            if (map[c] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    return 0;
}