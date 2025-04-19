#include <iostream>

/*
    Catalan Formula:

        Catalan numbers are defined as a mathematical sequence that consists of positive integers, which can be used to find the number of possibilities of various combinations.  The nth term in the sequence denoted Cn, is found in the following formula:

            Catalan Number Formula:
                Cn = (1 / (n + 1)) * (2n choose n)
                = (2n)! / [(n + 1)! * n!]

            --- What is (2n choose n)? ---
            This is the **combination formula**, written as:
                (2n choose n) = (2n)! / (n! * n!)

            It represents the number of ways to choose 'n' elements from a set of '2n'
            elements, without considering order.

            The first few Catalan numbers for n = 0, 1, 2, 3, 4, 5… are: 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …  so on.

        Catalan numbers occur in many interesting counting problems like the following:

        • Count the number of expressions containing n pairs of parentheses that are correctly matched.
        • Count the number of possible Binary Search Trees with n keys
        • Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
        • Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.

        For more information: https://www.geeksforgeeks.org/program-nth-catalan-number/
*/

// Time: O(n^2) Space: O(n)
int possibleBinaryTreeCount(int n)
{
    std::vector<int> catalan(n + 1, 0);
    catalan[0] = catalan[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }

    return catalan[n];
}

int main()
{
    // Finding possible binary tree count using Catalan Number:
    const int nodeCount = 6;
    const int nodeCount2 = 4;

    std::cout << "Possible binary tree count for " << nodeCount << " nodes is: " << possibleBinaryTreeCount(nodeCount) << std::endl;   // 132
    std::cout << "Possible binary tree count for " << nodeCount2 << " nodes is: " << possibleBinaryTreeCount(nodeCount2) << std::endl; // 14

    return 0;
}