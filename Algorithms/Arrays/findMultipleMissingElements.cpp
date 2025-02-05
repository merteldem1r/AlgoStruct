#include <iostream>
#include <vector>
#include <unordered_set>

// Find mutiple missing elements in array

template <typename T>
void printArr(const T &container, int arrLen)
{
    std::cout << "{ ";
    for (int i = 0; i < arrLen; ++i)
        std::cout << container[i] << " ";
    std::cout << "}" << std::endl;
}

// 1) Find missing elements on sorted Array
// [6,7,8,9,11,12,15,16,17,18,19]
// Time: O(n^2) Space: O(1)
std::vector<int> findMultipleSorted(const int A[], int arrLen)
{
    std::vector<int> missing;

    int diff = A[0];

    for (int i = 0; i < arrLen; ++i)
    {
        if (A[i] - i != diff)
        {
            while (diff < A[i] - i)
            {
                missing.push_back(diff + i);
                ++diff;
            }
        }
    }

    return missing;
}

// 2) Find missing elements on unsorted array
// Time: O(n) Space: O(n)
std::vector<int> findMultipleUnsorted(const int A[], int arrLen)
{
    std::vector<int> missing;
    int maxValue = A[0];
    int minValue = A[0];

    for (int i = 1; i < arrLen; ++i)
    {
        if (A[i] > maxValue)
            maxValue = A[i];
        if (A[i] < minValue)
            minValue = A[i];
    }

    std::unordered_set<int> elemSet(A, A + arrLen);

    for (int i = minValue; i <= maxValue; ++i)
    {
        if (elemSet.find(i) == elemSet.end())
            missing.push_back(i);
    }

    return missing;
}

int main()
{
    // 1) Find Missing Elements on Sorted Array
    const int A[] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19}; // missing: 10, 13, 14
    const int aLen = sizeof(A) / sizeof(A[0]);

    const std::vector<int> missingA = findMultipleSorted(A, aLen);

    std::cout << "Missing A: ";
    printArr(missingA, missingA.size());

    // 2) Find Missing Elementes on Unsorted Array
    const int B[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10}; // missing: 5, 8
    const int bLen = sizeof(B) / sizeof(B[0]);

    const std::vector<int> missingB = findMultipleUnsorted(B, bLen);
    std::cout << "Missing B: ";
    printArr(missingB, missingB.size());

    return 0;
}