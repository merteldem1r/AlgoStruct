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

    // Getter for BFS
    std::vector<std::vector<int>> &getAdj()
    {
        return adj;
    }
};

// Graph Traversal: Breadth First Search (BFS)

/*
Idea:
    - Explore layer by layer using a queue
    - Excellent for shortest path in unweighted graphs

Time complexity:
    - O(V + E) with adjacency list

Use cases:

    - Minimum number of edges from source
    - Connected component detection
    - Level order exploration in networks
*/

void BFS(int start, std::vector<std::vector<int>> &adj)
{
    std::vector<bool> visited(adj.size(), false);
    std::queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int vertice = q.front();
        q.pop();

        std::cout << vertice << " ";

        for (int neighbor : adj[vertice])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
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
    BFS(0, graph.getAdj());

    return 0;
}