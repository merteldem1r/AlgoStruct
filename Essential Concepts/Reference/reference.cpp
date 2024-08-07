#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
When a variable is declared as a reference, it becomes an alternative name for an existing variable. A variable can be declared as a reference by putting ‘&’ in the declaration.
*/

/*
There are multiple applications for references in C++, a few of them are mentioned below:

* Modify the passed parameters in a function
* Avoiding a copy of large structures
* In For Each Loop to modify all objects
* For Each Loop to avoid the copy of objects
*/

/*
Limitations of References:
* Once a reference is created, it cannot be later made to reference another object; it cannot be reset. This is often done with pointers.
* References cannot be NULL. Pointers are often made NULL to indicate that they are not pointing to any valid thing.
* A reference must be initialized when declared. There is no such restriction with pointers.

*/

// reference is basically another name (alias) for the same variable
// references can be initizalized once and can not be assignment to another variable later

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

    cout << "a: " << a << endl; // 10

    ref = 20;

    cout << "a: " << a << endl; // 20

    cout << "&a: " << &a << endl;     // 0xfcb55ff804
    cout << "&ref: " << &ref << endl; // 0xfcb55ff804

    int x = 1;
    int y = 2;

    swap(x, y);

    cout << "x: " << x << " y: " << y << endl; // x: 2 y: 1

    // Using reference in for each loop to modify all elements

    vector<int> nums = {10, 20, 30, 40};

    for (auto &num : nums)
    {
        num += 5;
    }

    for (int num : nums)
    {
        cout << "num: " << num << endl;
    }

    vector<string> vect = {"hello world", "cpp essentials", "references examples"};

    // We avoid copy of the whole string
    for (const auto &x : vect)
    {
        cout << x << endl;
    }

    return 0;
}