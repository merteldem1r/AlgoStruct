#include <iostream>

// LeetCode: 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/

/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Example 1:
    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:
    * There is no string in strs that can be rearranged to form "bat".
    * The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
    * The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:
    Input: strs = [""]
    Output: [[""]]

Example 3:
    Input: strs = ["a"]
    Output: [["a"]]
*/

class Solution // Time: O(m * logN) => m: number of strings n: length of longest string | Space: O(n)
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> anagramMap;
        std::vector<std::vector<std::string>> res;

        for (auto &str : strs)
        {
            auto sortedStr = str;
            std::sort(sortedStr.begin(), sortedStr.end());
            anagramMap[sortedStr].emplace_back(str);
        }

        for (auto &entity : anagramMap)
        {
            res.emplace_back(entity.second);
        }

        return res;
    }
};

class SolutionHashMap // Time: O(m * n) => m: number of strings n: length of longest string | Space: O(m)
{
public:
    std::vector<std::vector<std::string>>
    groupAnagrams(std::vector<std::string> &strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> anagramMap;
        std::vector<std::vector<std::string>> res;

        for (const auto &str : strs)
        {
            int freq[26] = {0};

            for (char c : str)
            {
                freq[c - 'a']++;
            }

            std::string key = "";
            for (int i = 0; i < 26; ++i)
            {
                key += std::to_string(freq[i]) + "/";
            }

            anagramMap[key].emplace_back(str);
        }

        for (const auto &entity : anagramMap)
        {
            res.emplace_back(entity.second);
        }

        return res;
    }
};

int main()
{
    return 0;
}