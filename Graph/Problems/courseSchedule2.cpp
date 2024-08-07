//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Using Kahn Algorithm
    vector<int> findOrder(int n, int m, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(n);
        for (auto link : prerequisites)
        {
            int u = link[1];
            int v = link[0];

            adj[u].push_back(v);
        }

        vector<int> inDegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                inDegree[adj[i][j]]++;
            }
        }

        vector<int> result;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
                result.push_back(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto neighbour : adj[node])
            {
                inDegree[neighbour]--;

                if (inDegree[neighbour] == 0)
                {
                    q.push(neighbour);
                    result.push_back(neighbour);
                }
            }
        }

        if (result.size() != n)
            return {};

        return result;
    }

    // Using DFS (Topological sort)
    // bool dfs(vector<vector<int>> &adj, vector<bool> &isVisited, vector<bool> &currPath, stack<int> &st, int node) {
    //     isVisited[node] = true;
    //     currPath[node] = true;

    //     for(auto neighbour : adj[node]) {
    //         if(!isVisited[neighbour]) {
    //             if(dfs(adj, isVisited, currPath, st, neighbour)) return true;
    //         } else if(currPath[neighbour]) return true;
    //     }

    //     currPath[node] = false;
    //     st.push(node);
    //     return false;
    // }

    // vector<int> findOrder(int n, int m, vector<vector<int>>& prerequisites) {
    //     vector<vector<int>> adj(n);
    //     for(auto link : prerequisites) {
    //         int u = link[1];
    //         int v = link[0];

    //         adj[u].push_back(v);
    //     }

    //     vector<bool> isVisited(n, false);
    //     vector<bool> currPath(n, false);
    //     stack<int> st;
    //     for(int i = 0; i<n; i++) {
    //         if(!isVisited[i])
    //             dfs(adj, isVisited, currPath, st, i);
    //     }

    //     if(st.size() != n) return {};

    //     vector<int> result;
    //     while(!st.empty()) {
    //         result.push_back(st.top());
    //         st.pop();
    //     }

    //     return result;
    // }
};

//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<int> adj[])
{
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            prerequisites.push_back({u, v});
        }

        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);

        Solution obj;
        vector<int> res = obj.findOrder(n, m, prerequisites);
        if (!res.size())
            cout << "No Ordering Possible" << endl;
        else
            cout << check(n, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends