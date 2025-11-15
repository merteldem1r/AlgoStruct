#include <iostream>
#include <vector>
#include <unordered_map>

// Find pairs in array where sum of two elements = k
// { 6, 3, 8, 10, 16, 7, 5, 2, 9, 14 } k = 10 should return {3, 7}   3 + 7 = 10

// 1) UNSORTED ARRAY
// Time: O(n) Space: O(n)
std::vector<int> findPairSumUnsorted(const int A[], int arrLen, int k)
{
    std::unordered_map<int, int> map;

    for (int i = 0; i < arrLen; ++i)
    {
        if (map.count(A[i]) > 0)
            return {map[A[i]], A[i]};

        map[k - A[i]] = A[i];
    }

    return {};
}

// 2) SORTED ARRAY
// Time: O(n) Space: O(1)
std::vector<int> findPairSumSorted(const int A[], int arrLen, int k)
{
    int l = 0, r = arrLen - 1;

    while (l < r)
    {
        if (A[l] + A[r] == k)
            return {A[l], A[r]};
        else if (A[l] + A[r] > k)
            --r;
        else
            ++l;
    }

    return {};
}

template <typename T>
void printArr(const T &container, int containerLen)
{
    std::cout << "{ ";
    for (int i = 0; i < containerLen; ++i)
    {
        std::cout << container[i] << " ";
    }
    std::cout << "}" << std::endl;
}

int main()
{
    // 1) Unsorted Array
    const int A[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    const int aLen = sizeof(A) / sizeof(A[0]);

    const std::vector<int> pairUnsortedArray = findPairSumUnsorted(A, aLen, 10); // {3, 7}
    std::cout << "Pair sum for 10 (Unsorted): ";
    printArr(pairUnsortedArray, pairUnsortedArray.size());

    // 2) Sorted Array
    const int B[] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    const int bLen = sizeof(B) / sizeof(B[0]);

    const std::vector<int> pairSortedArray = findPairSumSorted(B, bLen, 10); // {1, 9}
    std::cout << "Pair sum for 10 (Sorted): ";
    printArr(pairSortedArray, pairSortedArray.size());

    return 0;
}