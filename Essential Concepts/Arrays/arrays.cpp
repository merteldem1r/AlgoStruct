#include <iostream>

using namespace std;

int main()
{
    int A[5];
    A[0] = 4;
    A[1] = 5;

    int B[] = {1, 2, 3};

    cout << "sizeof(A): " << sizeof(A) << endl;           // 20 bytes
    cout << "sizeof(B): " << sizeof(B) << endl;           // 12 bytes
    cout << "size: " << sizeof(B) / sizeof(B[0]) << endl; // 3

    for (auto num : B)
    {
        cout << "num: " << num << endl;
    }

    return 0;
}