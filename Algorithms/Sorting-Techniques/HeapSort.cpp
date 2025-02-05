#include <iostream>

// Heap Sort (Not Adaptive & Stable)
// Time Average & Best & Worst: O(n logn) || Space: O(1)

void heapify(int A[], int arrSize, int i);

void HeapSort(int A[], int arrSize)
{
    for (int i = arrSize / 2 - 1; i >= 0; --i)
        heapify(A, arrSize, i);

    for (int i = arrSize - 1; i > 0; --i)
    {
        std::swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

void heapify(int A[], int arrSize, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    int largest = i;

    if (l < arrSize && A[largest] < A[l])
        largest = l;

    if (r < arrSize && A[largest] < A[r])
        largest = r;

    if (largest != i)
    {
        std::swap(A[i], A[largest]);
        heapify(A, arrSize, largest);
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
    int A[] = {5, 2, 7, 45, 3, 79, 4, 23, 45, 23, 17, 4, 56, 120};

    int aSize = sizeof(A) / sizeof(A[0]);

    std::cout << "A: ";
    printArr(A, aSize);

    HeapSort(A, aSize);

    std::cout << "A after Heap Sort: ";
    printArr(A, aSize);
    return 0;
}