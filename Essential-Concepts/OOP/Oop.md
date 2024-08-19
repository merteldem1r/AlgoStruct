# Object Oriented Programming

**Classes** are an expanded concept of **data structures**: like data structures, they can contain data members, but they can also contain functions as members.

An _object_ is an instantiation of a class. In terms of variables, a class would be the type, and an object would be the variable.

Classes are defined using either keyword _class_ or keyword _struct._

Where **class_name** is a valid identifier for the class, object_names is an optional list of names for objects of this class. The body of the declaration can contain **members**, which can either be data or function declarations, and optionally **access specifiers**.

Classes have the same format as plain **data structures**, except that they can also include functions and have these new things called access specifiers. An access specifier is one of the following three keywords: private, public or protected. These specifiers modify the access rights for the members that follow them:

## Class Members

**private** members of a class are accessible only from within other members of the same class (or from their "friends").
**protected** members are accessible from other members of the same class (or from their "friends"), but also from members of their derived classes.
Finally, **public** members are accessible from anywhere where the object is visible.

By default, all members of a class declared with the class keyword have private access for all its members. Therefore, any member that is declared before any other access specifier has private access automatically.

## Definition of Memeber Functions

The **scope operator (::)** specifies the class to which the member being defined belongs, granting exactly the same scope properties as if this function definition was directly included within the class definition.

The only difference between defining a member function completely within the class definition or to just include its declaration in the function and define it later outside the class, is that in the first case the function is automatically considered an **inline** member function by the compiler, while in the second it is a normal (not-inline) class member function. This causes no differences in behavior, but only on possible compiler optimizations.

## Constructors

class can include a special function called its **constructor**, which is automatically called whenever a new object of this class is created, allowing the class to initialize member variables or allocate storage.

This constructor function is declared just like a regular member function, but with a name that matches the class name and without any return type; not even _void._

## Member initialization in constructors

When a constructor is used to initialize other members, these other members can be initialized directly, without resorting to statements in its body. This is done by inserting, before the constructor's body, a colon (:) and a list of initializations for class members. For example, consider a class with the following declaration:

`class Rectangle {
    int width,height;
  public:
    Rectangle(int,int);
    int area() {return width*height;}
};`

- The constructor for this class could be defined, as usual, as:

`Rectangle::Rectangle (int x, int y) { width=x; height=y; }`

- But it could also be defined using member initialization as:

`Rectangle::Rectangle (int x, int y) : width(x) { height=y; }`

- Or even:

`Rectangle::Rectangle (int x, int y) : width(x), height(y) { }`

Note how in this last case, the constructor does nothing else than initialize its members, hence it has an empty function body.

For members of fundamental types, it makes no difference which of the ways above the constructor is defined, because they are not initialized by default, but for member objects (those whose type is a class), if they are not initialized after the colon, they are default-constructed.

# Pointers to classes

Objects can also be pointed to by pointers: Once declared, a class becomes a valid type, so it can be used as the type pointed to by a pointer. For example:

`Rectangle * prect;`

is a pointer to an object of class _Rectangle_.

Similarly as with plain data structures, the members of an object can be accessed directly from a pointer by using the arrow operator (->). Here is an example with some possible combinations:

`#include <iostream>
using namespace std;

class Rectangle {
int width, height;
public:
Rectangle(int x, int y) : width(x), height(y) {}
int area(void) { return width \* height; }
};

int main() {
Rectangle obj (3, 4);
Rectangle _ foo, _ bar, * baz;
foo = &obj;
bar = new Rectangle (5, 6);
baz = new Rectangle[2] { {2,5}, {3,6} };
cout << "obj's area: " << obj.area() << '\n';
cout << "*foo's area: " << foo->area() << '\n';
cout << "\*bar's area: " << bar->area() << '\n';
cout << "baz[0]'s area:" << baz[0].area() << '\n';
cout << "baz[1]'s area:" << baz[1].area() << '\n';  
 delete bar;
delete[] baz;
return 0;
}`

# Classes defined with struct and union

Classes can be defined not only with keyword class, but also with keywords **struct** and union.

The keyword **struct**, generally used to declare plain **data structures**, can also be used to declare classes that have **member functions**, with the same syntax as with keyword class. The only difference between both is that members of classes declared with the keyword struct have _public_ access by default, while members of classes declared with the keyword class have _private_ access by default. For all other purposes both keywords are equivalent in this context.

Conversely, the concept of **unions** is different from that of classes declared with struct and class, since unions only store one data member at a time, but nevertheless they are also classes and can thus also hold member functions. The default access in union classes is _public_.

# Static members

A class can contain static members, either data or functions.

A static data member of a class is also known as a "class variable", because there is only one common variable for all the objects of that same class, sharing the same value: i.e., its value is not different from one object of this class to another.
