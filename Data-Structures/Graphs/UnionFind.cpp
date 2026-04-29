#include <iostream>

// Disjoint Set (UnionFind) - Data Structure
// Related Article: https://www.geeksforgeeks.org/dsa/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
// More optimized version: Data-Structures/Graphs/DisjointUnionSets.cpp
// Author: Mert Eldemir

/*
Two sets are called disjoint sets if they don't have any element in common. The disjoint set data structure is used to store such sets. It supports following operations:

    * Merging two disjoint sets to a single set using Union operation.
    * Finding representative of a disjoint set using Find operation.
    * Check if two elements belong to same set or not. We mainly find representative of both and check if same.


Consider a situation with a number of persons and the following tasks to be performed on them:

    * Add a new friendship relation, i.e. a person x becomes the friend of another person y i.e adding new element to a set.
    * Find whether individual x is a friend of individual y (direct or indirect friend)

Examples:
    We are given 10 individuals say, a, b, c, d, e, f, g, h, i, j

    Following are relationships to be added:
    a <-> b
    b <-> d
    c <-> f
    c <-> i
    j <-> e
    g <-> j

    Given queries like whether a is a friend of d or not. We basically need to create following 4 groups and maintain a quickly accessible connection among group items:
    G1 = {a, b, d}
    G2 = {c, f, i}
    G3 = {e, g, j}
    G4 = {h}
*/

class UnionFind
{
private:
    std::vector<int> parent;

public:
    UnionFind(int n)
    {
        parent.resize(n);

        // initialize the parent arr as each element its own representative
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    // // Find the representative (root) of the
    int find(int i)
    {
        if (parent[i] == i)
        {
            return i;
        }

        // Else recursively find the representative
        return find(parent[i]);
    }

    // Unite (merge) the set that includes element
    // i and the set that includes element j
    void unite(int i, int j)
    {
        // Representative of set containing i
        int iRep = find(i);

        // Representative of set containing j
        int jRep = find(j);

        // Make the representative of i's set
        // be the representative of j's set
        parent[iRep] = jRep;
    }
};

int main()
{
    int size = 6;
    UnionFind uf(size);
    uf.unite(1, 2);
    uf.unite(3, 4);

    /*
        4 different sets:
            --------      --------     ---      ---
           | 1 -- 2 |    | 3 -- 4 |   | 5 |    | 6 |
            --------      --------     ---      ---
    */

    const bool inSameSet = (uf.find(1) == uf.find(2));
    std::cout << "Are 1 and 2 in the same set? " << (inSameSet ? "Yes" : "No") << std::endl; // Yes

    const bool inSameSet2 = (uf.find(4) == uf.find(6));
    std::cout << "Are 4 and 6 in the same set? " << (inSameSet2 ? "Yes" : "No") << std::endl; // No

    return 0;
}