#include <iostream>

// Tower Of Hanoi Problem

// info: https://en.wikipedia.org/wiki/Tower_of_Hanoi

/*

     Tower of Hanoi Problem Visualization (Start):

         |                  |           |
        ===                 |           |
       =====                |           |
      =======               |           |
     =========              |           |
    ============            |           |

    Source Rod (A)    Aux Rod (B)    Target Rod (C)

    Goal: Move all 5 disks from Source (A) to Target (C) following these rules:

    1. Only one disk can be moved at a time.
    2. A disk can only be placed on top of a larger disk or an empty rod.

*/

// Time: O(2^n) || Space: O(n)
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod)
{
    if (n == 0)
        return;

    towerOfHanoi(n - 1, fromRod, auxRod, toRod);

    std::cout << "  Move disk " << n << " from " << fromRod << " --> " << toRod << std::endl;

    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main()
{
    // Tower Of Hanoi visualization using 3 disks
    int n = 3;

    std::cout << "Start Tower Of Hanoi: " << std::endl;

    towerOfHanoi(n, 'A', 'C', 'B');

    std::cout << "End Tower Of Hanoi: " << std::endl;

    return 0;
}