#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // A large value to represent infinity

void floydWarshall(int graph[][100], int V) {  // Maximum vertices assumed as 100
    // Distance matrix initialized with the input graph
    int dist[100][100];  // Same size as graph

    // Initialize the distance matrix with the graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < V; k++) { // Intermediate vertex
        for (int i = 0; i < V; i++) { // Source vertex
            for (int j = 0; j < V; j++) { // Destination vertex
                // Update the shortest distance if a shorter path is found via vertex k
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print the resulting shortest distances
    cout << "All Pairs Shortest Path Matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    // Initialize the graph with INF for no direct edge and 0 for self-loops
    int graph[100][100];  // Maximum vertices assumed as 100
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = INF;
        }
        graph[i][i] = 0;  // Distance from a vertex to itself is 0
    }

    cout << "Enter edges (u, v, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1][v - 1] = w;
    }

    floydWarshall(graph, V);

    return 0;
}
