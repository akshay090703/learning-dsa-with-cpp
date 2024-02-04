#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

void makeAdjList(vector<vector<int>> &edges, unordered_map<int, list<int>> &adj)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v); // as it is directed
    }
}

// using dfs traversal
void solve(unordered_map<int, list<int>> &adjList, vector<bool> &isVisited, stack<int> &s, int node)
{
    if (isVisited[node])
        return;

    isVisited[node] = true;
    for (auto neighbour : adjList[node])
    {
        if (!isVisited[neighbour])
        {
            solve(adjList, isVisited, s, neighbour);
        }
    }

    s.push(node);
}

// Time Complexity -> O(n + m)
// Space Complexity -> O(n + m)
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adjList;
    vector<bool> isVisited(v); // in unordered_map, we were getting TLE
    stack<int> s;

    makeAdjList(edges, adjList);

    for (int i = 0; i < v; i++)
    {
        if (!isVisited[i])
        {
            solve(adjList, isVisited, s, i);
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        int node = s.top();
        ans.push_back(node);
        s.pop();
    }

    return ans;
}

int main()
{

    return 0;
}