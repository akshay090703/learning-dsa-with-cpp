//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int timer = 0;

    void dfs(vector<int> adj[], vector<bool> &isVisited, vector<int> &discTime,
             vector<int> &lowestTime, vector<vector<int>> &bridges, int node, int parent)
    {

        isVisited[node] = true;
        discTime[node] = lowestTime[node] = timer;
        timer++;

        for (auto neighbour : adj[node])
        {
            if (neighbour == parent)
                continue;

            if (!isVisited[neighbour])
            {
                dfs(adj, isVisited, discTime, lowestTime, bridges, neighbour, node);
                lowestTime[node] = min(lowestTime[node], lowestTime[neighbour]);

                // if the lowest possible arrival time of child node is lesser than the
                // discovery time of parent, then it is surely a bridge
                if (lowestTime[neighbour] > discTime[node])
                {
                    if (neighbour >= node)
                    {
                        bridges.push_back({node, neighbour});
                    }
                    else
                    {
                        bridges.push_back({neighbour, node});
                    }
                }
            }
            else
            {
                lowestTime[node] = min(lowestTime[node], lowestTime[neighbour]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int v, vector<int> adj[])
    {
        vector<bool> isVisited(v, false);

        // discovery time of each node
        vector<int> discTime(v);

        // lowest possible arrival time of each node
        vector<int> lowestTime(v);

        vector<vector<int>> bridges;
        dfs(adj, isVisited, discTime, lowestTime, bridges, 0, -1);

        sort(bridges.begin(), bridges.end());
        return bridges;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>> ans = obj.criticalConnections(V, adj);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}
// } Driver Code Ends