#include <iostream>

class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle(int l, int b) // with just writing class name so this becomes as constructor to initializating
    {
        length = l;
        breadth = b;
    }

    int area()
    {
        return length * breadth;
    }

    void changeLength(int l)
    {
        length = l;
    };
};

int main()
{
    Rectangle r = {10, 5};                          // object
    std::cout << "area: " << r.area() << std::endl; // 50;

    r.changeLength(20);

    std::cout << "area: " << r.area() << std::endl; // 100;
    return 0;
}