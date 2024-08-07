//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(vector<int> graph[], vector<int> &color, int currNode, int parent)
    {
        int parentColor = -1;

        if (parent != -1)
            parentColor = color[parent];
        color[currNode] = parentColor == -1 ? 0 : !parentColor;

        int currColor = color[currNode];
        for (auto neighbour : graph[currNode])
        {
            if (color[neighbour] == -1)
            {
                if (!dfs(graph, color, neighbour, currNode))
                {
                    return false;
                }
            }
            else if (color[neighbour] == currColor)
                return false;
        }

        return true;
    }

    bool bfs(vector<int> adj[], vector<int> &color, int currNode)
    {
        queue<int> q;

        q.push(currNode);
        color[currNode] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            int currColor = color[node];
            int newColor = currColor == 0 ? 1 : 0;

            for (auto neighbour : adj[node])
            {
                if (color[neighbour] == -1)
                {
                    color[neighbour] = newColor;
                    q.push(neighbour);
                }
                else if (color[neighbour] == currColor)
                    return false;
            }
        }

        return true;
    }

    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                // if(!bfs(adj, color, i)) return false;
                if (!dfs(adj, color, i, -1))
                    return false;
            }
        }

        return true;
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
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends