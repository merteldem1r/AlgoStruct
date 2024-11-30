#include <iostream>

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
        std::cout << "A[i]: " << A[i] << std::endl;
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
    std::cout << "Performing an action..." << std::endl;
    callback();
}

void sayHello()
{
    std::cout << "Hello!" << std::endl;
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

    std::cout << "z: " << z << std::endl; // 7

    // Pass by Address ****

    int a = 1, b = 2;
    swap(&a, &b); // passing address

    std::cout << "a: " << a << " b: " << b << std::endl; // a: 2 b :1

    // Pass by Reference *****

    int i = 1, j = 2;
    swapRef(i, j);

    std::cout << "i: " << i << " j: " << j << std::endl; // i: 2 j :1

    // Passing array
    int A[5] = {1, 2, 3, 4, 5};
    int ASize = sizeof(A) / sizeof(A[0]);
    printArr(A, ASize);

    std::cout << "A[ASize - 1]: " << A[ASize - 1] << std::endl; // 25

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
        std::cout << "B[i]: " << B[i] << std::endl;
    }

    delete[] B;

    // ******* Structure as Parameter
    Rectangle r = {10, 5};

    // call by value
    std::cout << "area of r: " << area(r) << std::endl; // 50;

    // call by reference
    std::cout << "area of r: " << rArea(r) << std::endl;  // 50;
    std::cout << "r.length: " << r.length << std::endl;   // 15;
    std::cout << "r.breadth: " << r.breadth << std::endl; // 20;

    // call by address
    changeLen(&r);                                      // pass adress
    std::cout << "r.length: " << r.length << std::endl; // 30;

    // function which return pointer to structure object that created on Heap
    Rectangle *rPtr = retRec();

    std::cout << "rPtr->length: " << rPtr->length << std::endl;   // 30
    std::cout << "rPtr->breadth: " << rPtr->breadth << std::endl; // 40

    delete rPtr;

    // Callback function
    performeFunction(sayHello); // Performing an action... Hello!

    // An array of function pointer and how the elements are accessed
    int (*funcArray[3])(int, int) = {addFunc, subtractFunc, multiplyFunc};

    // Variables to use as function parameters
    int t = 2, e = 3;

    // Access and call the functions using the arrae of function pointers
    std::cout << "Add: " << funcArray[0](t, e) << std::endl;      // Calls add(10, 5)
    std::cout << "Subtract: " << funcArray[1](t, e) << std::endl; // Calls subtract(10, 5)
    std::cout << "Multiply: " << funcArray[2](t, e) << std::endl; // Calls multiply(10, 5)

    return 0;
}