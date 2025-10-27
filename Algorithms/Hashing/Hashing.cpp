#include <iostream>

// Hashing
// Author: Mert Eldemir

/*
In hashing there is a hash function that maps keys to some values. But these hashing functions may lead to a collision that is two or more keys are mapped to same value. Chain hashing avoids collision. The idea is to make each cell of hash table point to a linked list of records that have same hash function value.

    Loading Factor in Hash Table:

        Formula:  lambda = n / size
            * n: number of keys
            * size: size of the table

    Analysis of Hash Table based on loading factor.
*/

int main()
{
    // ********************* Simple Hashing (One-to-One Mapping) *********************
    int arr[] = {8, 3, 6, 10, 15, 18, 4};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    // find max value from the arr
    int max = INT_MIN;
    for (int i = 0; i < arrSize; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // allocate max + 1 size array
    int *hashedArr = new int[max + 1]();

    // now each value stays on the same number index, which allows fast access with O(1) time complexity
    for (int i = 0; i < arrSize; ++i)
    {
        hashedArr[arr[i]] = arr[i];
    }

    std::cout << "[ ";
    for (int i = 0; i < max + 1; ++i)
    {
        std::cout << hashedArr[i] << " ";
    }
    std::cout << "]"; // [ 0 0 0 3 4 0 6 0 8 0 10 0 0 0 0 15 0 0 18 ]

    // DRAWBACKS: Allocated array might be much longer if the range of the values is big, which cause bad effect on space complexity

    delete[] hashedArr;

    // ********************* Hashing using Mod operator (Many-to-One Mapping) *********************
    int arr2[] = {8, 3, 6, 10, 15, 18, 4};
    int arrSize2 = sizeof(arr2) / sizeof(arr2[0]);

    int hashedArr2[10] = {};
    for (int i = 0; i < arrSize2; ++i)
    {
        hashedArr2[arr2[i] % 10] = arr2[i];
    }

    // DRAWBACKS: Same remainder may cause to get into the same index, that's called Hash Collision

    return 0;
}