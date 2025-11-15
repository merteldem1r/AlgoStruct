#include <iostream>

// Merge two sorted arrays into single one.

int *merge(int A[], int B[], int aSize, int bSize) // Time: O(n) Space O(m + n)
{
    int *temp = new int[aSize + bSize];
    int i = 0, j = 0, k = 0;

    while (i < aSize && j < bSize)
    {
        if (A[i] < B[j])
            temp[k++] = A[i++];
        else
            temp[k++] = B[j++];
    }

    for (; i < aSize; ++i)
        temp[k++] = A[i];

    for (; j < bSize; ++j)
        temp[k++] = B[j];

    return temp;
}

void printArr(int arr[], int n)
{
    std::cout << "\t[ ";

    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";

    std::cout << "}" << std::endl;
}

int main()
{
    int A[] = {1, 2, 4, 7, 11};
    int B[] = {4, 5, 6, 7, 8, 15, 22};

    std::cout << "A: ";
    printArr(A, 5);

    std::cout << "B: ";
    printArr(B, 7);

    const auto res = merge(A, B, 5, 7);

    std::cout << "After merge: "; // [ 1 2 4 4 5 6 7 7 8 11 15 22 ]
    printArr(res, 12);

    delete[] res;

    return 0;
}