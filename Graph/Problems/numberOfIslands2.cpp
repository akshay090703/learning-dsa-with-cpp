//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findingUlParent(int u)
    {
        if (u == parent[u])
            return u;

        return parent[u] = findingUlParent(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        int ulParentU = findingUlParent(u);
        int ulParentV = findingUlParent(v);

        if (ulParentU == ulParentV)
            return;

        int rankU = rank[ulParentU];
        int rankV = rank[ulParentV];

        if (rankU == rankV)
        {
            rank[ulParentU] = rankV + 1;
            parent[ulParentV] = ulParentU;
        }
        else if (rankU > rankV)
        {
            parent[ulParentV] = ulParentU;
        }
        else
        {
            parent[ulParentU] = ulParentV;
        }
    }
};

class Solution
{
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        int k = operators.size();

        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        DisjointSet ds(n * m);
        vector<int> islands(k);

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, -1, 0, 1};

        int currIslands = 0;
        for (int i = 0; i < k; i++)
        {
            int row = operators[i][0];
            int col = operators[i][1];
            int currNode = row * m + col;

            if (!isVisited[row][col])
            {
                isVisited[row][col] = true;
                currIslands++;

                for (int i = 0; i <= 3; i++)
                {
                    int nRow = row + dRow[i];
                    int nCol = col + dCol[i];

                    if (nRow >= 0 and nCol >= 0 and nRow < n and nCol < m and isVisited[nRow][nCol])
                    {
                        int neighbourNode = nRow * m + nCol;

                        if (ds.findingUlParent(currNode) != ds.findingUlParent(neighbourNode))
                        {
                            ds.unionByRank(currNode, neighbourNode);
                            currIslands--;
                        }
                    }
                }
            }

            islands[i] = currIslands;
        }

        return islands;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> a;

        for (int i = 0; i < k; i++)
        {
            vector<int> temp;
            for (int j = 0; j < 2; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.numOfIslands(n, m, a);

        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
}

// } Driver Code Ends