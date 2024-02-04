#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

void makeAdjList(vector<pair<int, int>> &adj, unordered_map<int, set<int>> &adjList)
{
    for (int i = 0; i < adj.size(); i++)
    {
        int u = adj[i].first;
        int v = adj[i].second;

        // as it is directed graph
        adjList[u].insert(v);
    }
}

bool dfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &isVisited, unordered_map<int, bool> &dfsVisited, int node)
{
    if (isVisited[node] && dfsVisited[node])
    {
        return true;
    }
    else if (!isVisited[node])
    {
        isVisited[node] = true;
        dfsVisited[node] = true;

        for (auto node : adjList[node])
        {
            bool ans = dfs(adjList, isVisited, dfsVisited, node);
            if (ans)
                return true;
        }
    }
    dfsVisited[node] = false;

    return false;
}

// Time Complexity -> O(nodes + edges)
// Space Complexity -> O(nodes + edges)
bool isCyclicDFS(vector<pair<int, int>> &adj, int vertex)
{
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> isVisited;
    unordered_map<int, bool> dfsVisited;

    makeAdjList(adj, adjList);

    for (int i = 1; i <= vertex; i++)
    {
        if (!isVisited[i])
        {
            bool ans = dfs(adjList, isVisited, dfsVisited, i);
            if (ans)
                return true;
        }
    }

    return false;
}

int main()
{

    return 0;
}