//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // TC -> O(E)
    // SC -> O(E) + O(V)
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<vector<pair<int, int>>> adjList(n);
        for (int i = 0; i < flights.size(); i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];

            adjList[u].push_back({v, cost});
        }

        // here we will store in the priority queue in order of
        // stops, cost, node as here the number of stops is more important
        // here we can also implement with the queue only as we will only proceed when stops is within K
        // this will also save the lograthmic time complexity
        // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        queue<pair<int, pair<int, int>>> q;
        vector<int> cost(n, INT_MAX);

        cost[src] = 0;
        // stops, cost, node
        q.push({0, {0, src}});

        int minCost = INT_MAX;
        while (!q.empty())
        {
            int stops = q.front().first;
            int currCost = q.front().second.first;
            int node = q.front().second.second;
            q.pop();

            if (node == dst)
                minCost = min(minCost, currCost);

            if (stops <= K)
            {
                for (auto neighbour : adjList[node])
                {
                    int v = neighbour.first;
                    int nextCost = neighbour.second;

                    int newCost = currCost + nextCost;
                    if (cost[v] > newCost)
                    {
                        cost[v] = newCost;
                        q.push({stops + 1, {newCost, v}});
                    }
                }
            }
        }

        return minCost == INT_MAX ? -1 : minCost;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        int edge;
        cin >> edge;
        vector<vector<int>> flights;

        for (int i = 0; i < edge; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }

        int src, dst, k;
        cin >> src >> dst >> k;
        Solution obj;
        cout << obj.CheapestFLight(n, flights, src, dst, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends