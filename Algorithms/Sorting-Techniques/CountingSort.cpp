#include <iostream>

// COUNTING SORT (Non-Comparative & Stable)
// Time: O(n + k) || Space: O(n + k)
// where n = number of elements, k = range of input (max value)

// Counting Sort is a non-comparison-based sorting algorithm. It is particularly efficient when the range of input values is small compared to the number of elements to be sorted. The basic idea behind Counting Sort is to count the frequency of each distinct element in the input array and use that information to place the elements in their correct sorted positions.

// Link to follow the topic: https://www.geeksforgeeks.org/dsa/counting-sort/

// 1. Version: STABLE
std::vector<int> CountingSort(std::vector<int> &arr)
{
    int maxNum = 0;
    // Find the maximum value in the array
    for (auto &num : arr)
    {
        if (num > maxNum)
            maxNum = num;
    }

    // To store frequency of each number
    std::vector<int> countArr(maxNum + 1, 0);
    // count how many times each number appears
    for (int i = 0; i < arr.size(); ++i)
    {
        ++countArr[arr[i]];
    }

    // Convert count array to cumulative count array
    // This shows the position each number should go to
    for (int i = 1; i < countArr.size(); ++i)
    {
        countArr[i] += countArr[i - 1];
    }

    std::vector<int> sorted(arr.size());

    // Place each element in its correct sorted position (stable)
    // Process from end to start to keep original order for same numbers
    for (int i = arr.size() - 1; i >= 0; --i)
    {
        sorted[countArr[arr[i]] - 1] = arr[i];
        --countArr[arr[i]];
    }

    return sorted;
}

// 2. Version NOT STABLE but Simpler
std::vector<int> CountingSort2(std::vector<int> &arr)
{
    int maxNum = 0;
    for (auto &num : arr)
    {
        if (num > maxNum)
            maxNum = num;
    }

    std::vector<int> countArr(maxNum + 1, 0);

    for (int i = 0; i < arr.size(); ++i)
    {
        ++countArr[arr[i]];
    }

    std::vector<int> sorted;
    sorted.reserve(arr.size());

    // For each number, push it into sorted array as many times as it appears
    // This does not preserve original order for same numbers
    for (int i = 0; i < countArr.size(); ++i)
    {
        while (countArr[i] != 0)
        {
            sorted.emplace_back(i);
            --countArr[i];
        }
    }

    return sorted;
}

void printArr(std::vector<int> &arr)
{
    for (auto &num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 2, 1, 5, 4, 3, 5};
    printArr(arr);

    std::vector<int> sortedArr = CountingSort(arr); // (STABLE)
    printArr(sortedArr);                            // 1 1 2 2 3 3 4 5 5

    std::vector<int> sortedArr2 = CountingSort2(arr); // (NOT STABLE)
    printArr(sortedArr2);                             // 1 1 2 2 3 3 4 5 5

    return 0;
}