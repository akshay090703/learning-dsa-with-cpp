//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct DisjointSet
{
    vector<int> size, parent;

    DisjointSet(int n)
    {
        size.resize(n, 1);
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

    void unionBySize(int u, int v)
    {
        int ulParU = findUlParent(u);
        int ulParV = findUlParent(v);

        if (ulParU == ulParV)
            return;

        int sizeU = size[ulParU];
        int sizeV = size[ulParV];

        if (sizeU >= sizeV)
        {
            size[ulParU] += sizeV;
            parent[ulParV] = ulParU;
        }
        else
        {
            size[ulParV] += sizeU;
            parent[ulParU] = ulParV;
        }
    }
};

class Solution
{
public:
    int maxRemove(vector<vector<int>> &stones, int n)
    {
        int maxRow = 0, maxCol = 0;
        for (int i = 0; i < n; i++)
        {
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }

        DisjointSet ds(maxRow + maxCol + 2);
        for (int i = 0; i < n; i++)
        {
            int row = stones[i][0];
            // shifting of node numbers to accomodate col number
            int col = stones[i][1] + maxRow + 1;

            ds.unionBySize(row, col);
        }

        int components = 0;
        for (int i = 0; i < ds.parent.size(); i++)
        {
            // if the node is the parent of itself and its size is greater than one, then it is a component
            if (ds.parent[i] == i and ds.size[i] > 1)
            {
                components++;
            }
        }

        return n - components;
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
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i)
        {
            vector<int> temp;
            for (int i = 0; i < 2; ++i)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends