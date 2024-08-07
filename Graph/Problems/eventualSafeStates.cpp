//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isCycleDFS(vector<int> adj[], vector<int> &isVisited, int node)
    {
        // marking the node visited and 2 for the curr path
        isVisited[node] = 2;

        for (auto neighbour : adj[node])
        {
            if (isVisited[neighbour] == 2)
            {
                return true;
            }
            else if (isVisited[neighbour] == 0)
            {
                if (isCycleDFS(adj, isVisited, neighbour))
                    return true;
            }
        }

        isVisited[node] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> safeNodes;

        // 0 -> not visited
        // 1 -> visited
        // 2 -> visited and in the same path
        vector<int> isVisited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (isVisited[i] == 0)
            {
                isCycleDFS(adj, isVisited, i);
            }
        }

        for (int i = 0; i < V; i++)
        {
            // all those nodes that are not safe would be marked as 2 according to our DFS
            if (isVisited[i] == 1)
                safeNodes.push_back(i);
        }

        return safeNodes;
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
        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends