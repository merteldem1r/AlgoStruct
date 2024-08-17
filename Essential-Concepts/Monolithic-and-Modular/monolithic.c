#include <stdio.h>

// MONOLITHIC PROGRAM

int main()
{
    int length = 0, breadth = 0;

    printf("Enter length and breadth: \n");
    scanf("%d %d", &length, &breadth);

    int area = length * breadth;
    int peri = 2 * (length + breadth);

    printf("Area: %d Perimeter: %d\n", area, peri);

    return 0;
}
