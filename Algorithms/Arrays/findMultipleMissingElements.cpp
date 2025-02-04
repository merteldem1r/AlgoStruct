#include <iostream>

// Find mutiple missing elements in array

void printArr(int arr[], int arrLen)
{
    std::cout << "[ ";
    for (int i = 0; i < arrLen; ++i)
        std::cout << arr[i] << " ";
    std::cout << "]";
}

int main()
{
    return 0;
}