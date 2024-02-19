#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

// Time Complexity -> O(n^2)
// Space Complexity -> O(n + e)
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // creating adjacency list
    // starting node: {adjacent node, weight}
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int weight = g[i].second;

        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
    }

    // denoting the node with the index of the vector
    vector<int> key(n + 1);    // kinda like the minimum distance from each node
    vector<bool> mst(n + 1);   // kinda like the isVisited structure
    vector<int> parent(n + 1); // parent of the nodes

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // Algorithm
    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        // finding the minimum node
        // (can be optimized using priority queue(min heap))
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false and key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // mark min node true
        mst[u] = true;

        // check its adjacent nodes
        for (auto it : adjList[u])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false and w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    // here all nodes start with 1
    // parent of 1 is -1
    for (int i = 2; i <= n; i++)
    {
        result.push_back(make_pair(make_pair(parent[i], i), key[i]));
    }

    return result;
}

int main()
{

    return 0;
}