//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    const int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<long long, long long>>> adjList(n);
        for (int i = 0; i < roads.size(); i++)
        {
            long long u = roads[i][0];
            long long v = roads[i][1];
            long long time = roads[i][2];

            adjList[u].push_back({v, time});
            adjList[v].push_back({u, time});
        }

        // minimum time : node
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> minHeap;
        // minimum time : freq
        vector<pair<long long, long long>> dist(n, {LLONG_MAX, 0});

        minHeap.push({0, 0});
        dist[0] = {0, 1};
        while (!minHeap.empty())
        {
            long long minTime = minHeap.top().first;
            long long node = minHeap.top().second;
            minHeap.pop();

            for (auto neighbour : adjList[node])
            {
                long long v = neighbour.first;
                long long nextTime = neighbour.second;
                long long newTime = minTime + nextTime;

                if (dist[v].first > newTime)
                {
                    dist[v] = {newTime, dist[node].second};
                    minHeap.push({newTime, v});
                }
                else if (dist[v].first == newTime)
                {
                    dist[v].second = (dist[v].second + dist[node].second) % MOD;
                }
            }
        }

        return dist[n - 1].second;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends