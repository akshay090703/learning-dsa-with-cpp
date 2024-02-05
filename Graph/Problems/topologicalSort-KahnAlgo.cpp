#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

void bfs(unordered_map<int, list<int>> &adjList, queue<int> &q, unordered_map<int, bool> &isVisited, vector<int> &ans, vector<int> &indegree)
{
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // ans store
        ans.push_back(front);

        // neighbour indegree update
        for (auto i : adjList[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
}

// Time Complexity -> O(n+e)
// Space Complexity -> O(n+e)
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, bool> isVisited;
    unordered_map<int, list<int>> adjList;
    vector<int> res;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0], v = edges[i][1];
        adjList[u].push_back(v);
    }

    vector<int> indegree(v);
    for (auto i : adjList)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (!indegree[i])
            q.push(i);
    }

    // now we do bfs
    bfs(adjList, q, isVisited, res, indegree);

    return res;
}

int main()
{

    return 0;
}