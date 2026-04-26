#include <iostream>
#include <queue>

class Graph
{
    int n; // number of vertices
    std::vector<std::vector<int>> adj;

public:
    Graph(int vertices) : n(vertices), adj(vertices) {}

    // Add edge (undirected)
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printList()
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

    // Getter for DFS
    std::vector<std::vector<int>> &getAdj()
    {
        return adj;
    }
};

// Graph Traversal: Depth-First Search (DFS)

/*
Idea:
    - Explore one branch as deep as possible before backtracking
    - Implemented using recursion or stack

Time complexity:
    - O(V + E) with adjacency list

Use cases:
    - Cycle detection
    - Topological sort (DAG)
    - Strongly connected components
    - Articulation points and bridges
*/

void DFS(int start, std::vector<std::vector<int>> &adj)
{
}

int main()
{
    Graph graph(4);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);

    graph.printList();

    // BFS
    DFS(0, graph.getAdj());

    return 0;
}