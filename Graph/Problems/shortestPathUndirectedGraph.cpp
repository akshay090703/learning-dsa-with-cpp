#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(unordered_map<int, list<int>> &adjList, vector<bool> &isVisited, int node, int end, vector<int> &ans, vector<int> &path)
{
    if (isVisited[node])
        return;

    path.push_back(node);
    isVisited[node] = true;

    if (node == end)
    {
        if (ans.empty() || ans.size() > path.size())
        {
            ans = path;
        }
    }

    for (auto neighbour : adjList[node])
    {
        if (!isVisited[neighbour])
        {
            dfs(adjList, isVisited, neighbour, end, ans, path);
        }
    }

    // Backtracking
    isVisited[node] = false;
    path.pop_back();
}

// Time Complexity -> O(n+m)
// Space Complexity -> O(n+m)
// getting TLE in this
vector<int> shortestPathDFS(vector<pair<int, int>> &edges, int n, int m, int startNode, int endNode)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        // This is an undirected graph
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> isVisited(n + 1, false);
    vector<int> ans;
    vector<int> path;
    dfs(adjList, isVisited, startNode, endNode, ans, path);

    return ans;
}

// We won't get TLE in this as we are doing this iteratively and not in recursive calls
// Time Complexity -> O(n + e)
// Space Complexity -> O(n + e)
vector<int> shortestPathBFS(vector<pair<int, int>> &edges, int n, int m, int startNode, int endNode)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        // This is an undirected graph
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> isVisited(n + 1, false);
    unordered_map<int, int> parent;

    queue<int> q;
    q.push(startNode);
    isVisited[startNode] = true;
    parent[startNode] = -1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto neighbour : adjList[frontNode])
        {
            if (!isVisited[neighbour])
            {
                q.push(neighbour);
                isVisited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
    }

    // Now we have the parent of each node and can find the path from source to destination using backtracking
    vector<int> path;
    int node = endNode;
    path.push_back(node);

    while (node != startNode)
    {
        node = parent[node];
        path.push_back(node);
    }

    reverse(path.begin(), path.end());

    return path;
}

int main()
{

    return 0;
}