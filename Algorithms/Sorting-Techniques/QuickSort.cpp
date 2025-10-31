#include <iostream>

// QUICK SORT (Not Adaptive & Not Stable)
// Time Average & Best: O(n logn) Time Worst: O(n^2) || Space: O(n logn)

void printArr(int arr[], int arrSize)
{
    std::cout << "{ ";
    for (int i = 0; i < arrSize; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "}" << std::endl;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j <= high - 1; ++j)
    {
        if (arr[j] < pivot)
        {
            std::swap(arr[i], arr[j]);
            ++i;
        }
    }

    std::swap(arr[i], arr[high]);
    return i;
}

void quickSort(int A[], int low, int high)
{
    if (low >= high)
        return;

    int pi = partition(A, low, high);
    quickSort(A, low, pi - 1);
    quickSort(A, pi + 1, high);
}

int main()
{
    // Quick Sort
    int A[] = {50, 70, 60, 40, 80, 10, 20, 30};

    int aSize = sizeof(A) / sizeof(A[0]);

    std::cout << "A: ";
    printArr(A, aSize);

    quickSort(A, 0, aSize - 1);

    std::cout << "A after Quick Sort: ";
    printArr(A, aSize);

    return 0;
}