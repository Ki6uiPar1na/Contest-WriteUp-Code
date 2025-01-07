#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 10; // Maximum number of vertices

void printSolution(vector<int>& colors, int V) {
    cout << "Solution: ";
    for (int i = 0; i < V; i++) {
        cout << colors[i] << " ";
    }
    cout << endl;
}

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& colors, int c) {
    for (int i = 0; i < graph[v].size(); i++) {
        if (graph[v][i] == 1 && colors[i] == c) // Adjacent vertex has the same color
            return false;
    }
    return true;
}

void solveMColoring(vector<vector<int>>& graph, int M, int V, int v, vector<int>& colors, vector<vector<int>>& solutions) {
    if (v == V) { // All vertices are colored
        solutions.push_back(colors);
        printSolution(colors, V);
        return;
    }

    for (int c = 1; c <= M; c++) { // Try each color from 1 to M
        if (isSafe(v, graph, colors, c)) {
            colors[v] = c; // Assign color
            solveMColoring(graph, M, V, v + 1, colors, solutions); // Recur for the next vertex
            colors[v] = 0; // Backtrack
        }
    }
}

int main() {
    int V, E, M;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<vector<int>> graph(V, vector<int>(V, 0)); // Adjacency matrix representation

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u - 1][v - 1] = 1;
        graph[v - 1][u - 1] = 1; // Undirected graph
    }

    cout << "Enter the number of colors (M): ";
    cin >> M;

    vector<int> colors(V, 0); // To store the color assigned to each vertex
    vector<vector<int>> solutions; // To store all solutions

    solveMColoring(graph, M, V, 0, colors, solutions);

    cout << "Total Solutions: " << solutions.size() << endl;

    return 0;
}
