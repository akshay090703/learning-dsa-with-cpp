#include <bits/stdc++.h>
using namespace std;

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

    void unionByRank(int u, int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);
        int ranku = rank[pu];
        int rankv = rank[pv];

        if (pu == pv)
            return;

        if (ranku == rankv)
        {
            rank[pu] = rankv + 1;
            parent[pv] = pu;
        }
        else if (ranku > rankv)
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv;
        }
    }

    int findUParent(int u)
    {
        if (parent[u] == u)
            return u;

        // Path Compression
        return parent[u] = findUParent(parent[u]);
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findUParent(3) == ds.findUParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUParent(3) == ds.findUParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";
    return 0;
}