#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<pair<double, pair<int, int>>> vp(n); // {value-to-weight ratio, {price, weight}}
    cout << "Enter price and weight for each item: " << endl;
    for (auto &i : vp) {
        cin >> i.second.first >> i.second.second;
        i.first = i.second.first * 1.0 / i.second.second; // Value-to-weight ratio
    }

    // Sort items by value-to-weight ratio in descending order
    sort(vp.begin(), vp.end(), [](auto &a, auto &b) {
        return a.first > b.first;
    });

    // Print the sorted items
    cout << "Sorted items (ratio price weight):" << endl;
    for (auto &i : vp) {
        cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
    }

    int m;
    cout << "Enter the maximum weight capacity: ";
    cin >> m;

    int totalWeight = 0;
    double totalValue = 0.0;
    vector<pair<double, pair<int, int>>> solutionVector; // Fractional solution vector

    for (int i = 0; i < n; ++i) {
        if (totalWeight + vp[i].second.second <= m) {
            // Take the entire item
            totalWeight += vp[i].second.second;
            totalValue += vp[i].second.first;
            solutionVector.push_back({1.0, {vp[i].second.first, vp[i].second.second}});
        } else {
            // Take a fraction of the item
            double fraction = (m - totalWeight) * 1.0 / vp[i].second.second;
            totalWeight += fraction * vp[i].second.second;
            totalValue += fraction * vp[i].second.first;
            solutionVector.push_back({fraction, {vp[i].second.first, vp[i].second.second}});
            break;
        }
    }

    // Print the solution
    cout << "Solution (fraction price weight):" << endl;
    for (auto &i : solutionVector) {
        cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
    }

    cout << "Total value: " << totalValue << endl;

    return 0;
}
