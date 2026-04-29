#include <iostream>

// DisjointUnionSets - Data Structure (Union By Rank and Path Compression in Union-Find Algorithm)
// Related Article: https://www.geeksforgeeks.org/dsa/union-by-rank-and-path-compression-in-union-find-algorithm/
// Author: Mert Eldemir

/*
    This implementatoin is the optimization that applied to the UnionFind Data Structure (Data-Structures/Graphs/UnionFind.cpp)

    Path Compression (Used to improve find()):
        The idea is to flatten the tree when find() is called. When find() is called for an element x, root of the tree is returned. The find() operation traverses up from x to find root. The idea of path compression is to make the found root as parent of x so that we don’t have to traverse all intermediate nodes again. If x is root of a subtree, then path (to root) from all nodes under x also compresses.

    It speeds up the data structure by compressing the height of the trees. It can be achieved by inserting a small caching mechanism into the Find operation. Take a look at the code for more details:

    Union by Rank (Modifications to union()):
        Rank is like height of the trees representing different sets. We use an extra array of integers called rank[]. The size of this array is the same as the parent array Parent[]. If i is a representative of a set, rank[i] is the rank of the element i.  Rank is same as height if path compression is not used. With path compression, rank can be more than the actual height.

        Now recall that in the Union operation, it doesn’t matter which of the two trees is moved under the other. Now what we want to do is minimize the height of the resulting tree. If we are uniting two trees (or sets), let’s call them left and right, then it all depends on the rank of left and the rank of right.

            * If the rank of left is less than the rank of right, then it’s best to move left under right, because that won’t change the rank of right (while moving right under left would increase the height). In the same way, if the rank of right is less than the rank of left, then we should move right under left.
            * If the ranks are equal, it doesn’t matter which tree goes under the other, but the rank of the result will always be one greater than the rank of the trees.
*/

class DisjointUnionSets
{
private:
    std::vector<int> parent, rank;

public:
    DisjointUnionSets(int n)
    {
        parent.resize(n);
        rank.resize(n, 0); // default 0 rank for each element

        // initialize the parent arr as each element its own representative
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int i)
    {
        const int root = parent[i];

        // path compression
        if (parent[root] != root)
        {
            parent[i] = find(parent[root]);
        }

        /*
            Example (for find(1)):

                First structure:
                    0
                     \
                      2
                       \
                        1

                After path compression:
                     0
                   /   \
                  2     1
        */

        return root;
    }

    void unionSets(int x, int y)
    {
        const int xRoot = find(x);
        const int yRoot = find(y);

        // if they are on the same set -> skip
        if (xRoot == yRoot)
        {
            return;
        }

        // check and update ranks (union by rank)
        if (rank[xRoot] < rank[yRoot])
        {
            parent[xRoot] = yRoot;
        }
        else if (rank[yRoot] < rank[xRoot])
        {
            parent[yRoot] = xRoot;
        }
        else
        {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

int main()
{
    // Let there be 5 persons with ids 0, 1, 2, 3, and 4
    const int n = 5;
    DisjointUnionSets dus(n);

    // 0 is a friend of 2
    dus.unionSets(0, 2);

    // 4 is a friend of 2
    dus.unionSets(4, 2);

    // 3 is a friend of 1
    dus.unionSets(3, 1);

    // Check if 4 is a friend of 0
    std::cout << (dus.find(4) == dus.find(0) ? "Yes" : "No") << std::endl; // Yes

    // Check if 1 is a friend of 0
    std::cout << (dus.find(1) == dus.find(0) ? "Yes" : "No") << std::endl; // No

    return 0;
}