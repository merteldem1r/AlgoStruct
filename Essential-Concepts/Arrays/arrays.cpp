#include <iostream>

int main()
{
    int A[5];
    A[0] = 4;
    A[1] = 5;

    int B[] = {1, 2, 3};

    std::cout << "sizeof(A): " << sizeof(A) << std::endl;           // 20 bytes
    std::cout << "sizeof(B): " << sizeof(B) << std::endl;           // 12 bytes
    std::cout << "size: " << sizeof(B) / sizeof(B[0]) << std::endl; // 3

    for (auto num : B)
    {
        std::cout << "num: " << num << std::endl;
    }

    return 0;
}