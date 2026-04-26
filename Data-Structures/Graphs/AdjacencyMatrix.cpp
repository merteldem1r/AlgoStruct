#include <iostream>

/*
    Adjacency Matrix:

        For n vertices, use an n x n matrix M:

        - M[i][j] = 1 if edge exists (unweighted)
        - M[i][j] = weight if weighted
        - M[i][j] = 0 or INF if no edge

        Advantages:

        - O(1) edge existence check
        - Straightforward implementation

        Disadvantages:

        - O(V^2) memory even for sparse graphs
        - Iterating neighbors of a vertex is O(V)
*/

class AdjacencyMatrixGraph
{
    std::vector<std::vector<int>> adjMatrix;

public:
    // initialize graph with n vertices
    AdjacencyMatrixGraph(int n)
    {
        this->adjMatrix = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
    }

    // func to add the edge between vertice 'u' and 'v'
    void addEdge(int u, int v)
    {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void printMatrix()
    {
        const int n = adjMatrix.size();
        for (int i = 0; i < n; ++i)
        {
            std::cout << "[ ";
            for (int j = 0; j < n; ++j)
            {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << "]" << std::endl;
        }
    }
};

int main()
{
    // Number of vertices
    int n = 4;
    // Create a graph with 4 vertices
    AdjacencyMatrixGraph Graph(n);

    // Adding the specified edges in the graph
    Graph.addEdge(0, 1);
    Graph.addEdge(0, 2);
    Graph.addEdge(1, 3);
    Graph.addEdge(2, 3);

    Graph.printMatrix();
    return 0;
}