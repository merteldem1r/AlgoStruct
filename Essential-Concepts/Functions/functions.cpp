#include <iostream>

using namespace std;

//  Pass by Value
int add(int a, int b) // prototype | (int a, int b) => formal parameters
{
    // values of formal parameters copied in formal parameters
    int c = a + b; // c => local variable
    return c;
}

// Pass by Address
void swap(int *a, int *b) // formal parameters must be pointers
{
    auto temp = *a; // derefferencing to access actual value
    *a = *b;
    *b = temp;
}

// Pass by Reference (Feature of C++)
void swapRef(int &a, int &b) // with ampersand(&), it's just alias for actual variables in memory
{
    auto temp = a;
    a = b;
    b = temp;
}

// Passing array as parameter, in C or C++ arrays can be passed only by address
void printArr(int A[], int n) // only local variable is "n", instead of writing A[] can write as *A
{
    for (int i = 0; i < n; ++i)
    {
        cout << "A[i]: " << A[i] << endl;
    }

    A[n - 1] = 25; // modify actual array
}

// Returning Array
int *rArr(int n)
{
    int *P = new int[n]; // allocating memory on Heap
    return P;
}

// Strcuture as Parameter
struct Rectangle
{
    int length;
    int breadth;
};

int area(Rectangle r) // Passed by value
{
    // will be created new copy of "r"
    // any modifications will not affect actual parameter
    int rArea = r.breadth * r.length;
    return rArea;
}

int rArea(Rectangle &r) // Passed by Reference
{
    int rArea = r.breadth * r.length;
    r.length = 15;
    r.breadth = 20;
    return rArea;
}

void changeLen(Rectangle *r) // Passed by Address
{
    r->length = 30;
}

// Create on  structure on heap and return pointer
Rectangle *retRec()
{
    Rectangle *rec = new Rectangle;
    rec->length = 30;
    rec->breadth = 40;
    return rec;
}

// Callback function
typedef void (*CallbackFun)();

void performeFunction(CallbackFun callback)
{
    cout << "Performing an action..." << endl;
    callback();
}

void sayHello()
{
    cout << "Hello!" << endl;
}

// Function declarations for array of function pointers
int addFunc(int a, int b)
{
    return a + b;
}

int subtractFunc(int a, int b)
{
    return a - b;
}

int multiplyFunc(int a, int b)
{
    return a * b;
}

int main()
{
    // Pass by Value ****

    int x = 2, y = 5; // created on Stack

    int z = add(x, y); // (x,y) => actual parameters

    cout << "z: " << z << endl; // 7

    // Pass by Address ****

    int a = 1, b = 2;
    swap(&a, &b); // passing address

    cout << "a: " << a << " b: " << b << endl; // a: 2 b :1

    // Pass by Reference *****

    int i = 1, j = 2;
    swapRef(i, j);

    cout << "i: " << i << " j: " << j << endl; // i: 2 j :1

    // Passing array
    int A[5] = {1, 2, 3, 4, 5};
    int ASize = sizeof(A) / sizeof(A[0]);
    printArr(A, ASize);

    cout << "A[ASize - 1]: " << A[ASize - 1] << endl; // 25

    // Returning Array
    int *B;
    int size = 3;

    B = rArr(size);

    // so after creating an array on Heap we can access it whereever we want if we have pointer to it
    B[0] = 1;
    B[1] = 2;
    B[2] = 3;

    for (int i = 0; i < size; ++i)
    {
        cout << "B[i]: " << B[i] << endl;
    }

    delete[] B;

    // ******* Structure as Parameter
    Rectangle r = {10, 5};

    // call by value
    cout << "area of r: " << area(r) << endl; // 50;

    // call by reference
    cout << "area of r: " << rArea(r) << endl;  // 50;
    cout << "r.length: " << r.length << endl;   // 15;
    cout << "r.breadth: " << r.breadth << endl; // 20;

    // call by address
    changeLen(&r);                            // pass adress
    cout << "r.length: " << r.length << endl; // 30;

    // function which return pointer to structure object that created on Heap
    Rectangle *rPtr = retRec();

    cout << "rPtr->length: " << rPtr->length << endl;   // 30
    cout << "rPtr->breadth: " << rPtr->breadth << endl; // 40

    delete rPtr;

    // Callback function
    performeFunction(sayHello); // Performing an action... Hello!

    // An array of function pointer and how the elements are accessed
    int (*funcArray[3])(int, int) = {addFunc, subtractFunc, multiplyFunc};

    // Variables to use as function parameters
    int t = 2, e = 3;

    // Access and call the functions using the arrae of function pointers
    cout << "Add: " << funcArray[0](t, e) << endl;      // Calls add(10, 5)
    cout << "Subtract: " << funcArray[1](t, e) << endl; // Calls subtract(10, 5)
    cout << "Multiply: " << funcArray[2](t, e) << endl; // Calls multiply(10, 5)

    return 0;
}