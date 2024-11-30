#include <iostream>

// INSERTION SORT (Adaptive & Stable)
// Time Average & Worst: O(n^2) Time Best: O(n) || Space: O(1)

void insertionSort(int arr[], int arrSize)
{
    for (int i = 1; i < arrSize; ++i)
    {
        const int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

void printArr(int arr[], int arrSize)
{
    std::cout << "[ ";
    for (int i = 0; i < arrSize; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    // Insertion Sort
    int A[] = {50, 70, 60, 40, 80, 10, 20, 30};

    int aSize = sizeof(A) / sizeof(A[0]);

    std::cout << "A: ";
    printArr(A, aSize);

    insertionSort(A, aSize);

    std::cout << "A after Insertion Sort: ";
    printArr(A, aSize);

    return 0;
}