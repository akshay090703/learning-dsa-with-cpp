#include <unordered_map>
#include <queue>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

void makeAdjList(vector<vector<int>> &adj, unordered_map<int, set<int>> &adjList)
{
    for (int i = 0; i < adj.size(); ++i)
    {
        int u = adj[i][0];
        int v = adj[i][1];

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

bool bfs(unordered_map<int, bool> &isVisited, unordered_map<int, set<int>> &adjList, int node, unordered_map<int, int> &parent)
{
    queue<int> q;
    q.push(node);
    isVisited[node] = true;
    parent[node] = -1;

    while (!q.empty())
    {
        int currNode = q.front();
        q.pop();

        for (auto i : adjList[currNode])
        {
            if (isVisited[i] && i != parent[currNode])
            {
                return true; // cycle detected
            }
            else if (!isVisited[i])
            {
                q.push(i);
                isVisited[i] = true;
                parent[i] = currNode;
            }
        }
    }

    return false;
}

// Time Complexity -> O(n+m)
// Space Complexity -> O(n+m)
bool isCyclicBFS(vector<vector<int>> &adj, int vertex)
{
    unordered_map<int, bool> isVisited;
    unordered_map<int, set<int>> adjList;

    unordered_map<int, int> parent;

    makeAdjList(adj, adjList);

    for (int i = 1; i <= vertex; i++)
    {
        if (!isVisited[i])
        {
            bool ans = bfs(isVisited, adjList, i, parent);
            if (ans)
                return true;
        }
    }

    return false;
}

// Using DFS traversal
// Time Complexity -> O(2n+m) ~ O(n+m)
// Space Complexity -> O(2n+m) ~ O(n+m)
void createAdjList(vector<vector<int>> &adj, unordered_map<int, set<int>> &adjList)
{
    for (int i = 0; i < adj.size(); i++)
    {
        int u = adj[i][0];
        int v = adj[i][1];

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

bool dfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &isVisited, unordered_map<int, int> &parent, int node, int parentNode)
{
    if (isVisited[node] && node != parent[parentNode])
        return true;
    else if (!isVisited[node])
    {
        isVisited[node] = true;
        parent[node] = parentNode;

        for (auto neighbour : adjList[node])
        {
            bool cycleDetected = dfs(adjList, isVisited, parent, neighbour, node);
            if (cycleDetected)
                return true;
        }
    }

    return false;
}

bool isCyclicDFS(vector<vector<int>> &adj, int vertex)
{
    unordered_map<int, bool> isVisited;
    unordered_map<int, set<int>> adjList;

    unordered_map<int, int> parent;

    createAdjList(adj, adjList);

    for (int i = 0; i < vertex; i++)
    {
        if (!isVisited[i])
        {
            bool ans = dfs(adjList, isVisited, parent, i, -1);
            if (ans)
                return true;
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    string ans = isCyclicDFS(edges, n) ? "Yes" : "No";

    return ans;
}

int main()
{
    // vector<vector<int>> edges = {{1, 2}, {2, 3}, {1, 3}};
    vector<vector<int>> edges = {{1, 2}, {2, 3}};
    cout << cycleDetection(edges, 3, 2) << endl;

    return 0;
}