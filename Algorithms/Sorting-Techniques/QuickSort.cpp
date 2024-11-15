#include <iostream>

using namespace std;

// QUICK SORT
// Time Average & Best: O(n logn) Time Worst: O(n^2) || Space: O(n logn)

void printArr(int arr[], int arrSize)
{
    cout << "[ ";
    for (int i = 0; i < arrSize; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int left = low + 1;
    int right = high;

    while (left <= right)
    {
        while (left <= right && A[left] <= pivot)
        {
            ++left;
        }
        while (left <= right && A[right] > pivot)
        {
            --right;
        }
        if (left < right)
        {
            swap(A[left], A[right]);
        }
    }

    swap(A[low], A[right]);
    return right;
}

void quickSort(int A[], int low, int high)
{
    if (low > high)
        return;

    auto pivot = partition(A, low, high);
    quickSort(A, low, pivot - 1);
    quickSort(A, pivot + 1, high);
}

int main()
{
    // Quick Sort
    int A[] = {50, 70, 60, 40, 80, 10, 20, 30};

    int aSize = sizeof(A) / sizeof(A[0]);

    cout << "A: ";
    printArr(A, aSize);

    quickSort(A, 0, aSize - 1);

    cout << "A after Quick Sort: ";
    printArr(A, aSize);

    return 0;
}