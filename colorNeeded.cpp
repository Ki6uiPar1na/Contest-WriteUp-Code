#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 10; // Maximum number of vertices

// Function to print the solution (coloring of vertices)
void printSolution(int colors[], int V) {
    cout << "Solution: ";
    for (int i = 0; i < V; i++) {
        cout << colors[i] << " ";
    }
    cout << endl;
}

// Function to check if it's safe to assign color c to vertex v
bool isSafe(int v, int graph[MAX_V][MAX_V], int colors[], int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && colors[i] == c) // Adjacent vertex has the same color
            return false;
    }
    return true;
}

// Backtracking function to find the minimum number of colors needed
bool solveGraphColoring(int graph[MAX_V][MAX_V], int M, int V, int v, int colors[]) {
    if (v == V) { // All vertices are colored
        return true;
    }

    for (int c = 1; c <= M; c++) { // Try each color from 1 to M
        if (isSafe(v, graph, colors, c, V)) {
            colors[v] = c; // Assign color
            if (solveGraphColoring(graph, M, V, v + 1, colors)) // Recur for the next vertex
                return true;
            colors[v] = 0; // Backtrack
        }
    }
    return false; // No solution found with M colors
}

// Function to find the minimum number of colors required for graph coloring
int graphColoring(int graph[MAX_V][MAX_V], int V) {
    int colors[MAX_V] = {0}; // To store the color assigned to each vertex
    int result = 0; // To store the minimum number of colors needed

    // Try for each number of colors starting from 1 up to V
    for (int m = 1; m <= V; m++) {
        if (solveGraphColoring(graph, m, V, 0, colors)) {
            result = m;
            printSolution(colors, V); // Print the solution vector
            break;
        }
    }

    return result;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    int graph[MAX_V][MAX_V] = {0}; // Adjacency matrix representation of the graph

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // Undirected graph
    }

    int minColors = graphColoring(graph, V);

    cout << "Minimum number of colors needed: " << minColors << endl;

    return 0;
}
