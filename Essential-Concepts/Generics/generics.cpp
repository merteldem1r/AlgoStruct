#include <iostream>

using namespace std;

/*
Generics is the idea to allow type (Integer, String, … etc and user-defined types) to be a parameter to methods, classes and interfaces. For example, classes like an array, map, etc, which can be used using generics very efficiently. We can use them for any type.

The method of Generic Programming is implemented to increase the efficiency of the code. Generic Programming enables the programmer to write a general algorithm which will work with all data types. It eliminates the need to create different algorithms if the data type is an integer, string or a character.

The advantages of Generic Programming are:

* Code Reusability
* Avoid Function Overloading
* Once written it can be used for multiple times and cases.
*/

// One function works for all data types.
// This would work even for user defined types
// if operator '>' is overloaded
template <typename T>

// 1) ***** Generic Functions using Template: *****
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

// 2) ***** Generic Class using Template: *****
template <typename A>
class Array
{
private:
    A *ptr;
    int size;

public:
    Array(A arr[], int s);
    void print();
};

template <typename A>
Array<A>::Array(A arr[], int s)
{
    ptr = new A[s];
    size = s;

    for (int i = 0; i < size; ++i)
    {
        ptr[i] = arr[i];
    }
}

template <typename A>
void Array<A>::print()
{
    for (int i = 0; i < size; ++i)
    {
        cout << *(ptr + i) << endl;
    }
}

// 3) ***** Working with multi-type Generics:

template <class B, class C>
class A
{
    B x;
    C y;

public:
    A()
    {
        cout << "Constructor Called" << endl;
    }
};

int main()
{
    // 1)
    cout << myMax<int>(3, 7) << endl;        // 7
    cout << myMax<double>(3.0, 7.0) << endl; // 7
    cout << myMax<char>('a', 'b') << endl;   // b

    // 2)
    int arr[5] = {1, 2, 3, 4, 5};
    int arrLen = sizeof(arr) / sizeof(arr[0]);
    Array<int> myArray = Array(arr, arrLen);
    myArray.print();

    // 3)
    A<char, char> a;  // Constructor Called
    A<int, double> b; // Constructor Called

    return 0;
}