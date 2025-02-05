#include <iostream>

// Find minimum and maximum values in given array in a single pass

// Time: O(n) Space: O(1)
std::pair<int, int> findMaxMin(const int A[], int arrLen)
{
    std::pair<int, int> maxMin;

    int min = A[0], max = A[0];

    for (int i = 1; i < arrLen; ++i)
    {
        if (A[i] < min)
            min = A[i];
        else if (A[i] > max)
            max = A[i];
    }

    return {max, min};
}

template <typename T>
void prinArr(const T &container, int containerLen)
{
    std::cout << "[ ";
    for (int i = 0; i < containerLen; ++i)
        std::cout << container[i] << " ";
    std::cout << "]";
}

int main()
{
    const int A[] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};
    const int aLen = sizeof(A) / sizeof(A[0]);

    const auto [max, min] = findMaxMin(A, aLen);

    std::cout << "Max: " << max << std::endl; // 10
    std::cout << "Min: " << min << std::endl; // -1

    return 0;
}