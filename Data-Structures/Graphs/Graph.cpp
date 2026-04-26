#include <iostream>

// GRAPH - Data Structure

// A graph is a non-linear data structure made up of vertices (nodes) and edges (connections) that represent relationships between objects. Unlike arrays or linked lists, graphs do not follow a sequential order.

/*
    Example Graph (Undirected, unweighted, cycled graph)

          2 --- 0
        /   \
       1 --- 3

    * Vertices: Vertices are the fundamental units of the graph. Sometimes, vertices are also known as vertex or nodes. Every node/vertex can be labeled or unlabelled.
    * Edges: Edges are drawn or used to connect two nodes of the graph. It can be ordered pair of nodes in a directed graph. Edges can connect any two nodes in any possible way. There are no rules. Sometimes, edges are also known as arcs. Every edge can be labelled/unlabelled.


    GRAPH Types:

        Based on weight :
            1. Weighted Graphs
                A  weighted graph is a graph where each edge has a number (weight) that represents distance, cost, or time.
            2. Unweighted Graphs
                An unweighted graph is a graph where all edges are treated equally, with no extra values like distance or cost.

        Based on Edge Direction:
            3. Undirected Graph
                A graph in which edges do not have any direction. That is the nodes are unordered pairs in the definition of every edge.
            4. Directed Graph
                A graph in which edge has direction. That is the nodes are ordered pairs in the definition of every edge.

    Representation of Graph Data Structure:
        There are multiple ways to store a graph: The following are the most common representations.
        * Adjacency Matrix
        * Adjacency List

        -> Adjacency Matrix Representation of Graph Data Structure:
            In this method, the graph is stored in the form of the 2D matrix where rows and columns denote vertices. Each entry in the matrix represents the weight of the edge between those vertices.

        matrix[i][j] = 1 if there is an edge between vertex i and vertex j.
        matrix[i][j] = 0 if there is no edge.

        -> Adjacency List Representation of Graph:
            This graph is represented as a collection of array lists. There is an array of pointer which points to the edges connected to that vertex.
*/

int main()
{
    std::cout << "Graph Data Structure" << std::endl;

    return 0;
}