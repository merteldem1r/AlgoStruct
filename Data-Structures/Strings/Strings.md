# Strings - Data Structure

In computer programming, a string is traditionally a sequence of characters, either as a literal constant or as some kind of variable. The latter may allow its elements to be mutated and the length changed, or it may be fixed (after creation). A string is generally considered as a data type and is often implemented as an array data structure of bytes (or words) that stores a sequence of elements, typically characters, using some character encoding. String may also denote more general arrays or other sequence (or list) data types and structures.

## General Properties of Strings in C and C++

- **Character Sequence**: A string is a sequence of characters, including letters, digits, symbols, and whitespace.
- **Null-Termination** (C Strings): In C, strings are character arrays ending with a null character (\0).
- **Mutability**: Strings can be modified if stored in a character array, but string literals are read-only.
  Memory Management: In C, strings require manual memory allocation (malloc, free), while - C++ provides automatic management via std::string.
- Encoding: Typically ASCII or UTF-8, depending on implementation.
- Operations: Common operations include concatenation, comparison, and length determination.

## **C-Specific** Properties of Strings

1. **Represented as Character Arrays**: Declared as char str[] = "Hello"; or char \*str = "Hello";.

2. **Null-Termination (\0)**: Strings must end with a \0 to indicate termination.

3. Manipulated with **Standard Library** Functions:

- strlen(): Get length
- strcpy(), strncpy(): Copy strings
- strcat(), strncat(): Concatenate strings
- strcmp(), strncmp(): Compare strings
- strchr(), strstr(): Search within strings

4. **Fixed or Dynamic Memory Allocation**:

- Fixed:
  `char str[20] = "Hello";`
- Dynamic:
  `char _str = (char _)malloc(20 \* sizeof(char));`

5. **String Literals are Read-Only**: `char \*str = "Hello";` cannot be modified.

## **C++-Specific** Properties of Strings

1. Uses **std::string Class**:

   - Safer and more convenient than C-style strings.
   - Dynamic memory management (automatically resizes).
   - Supports overloaded operators (+, ==, +=).
   - Example: std::string s = "Hello";

2. More Functionality with **std::string**:

   - .size(), .length(): Get length
   - .append(), +=: Concatenate
   - .substr(): Extract substring
   - .find(): Find substring
   - .replace(): Replace substring
   - .c_str(): Convert to C-style string

3. Supports **Iterators**:

   - Can be used with iterators like vectors.
   - `for (char c : str) { /_ loop through string _/ }`

4. **Input Handling**:

   - `std::getline(std::cin, str);` reads an entire line (including spaces).
   - `std::cin >> str;` reads until whitespace.

5. No Need for **Manual Memory Management**:
   - Unlike C, no malloc() or free() is required.
   - Memory is managed automatically.

## String Mutability in C++ vs. Python

### C++ (std::string)

- **Mutable**: Can change contents without creating a new object.

- **Efficient Copying**: Uses copy-on-write or reference counting (in some implementations), making copying operations often **O(1)** until modification.

- **Concatenation**: Appending strings is generally **O(n)** due to reallocation.

### Python (str)

- **Immutable**: Cannot change contents after creation.
- **Inefficient Copying**: Creating a modified string results in a new string, leading to **O(n)** copying each time.
- **Concatenation**: Repeated concatenation inside a loop can degrade to **O(n^2)** due to repeated copying.


