#include <iostream>

// Permutation (all possible strings using characters of that string)

/*
    string = "abc"

    "abc", "acb", "bac", "bca", "cab", "cba"
    possible permutations = 3! = 6
*/

// C style solution
void permutation(char str[], int k) // Time: O(n!) Space: O(n)
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

// Recursive solution
void recursivePermutation(char str[], int l, int h) {
    int i;

    if (l == h) {
        std::cout << str << " ";
    } else {
        for (i = l; i <= h; ++i) {
            std::swap(str[l], str[h]);
            recursivePermutation(str, l + 1, h);
            std::swap(str[l], str[i]);
        }
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

    return 0;
}