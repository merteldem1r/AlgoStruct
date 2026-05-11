#include <iostream>

// Dijkstra's Algorithm - Shortest Path Algorithm
// Given a weighted undirected graph and a source vertex src. We need to find the shortest path distances from the source vertex to all other vertices in the graph.
// Author: Mert Eldemir

std::vector<int> dijkstra(std::vector<std::vector<std::pair<int, int>>> &adj, const int src) // Time: O((V+E) * logV) Space: O(V + E)
{
    // Min-heap (priority queue) storing distance and node
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    const int nodeCount = adj.size();
    std::vector<int> dist(nodeCount, INT_MAX);

    // Distance from source to itself is 0
    dist[src] = 0;
    pq.emplace(0, src); // pair = {distance, node}

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        // skip distance that not shortest latest one
        if (d > dist[u])
            continue;

        // explore all neighbours of current node
        // nv = neighbour vertex, nvd = neighbour vertex distance
        for (auto &[nv, nvd] : adj[u])
        {
            // if found a shorter path to nv through u, update it
            if (dist[u] + nvd < dist[nv])
            {
                dist[nv] = dist[u] + nvd;
                pq.emplace(dist[nv], nv);
            }
        }
    }

    return dist;
}

int main()
{
    int src = 0;

    std::vector<std::vector<std::pair<int, int>>> adj(5);
    adj[0] = {{1, 4}, {2, 8}};
    adj[1] = {{0, 4}, {4, 6}, {2, 3}};
    adj[2] = {{0, 8}, {3, 2}, {1, 3}};
    adj[3] = {{2, 2}, {4, 10}};
    adj[4] = {{1, 6}, {3, 10}};

    std::vector<int> res = dijkstra(adj, src);

    for (int d : res)
        std::cout << d << " ";

    return 0;
}