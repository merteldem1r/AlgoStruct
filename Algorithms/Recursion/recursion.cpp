#include <iostream>

using namespace std;

// Simple difference between two Recursion functions:

// first PRINT then CALL itself
void func1(int x)
{
    if (x > 0)
    {
        cout << x << endl;
        func1(x - 1);
    }
}

// first CALL itself then PRINT
void func2(int x)
{
    if (x > 0)
    {
        func2(x - 1);
        cout << x << endl;
    }
}

/*
    Generalising Recursion

    * loops (for & while) has only Ascending phase rather than Recursion
    * there is two PHASES on Recursion -> Ascending and Descending

    void func(int n) {

        if (n > 0) {
            1. execute at CALLING time; (Ascending)

            2. RECURION func(n - 1);

            3. execute at RETURNING time; (Descending)
        }

    }

*/

int main()
{
    int x = 3;

    cout << "func1 outputs: " << endl;
    func1(x); // 3 2 1

    cout << "func2 outputs: " << endl;
    func2(x); // 1 2 3

    return 0;
}