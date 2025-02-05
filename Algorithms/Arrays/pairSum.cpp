#include <iostream>
#include <vector>
#include <unordered_map>

// Find pairs in array where sum of two elements = k
// {6, 3, 8, 10, 16, 7, 5, 2, 9, 14} k = 10 should return {3, 7}   3 + 7 = 10

std::vector<int> findPairSum(const int A[], int arrLen, int k)
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
    const int A[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    const int aLen = sizeof(A) / sizeof(A[0]);

    const std::vector<int> pair = findPairSum(A, aLen, 10);
    std::cout << "Pair sum for 10: ";
    printArr(pair, pair.size());

    return 0;
}