//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet
{
public:
    vector<int> size, parent;
    int maxSize = 0;

    DisjointSet(int n)
    {
        size.resize(n, 1);
        parent.resize(n);
        maxSize = 1;

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
        int ulParentU = findUlParent(u);
        int ulParentV = findUlParent(v);

        if (ulParentU == ulParentV)
            return;

        int sizeU = size[ulParentU];
        int sizeV = size[ulParentV];

        if (sizeU >= sizeV)
        {
            size[ulParentU] += sizeV;
            parent[ulParentV] = ulParentU;
            maxSize = max(maxSize, size[ulParentU]);
        }
        else
        {
            size[ulParentV] += sizeU;
            parent[ulParentU] = ulParentV;
            maxSize = max(maxSize, size[ulParentV]);
        }
    }

    int getMaxSize()
    {
        return this->maxSize;
    }
};

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, -1, 0, 1};
        DisjointSet ds(n * n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int currNode = i * n + j;

                    for (int k = 0; k < 4; k++)
                    {
                        int nRow = i + dRow[k];
                        int nCol = j + dCol[k];

                        if (nRow >= 0 and nRow < n and nCol >= 0 and nCol < n and grid[nRow][nCol] == 1)
                        {
                            int adjNode = nRow * n + nCol;
                            if (ds.findUlParent(adjNode) != ds.findUlParent(currNode))
                            {
                                ds.unionBySize(adjNode, currNode);
                            }
                        }
                    }
                }
            }
        }

        int maxIsland = ds.getMaxSize();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    int currNode = i * n + j;
                    unordered_set<int> seenParents;
                    int potentialSize = 1;

                    for (int k = 0; k < 4; k++)
                    {
                        int nRow = i + dRow[k];
                        int nCol = j + dCol[k];

                        if (nRow >= 0 and nRow < n and nCol >= 0 and nCol < n and grid[nRow][nCol] == 1)
                        {
                            int adjNode = nRow * n + nCol;
                            int ulParent = ds.findUlParent(adjNode);

                            if (seenParents.find(ulParent) == seenParents.end())
                            {
                                seenParents.insert(ulParent);
                                potentialSize += ds.size[ulParent];
                            }
                        }
                    }

                    maxIsland = max(maxIsland, potentialSize);
                }
            }
        }

        return maxIsland;
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
        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        Solution ob;
        cout << ob.largestIsland(grid) << endl;
    }
    return 0;
}

// } Driver Code Ends