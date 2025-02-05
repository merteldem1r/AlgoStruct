#include <iostream>
#include <vector>
#include <unordered_set>

// Find duplicate elements

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

// 1) Find duplicate elements in SORTED array
// Time: O(n) Space: O(n)
std::vector<int> findDubplicatesSorted(const int A[], int arrLen)
{
    std::vector<int> duplicates;
    int lastDuplicate;

    for (int i = 0; i < arrLen; ++i)
    {
        if (A[i] == A[i + 1] && A[i] != lastDuplicate)
        {
            duplicates.push_back(A[i]);
            lastDuplicate = A[i];
        }
    }

    return duplicates;
}

// 2) Find elements in UNSORTED array
// Time: O(n) Space: O(n)
std::vector<int> findDuplicatesUnsorted(const int A[], int arrLen)
{
    std::vector<int> freq(arrLen + 1, 0);
    std::vector<int> duplicates;

    for (int i = 0; i < arrLen; ++i)
    {
        if (freq[A[i]] == 1)
            duplicates.push_back(A[i]);

        ++freq[A[i]];
    }

    return duplicates;
}

int main()
{
    // 1) Find duplicate elements in SORTED array
    const int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20}; // duplicates: 8, 15
    const int aLen = sizeof(A) / sizeof(A[0]);

    const std::vector<int> missingA = findDubplicatesSorted(A, aLen);

    std::cout << "Duplicates A: ";
    printArr(missingA, missingA.size());

    // 2) Find elements in UNSORTED array

    const int B[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7}; // duplicates: 6, 8
    const int bLen = sizeof(B) / sizeof(B[0]);

    const std::vector<int> missingB = findDuplicatesUnsorted(B, bLen);

    std::cout << "Duplicates B: ";
    printArr(missingB, missingB.size());

    return 0;
}