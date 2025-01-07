#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 4;

void printSolution(vector<int>& board, int n) {
    cout << "Solution:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<int>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||                   // Same column
            board[i] - i == col - row ||         // Same diagonal (top-left to bottom-right)
            board[i] + i == col + row)           // Same diagonal (top-right to bottom-left)
            return false;
    }
    return true;
}

void solveNQueens(int n, int row, vector<int>& board, vector<vector<int>>& solutions) {
    if (row == n) {
        solutions.push_back(board);             // Store the solution
        printSolution(board, n);                // Print the solution
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row] = col;                   // Place the queen
            solveNQueens(n, row + 1, board, solutions); // Solve for the next row
            board[row] = -1;                    // Backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of n (1 <= n <= 4): ";
    cin >> n;

    if (n > MAX_N || n < 1) {
        cout << "Invalid input. Please enter a value between 1 and 4." << endl;
        return 0;
    }

    vector<int> board(n, -1);                   // Initialize the board
    vector<vector<int>> solutions;             // Store all solutions

    solveNQueens(n, 0, board, solutions);

    cout << "Total Solutions: " << solutions.size() << endl;

    return 0;
}
