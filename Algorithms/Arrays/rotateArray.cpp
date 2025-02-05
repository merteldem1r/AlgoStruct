#include <iostream>

// Rotate the array to the right by k steps.

void rotate(int arr[], int arrLen, int k) // Time: O(n) Space: O(n)
{

    if (k < 0)
    {
        printf("\t\t** Error: Invalid negative step for rotate\n");
        return;
    }

    if (arrLen == 1 || k == 0 || k % arrLen == 0)
        return;

    if (arrLen == 2)
    {
        if (k % 2 != 0)
            std::swap(arr[0], arr[1]);
        return;
    }

    int *temp = new int[arrLen];

    for (int i = 0; i < arrLen; ++i)
        temp[(i + k) % arrLen] = arr[i];

    for (int i = 0; i < arrLen; ++i)
        arr[i] = temp[i];

    delete[] temp;
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
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    int arrLen = sizeof(A) / sizeof(A[0]);
    int k = 3;

    std::cout << "A before rotate: ";
    printArr(A, arrLen);

    rotate(A, arrLen, k);

    printf("A after %d step rotate: ", k);
    printArr(A, arrLen);

    return 0;
}