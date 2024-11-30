#include <iostream>

// Taylor Series

/*

Taylor Series for e^x: e^x = 1 + (x^1 / 1!) + (x^2 / 2!) + (x^3 / 3!) + ... + (x^n / n!)

Taylor Series for sin(x): sin(x) = x - (x^3 / 3!) + (x^5 / 5!) - (x^7 / 7!) + ... + (-1)^n * (x^(2n+1) / (2n+1)!)

Taylor Series for cos(x): cos(x) = 1 - (x^2 / 2!) + (x^4 / 4!) - (x^6 / 6!) + ... + (-1)^n * (x^(2n) / (2n)!)

Taylor Series for ln(1 + x): ln(1 + x) = x - (x^2 / 2) + (x^3 / 3) - (x^4 / 4) + ... + (-1)^(n+1) * (x^n / n)

*/

double taylorSeries(int x, int n) // For e^x series for n terms
{
    static double p = 1, f = 1;
    double r = 1;

    if (n == 0)
    {
        return 1;
    }

    r = taylorSeries(x, n - 1);
    p = p * x;
    f = f * n;
    return r + p / f;
}

// Tayloe Series using Horner's Rule
// how to reduce multiplications?

// e^x: e^x = 1 + (x^1 / 1!) + (x^2 / 2!) + (x^3 / 3!) + ... + (x^n / n!)

// ->  1 + x/2 * [1 + x/2 * [1+ x/3 + x^2/(3*4)] ...]

// -> 1 + x * [1 + x/2 * [1 + x/3 * [1 + x/4] * n]] => O(n)

double taylorHorner(int x, int n)
{
    double s = 1;

    for (; n > 0; --n)
    {
        s = 1 + x * s / n;
    }

    return s;
}

double taylorHernerRec(int x, int n)
{
    static double s = 1;

    if (n == 0)
    {
        return s;
    }

    s = 1 + x * s / n;

    return taylorHernerRec(x, n - 1);
}

int main()
{
    std::cout << "taylorSeries: " << taylorSeries(1, 10) << std::endl;      // 2.71828
    std::cout << "taylorHorner: " << taylorHorner(1, 4) << std::endl;       // 2.70833
    std::cout << "taylorHernerRec: " << taylorHernerRec(1, 4) << std::endl; // 2.70833

    return 0;
}