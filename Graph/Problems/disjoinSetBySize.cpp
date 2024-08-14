#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulParentU = findUlParent(u);
        int ulParentV = findUlParent(v);

        if (ulParentU == ulParentV)
            return;

        if (size[ulParentU] >= size[ulParentV])
        {
            size[ulParentU] += size[ulParentV];
            parent[ulParentV] = ulParentU;
        }
        else
        {
            size[ulParentV] += size[ulParentU];
            parent[ulParentU] = ulParentV;
        }
    }

    int findUlParent(int u)
    {
        if (parent[u] == u)
            return u;

        // Path Compression
        return parent[u] = findUlParent(parent[u]);
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUlParent(3) == ds.findUlParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUlParent(3) == ds.findUlParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";
    return 0;

    return 0;
}