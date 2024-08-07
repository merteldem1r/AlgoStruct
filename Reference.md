# Reference in C++

When a variable is declared as a reference, it becomes an alternative name for an existing variable. A variable can be declared as a reference by putting ‘&’ in the declaration.

![649e749cc81a1_references_in_c_01](https://github.com/user-attachments/assets/60c9d379-b117-4990-91f0-bcb00994fb51)

*Reference is basically another name (alias) for the same variable*

*References can be initizalized once and can not be assignment to another variable later*

**There are multiple applications for references in C++, a few of them are mentioned below:**

* Modify the passed parameters in a function
* Avoiding a copy of large structures
* In For Each Loop to modify all objects
* For Each Loop to avoid the copy of objects
  
**Limitations of References:**
* Once a reference is created, it cannot be later made to reference another object; it cannot be reset. This is often done with pointers.
* References cannot be NULL. Pointers are often made NULL to indicate that they are not pointing to any valid thing.
* A reference must be initialized when declared. There is no such restriction with pointers.
