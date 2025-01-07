#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<pair<int, int>> vp(n);
    cout << "Enter the profit and deadline: \n";
    int mxDeadline = INT_MIN;
    for(auto &i : vp){
        cin >> i.first >> i.second;
        mxDeadline = max(mxDeadline, i.second);
    }
    vector<int> dp(mxDeadline + 1, -1);
    for(auto &i : vp){
        cout << i.first << ' ' << i.second << endl;
    }

    vector<int> solutionVector;
    int profit = 0;
    cout << "Selected tasks: ";
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= vp[i].second; j++){
            if(dp[j] == -1){
                dp[j] = 1;
                profit += vp[i].first;
                cout << vp[i].first << ' ';
                break;
            }
        }
    }
    cout << endl;
    cout << "Total profit: " << profit << endl;
}