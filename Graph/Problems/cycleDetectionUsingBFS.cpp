#include <iostream>
#include <queue>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

// Time Complexity -> O(n + e)
// Space Complexity -> O(n + e)
bool detectedCycle(vector<pair<int, int>> &edges, int n)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    // as here 1 based indexing is followed
    vector<int> inDegree(n + 1);
    for (auto i : adjList)
    {
        for (auto j : i.second)
        {
            inDegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!inDegree[i])
        {
            q.push(i);
        }
    }

    // now we will do bfs
    int count = 0;
    // in a valid topological sort, the number of printing is equal to the total number of nodes present
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        count++;

        for (auto neighbour : adjList[front])
        {
            inDegree[neighbour]--;

            if (inDegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    // when count is equal to n, then it is a valid topological sort and hence it is an acyclic graph by nature
    if (count == n)
        return false;

    return true;
}

int main()
{

    return 0;
}