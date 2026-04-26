# Graph Data Structure in C++

Graphs are one of the most powerful and flexible data structures in computer science. They are used to model relationships, connectivity, dependencies, and flows between entities.

A graph is a non-linear data structure consisting of:

- Vertices (or nodes): entities
- Edges: relationships between entities

Unlike arrays, stacks, or linked lists, graphs do not assume a strict linear ordering.

## 1. Core Terminology

Given a graph G = (V, E):

- V is the set of vertices
- E is the set of edges

Common terms:

- Adjacent vertices: two vertices connected by an edge
- Degree (undirected): number of edges incident to a vertex
- In-degree (directed): number of incoming edges
- Out-degree (directed): number of outgoing edges
- Path: sequence of vertices where consecutive pairs are connected
- Simple path: path with no repeated vertices
- Cycle: path that starts and ends at the same vertex
- Connected graph: every vertex is reachable from every other vertex (undirected)
- Component: maximal connected subgraph

## 2. Example Graph (Undirected, Unweighted, Cyclic)

This is aligned with your Graph.cpp comment example:

      2 --- 0
    /   \

1 --- 3

- Vertices: {0, 1, 2, 3}
- Edges: {(2,0), (2,1), (2,3), (1,3), (0,2)}

Since the graph is undirected, (2,0) and (0,2) represent the same connection conceptually.

## 3. Main Graph Types

### 3.1 Based on Edge Direction

1. Undirected Graph

- Edges have no direction
- Edge (u, v) means both u -> v and v -> u are valid movements

2. Directed Graph (Digraph)

- Edges have direction
- Edge (u, v) means movement from u to v only

### 3.2 Based on Edge Weight

1. Unweighted Graph

- Every edge has equal cost (often treated as 1)
- Useful for minimum-hop problems

2. Weighted Graph

- Each edge carries weight (distance, time, cost, risk, etc.)
- Needed for shortest/cheapest path optimization

### 3.3 Other Common Classifications

- Cyclic vs Acyclic
- Simple graph (no parallel edges, no self-loops) vs multigraph
- Sparse graph: edges much fewer than V^2
- Dense graph: edges close to V^2
- DAG (Directed Acyclic Graph): very important for dependency modeling

## 4. Graph Representations

Your Graph.cpp comments mention the two most common representations: adjacency matrix and adjacency list.

### 4.1 Adjacency Matrix

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

### 4.2 Adjacency List

Use an array/vector where each index stores neighbors of that vertex.

Unweighted example:

- adj[u] contains all vertices v such that edge (u, v) exists

Weighted example:

- adj[u] contains pairs (v, w)

Advantages:

- O(V + E) memory for sparse graphs
- Iterating neighbors is efficient: O(deg(u))

Disadvantages:

- Edge existence check can be O(deg(u)) unless additional hashing is used

### 4.3 Quick Comparison

| Operation              | Adjacency Matrix | Adjacency List |
| :--------------------- | :--------------- | :------------- |
| Memory                 | O(V^2)           | O(V + E)       |
| Check edge (u, v)      | O(1)             | O(deg(u))      |
| Iterate neighbors of u | O(V)             | O(deg(u))      |
| Best for               | Dense graphs     | Sparse graphs  |

## 5. C++ Representation Examples

### 5.1 Adjacency List (Unweighted, Undirected)

```cpp
#include <iostream>
#include <vector>

class Graph {
private:
    int n;
    std::vector<std::vector<int>> adj;

public:
    Graph(int vertices) : n(vertices), adj(vertices) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // remove this line for directed graph
    }

    void print() const {
        for (int u = 0; u < n; ++u) {
            std::cout << u << ": ";
            for (int v : adj[u]) {
                std::cout << v << " ";
            }
            std::cout << "\n";
        }
    }
};
```

### 5.2 Adjacency Matrix (Unweighted)

```cpp
#include <iostream>
#include <vector>

class GraphMatrix {
private:
    int n;
    std::vector<std::vector<int>> m;

public:
    GraphMatrix(int vertices) : n(vertices), m(vertices, std::vector<int>(vertices, 0)) {}

    void addEdge(int u, int v, bool undirected = true) {
        m[u][v] = 1;
        if (undirected) {
            m[v][u] = 1;
        }
    }

    bool hasEdge(int u, int v) const {
        return m[u][v] != 0;
    }
};
```

## 6. Fundamental Graph Traversals

### 6.1 Breadth-First Search (BFS)

Idea:

- Explore layer by layer using a queue
- Excellent for shortest path in unweighted graphs

Time complexity:

- O(V + E) with adjacency list

Use cases:

- Minimum number of edges from source
- Connected component detection
- Level order exploration in networks

### 6.2 Depth-First Search (DFS)

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

## 7. Important Graph Algorithms (When to Use Which)

- BFS: shortest path in unweighted graph
- DFS: reachability, cycle detection, topology-like exploration
- Dijkstra: shortest path with non-negative weights
- Bellman-Ford: shortest path with possible negative weights
- Floyd-Warshall: all-pairs shortest path (small/medium dense graphs)
- Topological Sort: linear ordering of DAG dependencies
- Kruskal / Prim: minimum spanning tree in weighted undirected graph
- Union-Find (DSU): dynamic connectivity, cycle checks in undirected graphs

## 8. Real-World Applications

1. Maps and Navigation

- Cities/intersections as vertices
- Roads as weighted edges (distance or time)
- Uses Dijkstra/A\* style shortest path techniques

2. Social Networks

- Users are vertices
- Friend/follow relations are edges
- Community detection, influence analysis, recommendation systems

3. Computer Networks

- Routers/servers are vertices
- Physical/logical connections are edges
- Routing and traffic optimization

4. Dependency Management

- Packages/modules/tasks as vertices
- Dependency links as directed edges
- Topological sort determines valid build/install order

5. Recommendation Systems

- User-item bipartite graphs
- Similarity and relationship propagation methods

6. Web and Search Engines

- Web pages as vertices
- Hyperlinks as directed edges
- Ranking methods (for example, graph-based scoring)

7. Operating Systems and Scheduling

- Process dependencies as DAG
- Task planning and deadlock analysis

## 9. Common Mistakes and Practical Tips

- Mistake: using adjacency matrix for very sparse graph
  Tip: prefer adjacency list to save memory

- Mistake: forgetting both directions in undirected graph insertion
  Tip: always add u -> v and v -> u

- Mistake: not marking visited in BFS/DFS
  Tip: visited structure is mandatory to avoid infinite loops on cycles

- Mistake: applying Dijkstra with negative edges
  Tip: use Bellman-Ford for negative weights

- Mistake: assuming every graph is connected
  Tip: run traversal from all unvisited vertices to process all components

## 10. Complexity Summary (Adjacency List)

- Add edge: O(1) amortized
- BFS: O(V + E)
- DFS: O(V + E)
- Space: O(V + E)

For adjacency matrix:

- Space: O(V^2)
- Edge query: O(1)
- BFS/DFS neighbor scan cost includes O(V) per vertex

## 11. Graph vs Tree (Quick Contrast)

- Tree is a special graph:
  - Connected
  - Acyclic
  - Exactly V - 1 edges for V vertices

- Graph in general:
  - May be disconnected
  - May contain cycles
  - May be directed/weighted
