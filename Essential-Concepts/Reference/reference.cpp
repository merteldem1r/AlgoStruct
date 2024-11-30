#include <iostream>
#include <vector>
#include <string>

// Function having parameters as references
void swap(int &first, int &second)
{
    int temp = first;
    first = second;
    second = temp;
}

int main()
{
    // both a and res variables occupies same memory and address (reference does not consume memory)
    int a = 10;
    int &ref = a;

    std::cout << "a: " << a << std::endl; // 10

    ref = 20;

    std::cout << "a: " << a << std::endl; // 20

    std::cout << "&a: " << &a << std::endl;     // 0xfcb55ff804
    std::cout << "&ref: " << &ref << std::endl; // 0xfcb55ff804

    int x = 1;
    int y = 2;

    std::swap(x, y);

    std::cout << "x: " << x << " y: " << y << std::endl; // x: 2 y: 1

    // Using reference in for each loop to modify all elements

    std::vector<int> nums = {10, 20, 30, 40};

    for (auto &num : nums)
    {
        num += 5;
    }

    for (int num : nums)
    {
        std::cout << "num: " << num << std::endl;
    }

    std::vector<std::string> vect = {"hello world", "cpp essentials", "references examples"};

    // We avoid copy of the whole std::string
    for (const auto &x : vect)
    {
        std::cout << x << std::endl;
    }

    return 0;
}