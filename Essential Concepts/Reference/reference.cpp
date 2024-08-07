#include <iostream>
#include <vector>
#include <string>

using namespace std;

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