#include <iostream>

// Find single missing element in the sorted array

void printArr(int arr[], int n)
{
    std::cout << "\t[ ";

    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";

    std::cout << "]" << std::endl;
}

// 1) For natural numbers
// Using [n * (n + 1)] / 2 (for natural numbers 1,2,3,4,5 ...)
int findSingleMissing1(int A[], int aLen) // Time: O(n) Space: O(1)
{
    const int lastVal = A[aLen - 1];
    const int wantedSum = (lastVal * (lastVal + 1)) / 2;
    int aSum = 0;

    for (int i = 0; i < aLen; ++i)
        aSum += A[i];

    return wantedSum - aSum;
}

// 2) Sequence starts from any point (6,7,8,9 ...)
int findSingleMissing2(int A[], int aLen)
{
    const int low = A[0];

    for (int i = 0; i < aLen; ++i)
    {
        if (A[i] - i != low)
            return i + low;
    }

    return -1;
}

int main()
{
    // 1) For natural numbers
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12}; // 11 missing
    int aLen = sizeof(A) / sizeof(A[0]);

    std::cout << "A findSingleMissing1(): " << findSingleMissing1(A, aLen) << std::endl;

    // 2) For any sequence
    int B[] = {6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17}; // 12 missing
    int bLen = sizeof(B) / sizeof(B[0]);

    std::cout << "B findSingleMissing2(): " << findSingleMissing2(B, bLen) << std::endl;

    return 0;
}