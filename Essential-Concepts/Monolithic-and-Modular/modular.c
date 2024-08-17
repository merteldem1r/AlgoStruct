#include <stdio.h>

// MODULAR PROGRAM

struct Rectangle
{
    int length;
    int breadth;
};

int area(struct Rectangle *r)
{
    return r->length * r->breadth;
}

int perimeter(struct Rectangle *r)
{
    int p = 2 * (r->length + r->breadth);
    return p;
}

int main()
{
    struct Rectangle r = {0, 0};

    printf("Enter length and breadth: \n");
    scanf("%d %d", &r.length, &r.breadth);

    int rArea = area(&r);
    int rPerimeter = perimeter(&r);

    printf("Area: %d Perimeter: %d\n", rArea, rPerimeter);

    return 0;
}
