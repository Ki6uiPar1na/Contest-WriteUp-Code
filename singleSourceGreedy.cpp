#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // A large value to represent infinity

void dijkstra(vector<vector<pair<int, int>>> &adj, int V, int src) {
    // Priority queue to store (distance, vertex) pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INF); // Distance vector initialized with infinity

    // Start from the source vertex
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Visit all adjacent vertices of u
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // If a shorter path to v is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest distances from the source
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << i << "\tINF" << endl;
        else
            cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    int V, E, src;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V); // Adjacency list

    cout << "Enter edges (u, v, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // If the graph is undirected
    }

    cout << "Enter the source vertex: ";
    cin >> src;

    dijkstra(adj, V, src);

    return 0;
}