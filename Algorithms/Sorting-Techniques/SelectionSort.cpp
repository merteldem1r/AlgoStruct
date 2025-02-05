#include <iostream>

// SELECTION SORT (Not Adaptive & Not Stable)
// Time: O(n^2) || Space: O(1)

void selectionSort(int A[], int arrSize)
{
    for (int i = 0; i < arrSize - 1; ++i)
    {
        int minIdx = i;

        for (int j = i + 1; j < arrSize; ++j)
        {
            if (A[j] < A[minIdx])
            {
                minIdx = j;
            }
        }

        if (minIdx != i)
        {
            std::swap(A[i], A[minIdx]);
        }
    }
}

void printArr(int arr[], int arrSize)
{
    std::cout << "{ ";
    for (int i = 0; i < arrSize; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "}" << std::endl;
}

int main()
{
    int A[] = {50, 70, 60, 40, 80, 10, 20, 30};

    int aSize = sizeof(A) / sizeof(A[0]);

    std::cout << "A: ";
    printArr(A, aSize);

    selectionSort(A, aSize);

    std::cout << "A after Selection Sort: ";
    printArr(A, aSize);

    return 0;
}