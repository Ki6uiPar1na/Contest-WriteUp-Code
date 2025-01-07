#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10, INF = 9999;
int cost[N][N];
int t[N][3];

void Prims(int n, int k, int l)
{
    int near[n + 10];
    int mincost = cost[k][l];
    t[1][1] = k;
    t[1][2] = l;
    for (int i = 1; i <= n; ++i)
    {
        if (cost[i][l] < cost[i][k])
            near[i] = l;
        else
            near[i] = k;
    }
    near[k] = 0;
    near[l] = 0;
    for (int i = 2; i < n; i++)
    {
        int j = 0;
        int near_cost = INF;
        for (int v = 1; v <= n; ++v)
        {
            if (near[v] != 0 && cost[v][near[v]] < near_cost)
            {
                near_cost = cost[v][near[v]];
                j = v;
            }
        }
        t[i][1] = j;
        t[i][2] = near[j];
        mincost += cost[j][near[j]];
        near[j] = 0;
        for (int k = 1; k <= n; ++k)
        {
            if (near[k] != 0 && cost[k][near[k]] > cost[k][j])
                near[k]=j;
        }
    }
    cout<<"Minimum cost is: "<< mincost<<endl;
    cout<<"Edges taken: "<<endl;
    for(int i=1; i<n; ++i)
    {
        int v1=t[i][1];
        int v2=t[i][2];
        cout<<"Vertices: "<<v1<<" and "<<v2<<", Cost: "<< cost[v1][v2]<<endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int mn = INT_MAX, k, l;
    for (int i = 0; i < m; ++i)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        cost[v1][v2] = w;
        cost[v2][v1] = w;
        if (w < mn)
        {
            mn = w;
            k = v1;
            l = v2;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    cout<<"The Graph in adjaceny matrix represntation: "<<endl;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j) 
        {
            if(cost[i][j]==INF) cout<<"I ";
            else cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }

    Prims(n, k, l);
}