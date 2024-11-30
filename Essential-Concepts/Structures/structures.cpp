#include <iostream>

// Structures (also called structs) are a way to group several related variables into one place. Each variable in the structure is known as a member of the structure.

struct Rectangle
{
    int length;
    int breadth;

    void getArea()
    {
        std::cout << length * breadth << std::endl;
    }
};

struct Student
{
    int grade;
    char name[25];
    char address[50];
};

struct Card
{
    int face;
    int shape;
    int color;
};

int main()
{

    // *** Creating object on Stack
    Rectangle r;
    r.breadth = 2;
    r.length = 5;
    r.getArea(); // 10

    std::cout << sizeof(r) << std::endl; // 8 bytes (4 bytes for length + 4 bytes for breadth)

    Rectangle k = {3, 5};
    k.getArea(); // 15

    // **** Creating object on Heap
    Rectangle *h = new Rectangle();
    h->breadth = 10;
    h->length = 2;

    h->getArea(); // 20

    // deallocating memory
    delete h;

    // ****
    Student s = {2, "Mert", "foo"};

    // In C, the size of a struct may include padding to ensure proper alignment of its members. The padding is added to align data members according to the architecture's alignment requirements, which can result in the size of the struct being larger than the sum of the sizes of its individual members.
    std::cout << sizeof(s) << std::endl;

    Card deck[52]; // array of Card struct

    std::cout << "sizeof card deck: " << sizeof(deck) << std::endl; // (4 + 4 + 4) * 52 = 624

    return 0;
}