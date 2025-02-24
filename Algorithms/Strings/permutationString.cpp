#include <iostream>

// Permutation (all possible strings using characters of that string)

/*
    string = "abc"

    "abc", "acb", "bac", "bca", "cab", "cba"
    possible permutations = 3! = 6
*/

// C style solution
void permutation(char str[], int k) // Time: O(n * n!) Space: O(n)
{
    static int A[10] = {0};
    static char res[10];

    if (str[k] == '\0')
    {
        res[k] = '\0';
        printf("%s ", res);
    }
    else
    {
        for (int i = 0; str[i] != '\0'; ++i)
        {
            if (A[i] == 0)
            {
                res[k] = str[i];
                A[i] = 1;
                permutation(str, k + 1);
                A[i] = 0;
            }
        }
    }
}

// Recursive solutions

// Reverse Lexicographic order
void recursivePermutation(char str[], int l, int h) // Time: O(n * n!) Space: O(n)
{
    int i;
    if (l == h)
        std::cout << str << " ";
    else
        for (i = l; i <= h; ++i)
        {
            std::swap(str[l], str[h]);
            recursivePermutation(str, l + 1, h);
            std::swap(str[l], str[i]);
        }
}

// Lexicographic order
void recursivePermutation2(std::string &str, int l, int h) // Time: O(n * n!) Space: O(n)
{
    if (l == h)
        std::cout << str << " ";
    else
        for (int i = l; i <= h; ++i)
        {
            std::swap(str[l], str[i]);
            recursivePermutation2(str, l + 1, h);
            std::swap(str[l], str[i]);
        }
}

int main()
{
    char str[] = "abc";

    std::cout << "all permutations of " << str << " is: "; // abc acb bac bca cab cba
    permutation(str, 0);

    std::cout << std::endl;
    std::cout << "all recursive permutations of " << str << " is: "; // cab cba bca bac acb abc
    recursivePermutation(str, 0, 2);

    std::cout << std::endl;

    std::string str2 = "abc";
    std::cout << "all recursive permutations of " << str2 << " is: "; // abc acb bac bca cab cba
    recursivePermutation2(str2, 0, 2);
    std::cout << std::endl;
    std::cout << str2;

    return 0;
}