#include <iostream>

class Solution1 // Time: O(nlogn) Space: (n)
{
public:
    int bitCount(int num)
    {
        int count = 0;

        while (num != 0)
        {
            count += num & 1;
            num >>= 1;
        }

        return count;
    }

    std::vector<int> countBits(int n)
    {
        std::vector<int> ans(n + 1);

        for (int i = 0; i < n + 1; ++i)
        {
            const int count = bitCount(i);
            ans.emplace_back(count);
        }

        return ans;
    }
};

class Solution2
{
public:
};

int main()
{
    return 0;
}