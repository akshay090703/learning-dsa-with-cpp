#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

void dfs(int node, int parent, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &disc, vector<int> &low, vector<bool> &artiPoints, int &timer)
{
    visited[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for (auto neighbour : adj[node])
    {
        if (neighbour == parent)
            continue;

        if (!visited[neighbour])
        {
            dfs(neighbour, node, adj, visited, disc, low, artiPoints, timer);
            low[node] = min(low[node], low[neighbour]);

            // check if articulation point or not
            if (low[neighbour] >= disc[node] && parent != -1)
            {
                artiPoints[node] = true;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], disc[neighbour]);
        }

        // for 1st node
        if (parent == -1 and child > 1)
        {
            artiPoints[node] = true;
        }
    }
}

// Time Complexity and Space Complexity will be same as dfs
// Time : O(V+E)
// Space : O(V)
vector<bool> articulationPoints(vector<vector<int>> &edges, int v, int e)
{
    // adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v); // discovery time
    vector<int> low(v);  // lowest time
    unordered_map<int, bool> visited;
    vector<bool> artiPoints(v, false);

    for (int i = 0; i < v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    // dfs
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1, adj, visited, disc, low, artiPoints, timer);
        }
    }

    cout << "Articulation Points are as follows: " << endl;
    for (int i = 0; i < v; i++)
    {
        if (artiPoints[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return artiPoints;
}

int main()
{

    return 0;
}