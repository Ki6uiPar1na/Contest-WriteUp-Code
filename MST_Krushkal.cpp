#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int cost[N][N];
int parent[N];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionset(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int n)
{

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    int count = 0, mincost=0;

    cout <<"Edges taken: " <<endl;
    while (count < n - 1)
    {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (find(i) != find(j) && cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        unionset(a, b);
        cout << "Vertices: " << a << " " << b << ", Cost: " << cost[a][b] <<endl;
        mincost += min;
        count++;
    }
    cout << "Minimum cost is " << mincost << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        cost[v1][v2] = w;
        cost[v2][v1] = w;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }
    kruskal(n);
    return 0;
}