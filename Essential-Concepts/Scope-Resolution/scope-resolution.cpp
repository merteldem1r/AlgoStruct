#include <iostream>

int x = 10; // Global variable

class MyClass
{
public:
    void display(); // Declaration inside the class

    static int count; // Static member declaration
    static void displayCount()
    {
        std::cout << "Count: " << count << std::endl;
    }
};

// Definition outside the class using scope resolution
void MyClass::display()
{
    std::cout << "Hello, World!" << std::endl;
}

int MyClass::count = 5; // Definition of static member outside the class

namespace MyNamespace
{
    int value = 42;
}

int main()
{
    // 1) Accessing Global Variables:

    int x = 20; // Local variable
    std::cout << "Local x: " << x << std::endl;
    std::cout << "Global x: " << ::x << std::endl; // Accessing global variable

    // Local x: 20
    // Global x: 10

    // 2) Defining Class Member Functions Outside the Class:

    MyClass obj;
    obj.display(); // Hello, World!

    // 3) Accessing Static Members:

    MyClass::displayCount(); // Accessing static member using scope resolution // Count: 5

    // 4) Accessing Namespaces:

    std::cout << "Value: " << MyNamespace::value << std::endl; // Accessing value inside namespace // Value: 42

    return 0;
}
