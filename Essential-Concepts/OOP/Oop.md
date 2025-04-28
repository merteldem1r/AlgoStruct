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

```cpp
#include <iostream>

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

  std::cout << "obj's area: " << obj.area() << '\n';
  std::cout << "*foo's area: " << foo->area() << '\n';
  std::cout << "bar's area: " << bar->area() << '\n';
  std::cout << "baz[0]'s area:" << baz[0].area() << '\n';
  std::cout << "baz[1]'s area:" << baz[1].area() << '\n';

  delete bar;
  delete[] baz;

  return 0;
}
```

# Classes defined with struct and union

Classes can be defined not only with keyword class, but also with keywords **struct** and union.

The keyword **struct**, generally used to declare plain **data structures**, can also be used to declare classes that have **member functions**, with the same syntax as with keyword class. The only difference between both is that members of classes declared with the keyword struct have _public_ access by default, while members of classes declared with the keyword class have _private_ access by default. For all other purposes both keywords are equivalent in this context.

Conversely, the concept of **unions** is different from that of classes declared with struct and class, since unions only store one data member at a time, but nevertheless they are also classes and can thus also hold member functions. The default access in union classes is _public_.

# Static members

A class can contain static members, either data or functions.

A static data member of a class is also known as a "class variable", because there is only one common variable for all the objects of that same class, sharing the same value: i.e., its value is not different from one object of this class to another.

# Characteristics of an Object-Oriented Programming Language

![OOPs-Concepts](https://github.com/user-attachments/assets/e57c134a-530b-4d49-9070-5b00915bf113)

## Class

The building block of C++ that leads to Object-Oriented programming is a Class. It is a user-defined data type, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class. A class is like a blueprint for an object. For Example: Consider the Class of Cars. There may be many cars with different names and brands but all of them will share some common properties like all of them will have 4 wheels, Speed Limit, Mileage range, etc. So here, the Car is the class, and wheels, speed limits, and mileage are their properties.

- A Class is a user-defined data type that has data members and member functions.

- Data members are the data variables and member functions are the functions used to manipulate these variables together these data members and member functions define the properties and behavior of the objects in a Class.

- In the above example of class Car, the data member will be speed limit, mileage, etc and member functions can apply brakes, increase speed, etc.

We can say that a Class in C++ is a blueprint representing a group of objects which shares some common properties and behaviors.

## Object

An Object is an identifiable entity with some characteristics and behavior. An Object is an instance of a Class. When a class is defined, no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated.

## Encapsulation

In normal terms, Encapsulation is defined as wrapping up data and information under a single unit. In Object-Oriented Programming, Encapsulation is defined as binding together the data and the functions that manipulate them. Consider a real-life example of encapsulation, in a company, there are different sections like the accounts section, finance section, sales section, etc. The finance section handles all the financial transactions and keeps records of all the data related to finance. Similarly, the sales section handles all the sales-related activities and keeps records of all the sales. Now there may arise a situation when for some reason an official from the finance section needs all the data about sales in a particular month. In this case, he is not allowed to directly access the data of the sales section. He will first have to contact some other officer in the sales section and then request him to give the particular data. This is what encapsulation is. Here the data of the sales section and the employees that can manipulate them are wrapped under a single name “sales section”.

Encapsulation also leads to data abstraction or data hiding. Using encapsulation also hides the data. In the above example, the data of any of the sections like sales, finance, or accounts are hidden from any other section.

## Abstraction

Data abstraction is one of the most essential and important features of object-oriented programming in C++. Abstraction means displaying only essential information and hiding the details. Data abstraction refers to providing only essential information about the data to the outside world, hiding the background details or implementation. Consider a real-life example of a man driving a car. The man only knows that pressing the accelerator will increase the speed of the car or applying brakes will stop the car but he does not know how on pressing the accelerator the speed is actually increasing, he does not know about the inner mechanism of the car or the implementation of an accelerator, brakes, etc. in the car. This is what abstraction is.

- **Abstraction using Classes:** We can implement Abstraction in C++ using classes. The class helps us to group data members and member functions using available access specifiers. A Class can decide which data member will be visible to the outside world and which is not.

- **Abstraction in Header files:** One more type of abstraction in C++ can be header files. For example, consider the pow() method present in math.h header file. Whenever we need to calculate the power of a number, we simply call the function pow() present in the math.h header file and pass the numbers as arguments without knowing the underlying algorithm according to which the function is actually calculating the power of numbers.

## Polymorphism

The word polymorphism means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form. A person at the same time can have different characteristics. A man at the same time is a father, a husband, and an employee. So the same person possesses different behavior in different situations. This is called polymorphism. An operation may exhibit different behaviors in different instances. The behavior depends upon the types of data used in the operation. C++ supports operator overloading and function overloading.

- **Operator Overloading:** The process of making an operator exhibit different behaviors in different instances is known as operator overloading.

- **Function Overloading:** Function overloading is using a single function name to perform different types of tasks. Polymorphism is extensively used in implementing inheritance.

**Example:** Suppose we have to write a function to add some integers, sometimes there are 2 integers, and sometimes there are 3 integers. We can write the Addition Method with the same name having different parameters, the concerned method will be called according to parameters.

![polymorphismexample-660x460](https://github.com/user-attachments/assets/208a7947-f535-42fa-9b48-a67b089dac80)

## Inheritance

The capability of a class to derive properties and characteristics from another class is called Inheritance. Inheritance is one of the most important features of Object-Oriented Programming.

- **Sub Class:** The class that inherits properties from another class is called Sub class or Derived Class.

- **Super Class:** The class whose properties are inherited by a sub-class is called Base Class or Superclass.

- **Reusability:** Inheritance supports the concept of “reusability”, i.e. when we want to create a new class and there is already a class that includes some of the code that we want, we can derive our new class from the existing class. By doing this, we are reusing the fields and methods of the existing class.
