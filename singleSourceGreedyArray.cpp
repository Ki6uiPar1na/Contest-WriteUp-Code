#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // A large value to represent infinity
const int MAX_V = 100; // Maximum number of vertices

void dijkstra(int graph[MAX_V][MAX_V], int V, int src) {
    int dist[MAX_V]; // Distance array
    bool visited[MAX_V] = {false}; // Visited array

    // Initialize distances with infinity and source distance with 0
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        // Find the vertex with the minimum distance that hasn't been visited
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        // If no valid vertex is found, break (remaining vertices are unreachable)
        if (u == -1) break;

        // Mark the chosen vertex as visited
        visited[u] = true;

        // Update the distances of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances from the source
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << i + 1 << "\tINF" << endl; // Output vertex numbers as 1-based
        else
            cout << i + 1 << "\t" << dist[i] << endl;
    }
}

int main() {
    int V, E, src;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    int graph[MAX_V][MAX_V]; // Adjacency matrix

    // Initialize the graph with 0 (no edge)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    cout << "Enter edges (u, v, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1][v - 1] = w; // Convert to 0-based indexing for internal representation
    }

    cout << "Enter the source vertex: ";
    cin >> src;

    dijkstra(graph, V, src - 1); // Convert source to 0-based indexing

    return 0;
}
