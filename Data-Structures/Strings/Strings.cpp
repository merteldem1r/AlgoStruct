#include <iostream>

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
    printf("Str2 sizeof: %d \n", sizeof(str2)); // 7 characters + \0 = 8 bytes

    return 0;
}