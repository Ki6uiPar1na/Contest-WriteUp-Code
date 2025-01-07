#include<bits/stdc++.h>
using namespace std;

pair<int, int> findMaxMin(vector<int> &v, int low, int high){
    if(low == high){
        return make_pair(v[low], v[low]);
    }
    if(low == high + 1){
        return make_pair(min(v[low], v[high]), max(v[low], v[high]));
    }

    int mid = low + (high - low) / 2;

    pair<int, int> leftMaxMin = findMaxMin(v, low, mid);
    pair<int, int> rightMaxMin = findMaxMin(v, mid + 1, high);

    return make_pair(min(leftMaxMin.first, rightMaxMin.first), max(leftMaxMin.second, rightMaxMin.second));
}


int main()
{
    int n; cin >> n; 
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    pair<int, int> maxMin = findMaxMin(v, 0, n - 1);
    cout << "Minimum: " << maxMin.first << endl;
    cout << "Maximum: " << maxMin.second << endl;
}