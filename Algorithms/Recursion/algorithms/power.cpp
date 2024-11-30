#include <iostream>

// Power (m^n)

int powerRec(int base, int power) // Time: O(n) | Space: O(n)
{
    if (power == 0)
    {
        return 1;
    }

    return powerRec(base, power - 1) * base;
}

int powerLoop(int base, int power) // Time: O(n) | Space: O(1)
{
    int res = 1;

    for (int i = 0; i < power; ++i)
    {
        res *= base;
    }

    return res;
}

// FASTER RESURCIVE POWER FUNCTION

// 2^8 = (2^2)^3 power reduced by half, we can make that even faster than powerRec()
// which happens when power is EVEN

int powerRecFast(int base, int power) // Time: O(logN) | Space: O(logN)
{
    if (power == 0)
        return 1;

    if (power % 2 == 0)
    {
        return powerRecFast(base * base, power / 2);
    }

    return powerRecFast(base, power - 1) * base;
}

int main()
{

    std::cout << "powerRec: " << powerRec(3, 4) << std::endl;   // 81
    std::cout << "powerLoop: " << powerLoop(2, 0) << std::endl; // 0

    // Efficient
    std::cout << "powerRecFast: " << powerRecFast(2, 8) << std::endl; // 256

    return 0;
}