//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Kahn's Algo(BFS)
    bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
    {
        vector<vector<int>> adj(N);
        for (int i = 0; i < P; i++)
        {
            int u = prerequisites[i].second;
            int v = prerequisites[i].first;

            adj[u].push_back(v);
        }

        vector<int> inDegree(N, 0);
        for (int i = 0; i < N; i++)
        {
            for (auto j : adj[i])
            {
                inDegree[j]++;
            }
        }

        queue<int> q;
        vector<int> topoSort;
        for (int i = 0; i < N; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
                topoSort.push_back(i);
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
                    topoSort.push_back(neighbour);
                }
            }
        }

        return topoSort.size() == N;
    }

    // DFS Approach
    //     bool dfs(vector<vector<int>> &adj, vector<bool> &isVisited, vector<bool> &currPath, vector<int> &result, int node) {
    //         isVisited[node] = true;
    //         currPath[node] = true;

    //         for(auto neighbour : adj[node]) {
    //             if(!isVisited[neighbour]) {
    //                 if(dfs(adj, isVisited, currPath, result, neighbour)) return true;
    //             } else if(currPath[neighbour]) return true;
    //         }

    //         currPath[node] = false;
    //         result.push_back(node);
    //         return false;
    //     }

    // 	// DFS approach(topological sort)
    // 	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
    // 	    vector<vector<int>> adj(N);
    // 	    for(int i = 0; i<P; i++) {
    // 	        int u = prerequisites[i].second;
    // 	        int v = prerequisites[i].first;

    // 	        adj[u].push_back(v);
    // 	    }

    // 	    vector<bool> isVisited(N, false);
    // 	    vector<bool> currPath(N, false);
    // 	    vector<int> result;
    // 	    for(int i = 0; i<N; i++) {
    // 	        if(!isVisited[i]) {
    // 	            dfs(adj, isVisited, currPath, result, i);
    // 	        }
    // 	    }

    // 	    return result.size() == N;
    // 	}
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends