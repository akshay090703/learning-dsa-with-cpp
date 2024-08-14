//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet
{
    vector<int> size, rank, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n, 1);
        rank.resize(n, 0);
        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUlParent(int u)
    {
        if (u == parent[u])
            return u;

        return parent[u] = findUlParent(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        int parentU = findUlParent(u);
        int parentV = findUlParent(v);

        if (parentU == parentV)
            return;

        int rankU = rank[parentU];
        int rankV = rank[parentV];

        if (rankU == rankV)
        {
            parent[parentV] = parentU;
            rank[parentU] = rank[parentV] + 1;
        }
        else if (rankU > rankV)
        {
            parent[parentV] = parentU;
        }
        else
        {
            parent[parentU] = parentV;
        }
    }

    void unionBySize(int u, int v)
    {
        int parentU = findUlParent(u);
        int parentV = findUlParent(v);

        if (parentU == parentV)
            return;

        int sizeU = size[parentU];
        int sizeV = size[parentV];

        if (sizeU >= sizeV)
        {
            size[parentU] += size[parentV];
            parent[parentV] = parentU;
        }
        else
        {
            size[parentV] += size[parentU];
            parent[parentU] = parentV;
        }
    }
};

class Solution
{
public:
    int minimumConnections(int n, vector<vector<int>> &connections)
    {
        DisjointSet ds(n);

        int connection = 0;
        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];

            if (ds.findUlParent(v) != ds.findUlParent(u))
            {
                connection++;
                // ds.unionByRank(u, v);
                ds.unionBySize(u, v);
            }
        }

        int extraConnections = connections.size() - connection;
        int disconnected = n - (connection + 1);

        if (extraConnections >= disconnected)
            return disconnected;

        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<vector<int>> connections(m, vector<int>(2));
        for (auto &j : connections)
            cin >> j[0] >> j[1];
        Solution s;
        cout << s.minimumConnections(n, connections) << endl;
    }
    return 0;
}
// } Driver Code Ends