//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void dfs(vector<vector<int>> &adjList, vector<bool> &isVisited, int node)
    {
        isVisited[node] = true;

        for (auto neighbour : adjList[node])
        {
            if (!isVisited[neighbour])
            {
                dfs(adjList, isVisited, neighbour);
            }
        }
    }

    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<vector<int>> adjList(V);
        for (int u = 0; u < V; u++)
        {
            for (int v = 0; v < V; v++)
            {
                if (adj[u][v] == 1 and u != v)
                {
                    adjList[u].push_back(v);
                    adjList[v].push_back(u);
                }
            }
        }

        int provinces = 0;
        vector<bool> isVisited(V, false);
        for (int node = 0; node < V; node++)
        {
            if (!isVisited[node])
            {
                dfs(adjList, isVisited, node);
                provinces++;
            }
        }

        return provinces;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, x;
        cin >> V;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.numProvinces(adj, V) << endl;
    }
    return 0;
}
// } Driver Code Ends