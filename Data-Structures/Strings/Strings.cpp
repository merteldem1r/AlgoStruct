#include <iostream>
#include <string>

// Strings

int main()
{
    // ****************** CHARACTERS ******************

    char chr;
    chr = 'A';

    printf("Chr ASCII Code: %d \n", chr);             // 65 (ASCII Code)
    printf("Chr: %c \n", chr);                        // A
    printf("Chr sizeof (bytes): %d \n", sizeof(chr)); // 1 byte

    // ****************** STRINGS (Array of Characters) ******************

    // %s in printf expects a null-terminated string because it keeps printing until it encounters \0 to stop

    char str[5] = {'M', 'E', 'R', 'T', '\0'}; // \0 -> null-terminator
    printf("Str: %s \n", str);                // MERT

    // Using double quotes (compiler automatically adds a null terminator at the end)
    char str2[] = "ELDEMIR";
    printf("Str2: %s \n", str2);                // ELDEMIR
    printf("Str2 sizeof: %d \n", sizeof(str2)); // 7 characters + \0 = 8

    // In C++ (unlike C), string literals are read-only and stored in a special memory section (typically .rodata in compiled binaries). Modifying a string literal is undefined behavior (UB).
    const char *str3 = "String Representation"; // should be const
    printf("Str3 (String literal): %s\n", str3);

    // ****************** STRINGS (C++ style std::string) ******************

    std::string str4 = "AlgoStruct Repository";
    std::cout << "Str4 (std::string): " << str4 << std::endl;

    // Iterate through string
    std::cout << "Str 4 Characters for loop:" << std::endl;

    // The reference (&) avoids unnecessary copying, making it more efficient.
    for (auto &chr : str4)
        std::cout << chr << " ";

    return 0;
}