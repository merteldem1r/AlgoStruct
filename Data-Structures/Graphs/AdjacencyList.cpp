#include <iostream>
#include <unordered_map>
#include <vector>

/*
Adjacency List:
    Use an array/vector where each index stores neighbors of that vertex.

    Unweighted example:
        - adj[u] contains all vertices v such that edge (u, v) exists Weighted example:
        - adj[u] contains pairs (v, w)

    Advantages:
        - O(V + E) memory for sparse graphs
        - Iterating neighbors is efficient: O(deg(u))
*/

class AdjacencyListGraph
{
    std::unordered_map<int, std::vector<int>> adjList;

public:
    void addEdge(int u, int v)
    {
        adjList[u].emplace_back(v);
        adjList[v].emplace_back(u);
    }

    void printList()
    {
        for (auto &[vertex, neighbors] : adjList)
        {
            std::cout << vertex << " -> ";
            for (auto &n : neighbors)
            {
                std::cout << n << " ";
            }
            std::cout << "\n";
        }
    }
};

int main()
{
    AdjacencyListGraph Graph;

    Graph.addEdge(0, 1);
    Graph.addEdge(0, 2);
    Graph.addEdge(1, 3);
    Graph.addEdge(2, 3);

    Graph.printList();

    return 0;
}