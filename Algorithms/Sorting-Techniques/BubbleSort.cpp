#include <iostream>

// BUBBLE SORT
// Time Average & Worst: O(n^2) Time Best: O(n) || Space: O(1)

void bubbleSort(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize - 1; ++i)
    {
        bool swapped = false;

        for (int j = 0; j < arrSize - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
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
    // Quick Sort
    int A[] = {50, 70, 60, 40, 80, 10, 20, 30};

    int aSize = sizeof(A) / sizeof(A[0]);

    std::cout << "A: ";
    printArr(A, aSize);

    bubbleSort(A, aSize);

    std::cout << "A after Bubble Sort: ";
    printArr(A, aSize);

    return 0;
}