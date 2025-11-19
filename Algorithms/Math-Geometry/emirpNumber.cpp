#include <iostream>

/*
Emirp Number

An emirp number is a special type of prime number.
It has following conditions:
    * The number itself must be prime.
    * When the digits of the number are reversed, the result must also be prime.
    * The reversed number must be different from the original (so palindromic primes are excluded).

Examples

13 -> 31
13 is prime
31 is prime
    So 13 is an emirp.

17 -> 71
    Both prime - emirp.

101 -> 101
    Prime, but reversed form is the same
    NOT an emirp (because it's palindromic)
*/

bool isPrime(int num)
{
    if (num < 2)
    {
        return false;
    }

    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int reverseNum(int num)
{
    int reversed = 0;

    while (num > 0)
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    return reversed;
}

bool isEmirp(int num) // Time: O(√n) Space: O(1)
{
    if (num < 2)
    {
        return false;
    }

    const int reversed = reverseNum(num);

    return isPrime(num) && isPrime(reversed) && reversed != num;
}

int main()
{
    std::cout << std::boolalpha;
    // Test Case 1: 13 -> 31 (both prime, different)
    int num1 = 13;
    std::cout << num1 << ": " << isEmirp(num1) << std::endl; // true

    // Test Case 2: 17 -> 71 (both prime, different)
    int num2 = 17;
    std::cout << num2 << ": " << isEmirp(num2) << std::endl; // true

    // Test Case 3: 101 -> 101 (palindromic prime, not emirp)
    int num3 = 101;
    std::cout << num3 << ": " << isEmirp(num3) << std::endl; // false

    // Test Case 4: 12 -> 21 (12 is not prime, not emirp)
    int num4 = 12;
    std::cout << num4 << ": " << isEmirp(num4) << std::endl; // false
    std::cout << std::noboolalpha;

    return 0;
}