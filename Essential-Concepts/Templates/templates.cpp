#include <iostream>

using namespace std;

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
    cout << myMax<int>(3, 7) << endl;        // 7
    cout << myMax<double>(3.0, 7.0) << endl; // 7
    cout << myMax<char>('g', 'e') << endl;   // g

    // 2) Class Templates
    Arithametic<int> ar(10, 5);
    Arithametic<float> ar2(2.5, 4.2);

    cout << ar.add() << endl;  // 15
    cout << ar2.sub() << endl; // -1.7

    return 0;
}