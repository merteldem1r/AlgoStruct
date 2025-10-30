#include <iostream>

class Solution
{
public:
    std::string multiply(std::string num1, std::string num2) // Time: O(m * n) Space: O(m + n)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }

        std::vector<int> res(num1.length() + num2.length(), 0);

        for (int i = num1.length() - 1; i >= 0; --i)
        {
            for (int j = num2.length() - 1; j >= 0; --j)
            {
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
            }
        }

        std::string ans = "";
        int start = 0;
        while (res[start] == 0)
            ++start;
        for (int i = start; i < res.size(); ++i)
        {
            const char c = res[i] + '0';
            ans.push_back(c);
        }

        return ans;
    }
};

int main()
{
    return 0;
}