#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &isVisited)
{
    isVisited[node] = true;
    disc[node] = low[node] = timer++;

    for (auto neighbour : adj[node])
    {
        if (neighbour == parent)
            continue;

        if (!isVisited[neighbour])
        {
            dfs(neighbour, node, timer, disc, low, result, adj, isVisited);
            low[node] = min(low[node], low[neighbour]); // while returning -> backtracking

            // checking if edge is bridge, if it is a bridge, include in a vector
            if (low[neighbour] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else
        {
            // it is a fuckin back edge
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // needed data structures
    int timer = 0;       // updates in each call
    vector<int> disc(v); // discovery time of node
    vector<int> low(v);  // lowest time possible
    int parent = -1;
    unordered_map<int, bool> isVisited;

    for (int i = 0; i < v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> result;
    // dfs
    for (int i = 0; i < v; i++)
    {
        if (!isVisited[i])
        {
            dfs(i, parent, timer, disc, low, result, adj, isVisited);
        }
    }

    return result;
}

int main()
{

    return 0;
}