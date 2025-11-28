#include <iostream>

// LeetCode: 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/description/

/*
Given a string s, return the longest palindromic substring in s.

Example 1:
    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.

Example 2:
    Input: s = "cbbd"
    Output: "bb"
*/

class SolutionBruteForce // Time: O(n^3) Space: O(1)
{
public:
    bool isPalindrome(std::string &str, int l, int r)
    {
        while (l >= 0 && r < str.length() && l < r)
        {
            if (str[l] != str[r])
            {
                return false;
            }
            ++l, --r;
        }

        return true;
    }

    std::string longestPalindrome(std::string s)
    {
        int n = s.length();

        if (n <= 1)
        {
            return s;
        }

        int maxLen = 1;
        int start = 0;
        std::string res = s.substr(0, maxLen);
        for (int l = 0; l < n; ++l)
        {
            for (int r = 0; r < n; ++r)
            {
                if (isPalindrome(s, l, r) && r - l + 1 > maxLen)
                {
                    start = l;
                    maxLen = r - l + 1;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

class SolutionTwoPointers // Time: O(n^2) Space: O(1)
{
public:
    std::string longestPalindrome(std::string s)
    {
        int n = s.length();

        if (n <= 1)
        {
            return s;
        }

        int start = 0, len = 1;
        int l = 0, r = 0;

        for (int i = 0; i < n; ++i)
        {
            // for odd length palindromes
            l = i, r = i;
            while (l >= 0 && r <= n && s[l] == s[r])
            {
                if (r - l + 1 > len)
                {
                    len = r - l + 1;
                    start = l;
                }
                --l;
                ++r;
            }

            // for even length palindromes
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (r - l + 1 > len)
                {
                    start = l;
                    len = r - l + 1;
                }

                ++r;
                --l;
            }
        }

        return s.substr(start, len);
    }
};

// Taken from: https://neetcode.io/solutions/longest-palindromic-substring
class SolutionManacher // Time: O(n) Space: O(n)
{
public:
    std::vector<int> manacher(std::string &s)
    {
        std::string t = "#" + std::string(1, s[0]);
        for (int i = 1; i < s.size(); ++i)
            t += "#" + std::string(1, s[i]);
        t += "#";
        int n = t.size();
        std::vector<int> p(n, 0);
        int l = 0, r = 0;
        for (int i = 0; i < n; i++)
        {
            p[i] = (i < r) ? std::min(r - i, p[l + (r - i)]) : 0;
            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 &&
                   t[i + p[i] + 1] == t[i - p[i] - 1])
                p[i]++;
            if (i + p[i] > r)
                l = i - p[i], r = i + p[i];
        }
        return p;
    }

    std::string longestPalindrome(std::string s)
    {
        std::vector<int> p = manacher(s);
        int resLen = 0, center_idx = 0;
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] > resLen)
            {
                resLen = p[i];
                center_idx = i;
            }
        }
        int resIdx = (center_idx - resLen) / 2;
        return s.substr(resIdx, resLen);
    }
};

int main()
{
    return 0;
}