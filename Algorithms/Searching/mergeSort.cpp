#include <iostream>

using namespace std;

// MERGE SORT
// Time: O(nlogn) || Space: O(nlogn)

/*
    Example merge() functions letters:

        l        m              h
        [1, 3, 5, 7, 12, 15, 20, 21]
        i           j

*/

void merge(int A[], int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;

    int *tempArr = new int[h + 1];
    int k = l;

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            tempArr[k++] = A[i++];
        else
            tempArr[k++] = A[j++];
    }

    for (; i <= mid; ++i)
        tempArr[k++] = A[i];

    for (; j <= h; ++j)
        tempArr[k++] = A[j];

    for (i = l; i <= h; ++i)
    {
        A[i] = tempArr[i];
    }

    delete tempArr;
}

void iterativeMergeSort(int A[], int arrSize)
{
    int p, i, l, mid, h;

    for (p = 2; p <= arrSize; p *= 2)
    {
        for (i = 0; i + p - 1 < arrSize; i += p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;

            merge(A, l, mid, h);
        }
    }

    if (p > arrSize)
    {
        merge(A, 0, p - 3, arrSize - 1);
    }
}

void recursiveMergeSort(int A[], int arrSize, int l, int h)
{
    if (l >= h)
        return;

    int mid = l + (h - l) / 2;

    recursiveMergeSort(A, arrSize, l, mid);
    recursiveMergeSort(A, arrSize, mid + 1, h);
    merge(A, l, mid, h);
}

void printArr(int arr[], int arrSize)
{
    cout << "[ ";
    for (int i = 0; i < arrSize; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int main()
{
    // Iterative Merge Sort
    int A[] = {5, 2, 7, 45, 3, 79, 4, 23, 45, 23, 17, 4, 56, 120};

    int aSize = sizeof(A) / sizeof(A[0]);

    cout << "A: ";
    printArr(A, aSize);

    iterativeMergeSort(A, aSize);

    cout << "A after Iterative Merge Sort: ";
    printArr(A, aSize);

    // Recursive Merge Sort

    int B[] = {12, 0, 9, 34, 8, 65, 45, 11, 8};

    int bSize = sizeof(B) / sizeof(B[0]);

    cout << "B: ";
    printArr(B, bSize);

    recursiveMergeSort(B, bSize, 0, bSize - 1);

    cout << "B after Iterative Merge Sort: ";
    printArr(B, bSize);

    return 0;
}