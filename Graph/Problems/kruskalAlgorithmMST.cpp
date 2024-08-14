//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    class DisjointSet
    {
        vector<int> rank, parent;

    public:
        DisjointSet(int n)
        {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);

            for (int i = 0; i <= n; i++)
            {
                parent[i] = i;
            }
        }

        int findUlParent(int u)
        {
            if (parent[u] == u)
                return u;

            return parent[u] = findUlParent(parent[u]);
        }

        void unionByRank(int u, int v)
        {
            int ulParentU = findUlParent(u);
            int ulParentV = findUlParent(v);

            int rankParentU = rank[ulParentU];
            int rankParentV = rank[ulParentV];

            if (ulParentU == ulParentV)
                return;

            if (rankParentU == rankParentV)
            {
                parent[ulParentV] = ulParentU;
                rank[ulParentU] = rank[ulParentV] + 1;
            }
            else if (rankParentU > rankParentV)
            {
                parent[ulParentV] = ulParentU;
            }
            else
            {
                parent[ulParentU] = ulParentV;
            }
        }
    };

    // Using Kruskal's Algorithm
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>> edges;
        for (int i = 0; i < V; i++)
        {
            int u = i;
            for (int j = 0; j < adj[i].size(); j++)
            {
                int v = adj[i][j][0];
                int wt = adj[i][j][1];

                edges.push_back({wt, u, v});
                // would not make any difference as disjoint set will automatically discard it
                // edges.push_back({wt, v, u});
            }
        }

        DisjointSet ds(V);
        sort(edges.begin(), edges.end(), [](const auto &a, const auto &b)
             { return a[0] < b[0]; });

        int mstSum = 0;
        for (auto edge : edges)
        {
            if (ds.findUlParent(edge[1]) != ds.findUlParent(edge[2]))
            {
                ds.unionByRank(edge[1], edge[2]);
                mstSum += edge[0];
            }
        }

        return mstSum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends