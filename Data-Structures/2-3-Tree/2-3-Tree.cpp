#include "iostream"

// 2-3 Trees
// Author: Mert Eldemir

/*

    Properties:

        * 2-3 Trees are: Multiway search trees with Degree 3
            * Degree of Binary Search Tree is 2 (each node has 2 children)
            * Everything is bigger than degree of 2 called as the Multiway

        * B-Tree (general concept for any Degree)
            * B-Trees are: Height Balance Search Trees
            * We can call the 2-3 Trees as B-Tree with Degree 3
            * Every node must have the: [degree/2] children
                * E.g. tree with degree 5: [5/2] = 2.5 = 3 (it must have at least 3 children)
            * Height of a B-Tree in general of logN
            * They are usually used in the Database Management System (DBMS)
                * Widely used in real-world systems where efficient large-scale storage and retrieval is needed 
                * B-Trees are used in indexes. For example, a B-Tree index allows the database to quickly find all entries between two values, like age BETWEEN 30 AND 40

    Rules of 2-3 Trees:

        * All leaf nodes at the same level
        * Every node must have minimum 2 children: from the above B-Tree property we have [3/2] = 2 minimum children
        * It can not have duplicates (as all search trees)

        * Structure:
                     |k1|k2|
                   /    |    \
              | | |   | | |    | | |
                l       m        n

            * When 3 children are present 2 keys are possible (k1, k2)
            * k1 < k2 (it means keys inside the node must be sorted)
            * l < k1 (left child keys less than k1)
            * k2 < n (right child keys greater than k2)
            * k1 < m < k2 (middle child greater than k1 & less than k2)
            
            * Final key arrange: l < k1 < m < k2 < n
*/

struct TwoThreeNode {
    int k1, k2;
    TwoThreeNode* left;
    TwoThreeNode* middle;
    TwoThreeNode* right;
};

int main()
{
    return 0;
}