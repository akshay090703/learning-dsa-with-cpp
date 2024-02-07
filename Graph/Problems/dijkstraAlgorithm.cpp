#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <set>
// or we can use priority queue instead of set
using namespace std;

void shortestPath(int src, vector<int> &dist, set<pair<int, int>> &nodeDist, unordered_map<int, list<pair<int, int>>> &adjList)
{
    // insert the source vertex with distance 0 to start
    nodeDist.insert({0, src});
    dist[src] = 0;

    while (!nodeDist.empty())
    {
        pair<int, int> top = *nodeDist.begin();
        nodeDist.erase(nodeDist.begin());

        int nodeDistance = top.first;
        int node = top.second;

        for (auto neighbour : adjList[node])
        {
            if (nodeDistance + neighbour.second < dist[neighbour.first])
            {
                auto record = nodeDist.find({dist[neighbour.first], neighbour.first});

                // if there is already a set entry, then delete it
                if (record != nodeDist.end())
                {
                    nodeDist.erase(record);
                }

                // distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;

                nodeDist.insert({dist[neighbour.first], neighbour.first});
            }
        }
    }
}

// Time Complexity -> O(E*(log(V))) because of set
// Space Complexity -> O(n + e)
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // {vertex: [neighbour, weight]}
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int weight = vec[i][2];

        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }

    // in descending order: first largest last lowest
    // in case of pair, the order will be based on the first value in the pair
    set<pair<int, int>> nodesDist;

    shortestPath(source, dist, nodesDist, adjList);

    return dist;
}

int main()
{

    return 0;
}