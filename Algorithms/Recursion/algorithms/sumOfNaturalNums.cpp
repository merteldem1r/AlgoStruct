#include <iostream>

using namespace std;

// Sum Of Natural Numbers

int sumRec(int n) // Time: O(n) | Space: O(n)
{
    if (n < 1)
    {
        return n;
    }

    return sumRec(n - 1) + n;
}

int sumRecMemo(int n, int sum = 0) // / Time: O(n) | Space: O(n)
{
    if (n < 1)
    {
        return sum;
    }

    return sumRecMemo(n - 1, sum + n);
}

int sumLoop(int n) // Time: O(n) | Space: O(1)
{
    int sum = 0;

    for (int i = 0; i <= n; ++i)
    {
        sum += i;
    }

    return sum;
}

int sumWithFormula(int n) // Time: O(1) | Space: O(1)
{
    return (n * (n + 1)) / 2;
}

int main()
{

    cout << "sumRec: " << sumRec(0) << endl;                 // 3
    cout << "sumRecMemo: " << sumRecMemo(4) << endl;         // 10
    cout << "sumLoop: " << sumLoop(5) << endl;               // 15
    cout << "sumWithFormula: " << sumWithFormula(7) << endl; // 28

    return 0;
}