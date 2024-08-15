//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    int timer = 0;
    void dfs(vector<int> adj[], vector<bool> &isVisited, vector<int> &discTime,
             vector<int> &lowestTime, vector<bool> &mark, int node, int parent)
    {

        isVisited[node] = true;
        discTime[node] = lowestTime[node] = timer;
        timer++;

        int children = 0;
        for (auto neighbour : adj[node])
        {
            if (parent == neighbour)
                continue;

            if (!isVisited[neighbour])
            {
                dfs(adj, isVisited, discTime, lowestTime, mark, neighbour, node);
                lowestTime[node] = min(lowestTime[node], lowestTime[neighbour]);
                children++;

                if (lowestTime[neighbour] >= discTime[node] and parent != -1)
                {
                    mark[node] = true;
                }
            }
            else
            {
                lowestTime[node] = min(lowestTime[node], discTime[neighbour]);
            }
        }

        if (children > 1 and parent == -1)
            mark[node] = true;
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<bool> isVisited(V, false);

        // discovery time of the node
        vector<int> discTime(V);

        // lowest possible time to reach node
        vector<int> lowestTime(V);

        // will mark the articulation points
        vector<bool> mark(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!isVisited[i])
            {
                dfs(adj, isVisited, discTime, lowestTime, mark, i, -1);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; i++)
        {
            if (mark[i])
            {
                result.push_back(i);
            }
        }

        if (result.empty())
            return {-1};

        return result;
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
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends