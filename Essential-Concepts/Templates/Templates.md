# Templates in C++

A **template** is a simple yet very powerful tool in C++. The simple idea is to pass the data type as a parameter so that we don’t need to write the same code for different data types. For example, a software company may need to sort() for different data types. Rather than writing and maintaining multiple codes, we can write one sort() and pass the datatype as a parameter.

C++ adds two new keywords to support templates: ‘template’ and _‘typename’_. The second keyword can always be replaced by the keyword ‘class’.

## How Do Templates Work?

Templates are expanded at compiler time. This is like macros. The difference is, that the compiler does type-checking before template expansion. The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of the same function/class.

![templates-cpp](https://github.com/user-attachments/assets/b7aa957d-32e5-4e12-8352-0c54b2c5c4c9)

