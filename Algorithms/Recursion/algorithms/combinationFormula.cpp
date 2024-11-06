#include <iostream>
#include <vector>

using namespace std;

// Combination Formula

// C(n, r) = n! / [r! (n - r)!]
// n = total item count
// r = choose item count

// (3, 2)

// 3!
// ---------
// 2! * 1!

int combination(int n, int r, vector<int> &factArr)
{
    // foo

    return 1;
}

int combinationHelper(int n, int r)
{
    vector<int> factArr(n, -1);
    factArr[0] = 1;

    return combination(n, r, factArr);
}

int main()
{
    cout << "combination: " << combinationHelper(3, 2) << endl; // 2

    return 0;
}