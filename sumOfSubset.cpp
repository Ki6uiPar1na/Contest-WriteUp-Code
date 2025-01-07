#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> solutions;
// Function to find subsets that sum to m using backtracking
void subsetSum(vector<int>& arr, int n, int m, vector<int>& current, int index) {
    // Base case: If the current sum equals the target
    int sum = accumulate(current.begin(), current.end(), 0);
    if (sum == m) {
        solutions.push_back(current);
        return;
    }

    // If index exceeds or current sum exceeds m, stop exploring
    if (index >= n || sum > m) {
        return;
    }

    // Include the current element in the subset
    current.push_back(arr[index]);
    subsetSum(arr, n, m, current, index + 1);

    // Backtrack: Remove the last element and try without it
    current.pop_back();
    subsetSum(arr, n, m, current, index + 1);
}

int main() {
    int n, m;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target sum (m): ";
    cin >> m;

    vector<int> current;          // Current subset being explored

    // Backtracking to find all subsets that sum to m
    subsetSum(arr, n, m, current, 0);

    // Print the solutions
    cout << "Subsets that sum to " << m << " are:" << endl;
    for (auto& subset : solutions) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
