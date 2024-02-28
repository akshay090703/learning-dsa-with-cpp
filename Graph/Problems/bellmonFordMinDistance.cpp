#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Time Complexity -> O(n^2)
// Space Complexity -> O(n)
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e9); // Distance from source to all other vertices

    dist[src] = 0;

    // |V-1| times applying formula
    for (int i = 1; i <= n - 1; i++)
    {
        // traverse on edge list
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 and (dist[u] + wt) < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // check for negative cycle
    // applying formula one more time and checking if anything changes
    bool flag = false;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e9 and (dist[u] + wt) < dist[v])
        {
            flag = true;
        }
    }

    // there is a negative cycle
    if (flag)
    {
        return -1;
    }

    // the minimum distance from source to destination is stored in dist[dest]
    // if dist[dest] = 1e9 then there is no path from source to destination
    return dist[dest];
}

int main()
{
}