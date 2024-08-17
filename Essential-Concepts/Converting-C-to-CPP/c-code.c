#include <stdio.h>

struct Rectangle
{
    int length;
    int breadth;
};

void initialize(struct Rectangle *r, int l, int b)
{
    r->length = l;
    r->breadth = b;
}

int area(struct Rectangle r)
{
    return r.length * r.breadth;
}

void changeLength(struct Rectangle *r, int l)
{
    r->length = l;
};

int main()
{
    struct Rectangle r;

    initialize(&r, 10, 5);

    printf("%d", area(r)); // 50
    changeLength(&r, 20);

    printf("\nlength: %d", r.length); // 20
    printf("\n%d", area(r));          // 100

    return 0;
}