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

// using std::unordered_map
class AdjacencyListGraphMap
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

// using std::vector
class AdjacencyListGraphVector
{
    int n; // number of vertices
    std::vector<std::vector<int>> adj;

public:
    AdjacencyListGraphVector(int vertices) : n(vertices), adj(vertices) {}

    // Add edge (undirected)
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << i << " -> ";
            for (int neighbor : adj[i])
            {
                std::cout << neighbor << " ";
            }
            std::cout << "\n";
        }
    }

    // Getter for BFS
    std::vector<std::vector<int>> &getAdj()
    {
        return adj;
    }
};

int main()
{
    AdjacencyListGraphMap Graph;

    Graph.addEdge(0, 1);
    Graph.addEdge(0, 2);
    Graph.addEdge(1, 3);
    Graph.addEdge(2, 3);

    Graph.printList();

    return 0;
}