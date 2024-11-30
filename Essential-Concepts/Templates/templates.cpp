#include <iostream>

// 1) Function Templates

template <typename T>
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

// 2) Class Templates

template <class T>
class Arithametic
{
private:
    T a;
    T b;

public:
    Arithametic(T a, T b);
    T add();
    T sub();
};

template <class T>
Arithametic<T>::Arithametic(T a, T b)
{
    this->a = a;
    this->b = b;
};

template <class T>
T Arithametic<T>::add()
{
    T c;
    c = a + b;
    return c;
}

template <class T>
T Arithametic<T>::sub()
{
    T c;
    c = a - b;
    return c;
}

int main()
{
    // 1) Function Templates
    std::cout << myMax<int>(3, 7) << std::endl;        // 7
    std::cout << myMax<double>(3.0, 7.0) << std::endl; // 7
    std::cout << myMax<char>('g', 'e') << std::endl;   // g

    // 2) Class Templates
    Arithametic<int> ar(10, 5);
    Arithametic<float> ar2(2.5, 4.2);

    std::cout << ar.add() << std::endl;  // 15
    std::cout << ar2.sub() << std::endl; // -1.7

    return 0;
}