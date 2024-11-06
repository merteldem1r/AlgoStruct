#include <iostream>
#include <vector>

using namespace std;

// Fibonacci Series

// f(n) = 0,1,1,2,3,5,8,13,21,34 ...

// n =    0,1,2,3,4,5,6,7,8,9 ...

// Naive Approach

int fibonacciNaive(int n) // Time: O(2^n) | Space:O(n)
{
    if (n <= 1)
    {
        return n;
    }

    return fibonacciNaive(n - 1) + fibonacciNaive(n - 2);
}

/*

Excessive Recursion: repeats computations multiple time for same parameters

Visualization of calls for fibonacciNaive(5):

├── fibonacciNaive(4)
│   ├── fibonacciNaive(3)
│   │   ├── fibonacciNaive(2)
│   │   │   ├── fibonacciNaive(1) -> 1
│   │   │   └── fibonacciNaive(0) -> 0
│   │   └── Result: 1 + 0 = 1
│   └── fibonacciNaive(2)
│       ├── fibonacciNaive(1) -> 1
│       └── fibonacciNaive(0) -> 0
│   └── Result: 1 + 1 = 2
└── Result: 2 + 1 = 3
└── fibonacciNaive(3)
    ├── fibonacciNaive(2)
    │   ├── fibonacciNaive(1) -> 1
    │   └── fibonacciNaive(0) -> 0
    └── Result: 1 + 0 = 1
└── Result : 3 + 2 = 5

*/

// Fibonacci Memoization

int fibonacciMemoLoop(int n) // Time O(n) | Space(n)
{
    if (n <= 1)
        return n;

    vector<int> arr(n + 1);
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}

int fibonacciMemoRec(int n, vector<int> &arr) // Time O(n) | Space(n)
{
    if (n <= 1)
        return n;

    if (arr[n] != -1)
        return arr[n];

    arr[n] = fibonacciMemoRec(n - 1, arr) + fibonacciMemoRec(n - 2, arr);
    return arr[n];
}

/*

AVOIDING Excessive Recursion

Recursive steps with memoization for fibonacciMemoRec(5):

fibonacciMemoRec(5)
├── fibonacciMemoRec(4)
│   ├── fibonacciMemoRec(3)
│   │   ├── fibonacciMemoRec(2)
│   │   │   ├── fibonacciMemoRec(1) -> 1 (Base case, stored in arr[1])
│   │   │   └── fibonacciMemoRec(0) -> 0 (Base case, stored in arr[0])
│   │   └── Result: arr[2] = 1 + 0 = 1
│   └── fibonacciMemoRec(2) -> Uses arr[2] = 1 (already computed)
│   └── Result: arr[3] = 1 + 1 = 2
└── fibonacciMemoRec(3) -> Uses arr[3] = 2 (already computed)
└── Result: arr[4] = 2 + 1 = 3
└── fibonacciMemoRec(4) -> Uses arr[4] = 3 (already computed)
└── Result: arr[5] = 3 + 2 = 5


    Final result: arr[5] = 5
    arr = [0, 1, 1, 2, 3, 5]

*/

int fibonacciHelperRec(int n)
{
    vector<int> arr(n + 1, -1);
    return fibonacciMemoRec(n, arr);
}

int main()
{
    cout << "fibonacciNaive: " << fibonacciNaive(3) << endl;         // 2
    cout << "fibonacciMemoLoop: " << fibonacciMemoLoop(9) << endl;   // 34
    cout << "fibonacciHelperRec: " << fibonacciHelperRec(4) << endl; // 3

    return 0;
}