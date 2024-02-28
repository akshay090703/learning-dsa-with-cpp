#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, visited, st, adj);
        }
    }

    // topological sort
    st.push(node);
}

void reverseDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &transpose)
{
    visited[node] = true;

    for (auto neighbour : transpose[node])
    {
        if (!visited[neighbour])
        {
            reverseDfs(neighbour, visited, transpose);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // adjacency list creation
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // Step 1: Topological sort
    stack<int> st;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, st, adj);
        }
    }

    // Step 2: Transpose graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        visited[i] = false; // for 3rd step
        for (auto neighbour : adj[i])
        {
            transpose[neighbour].push_back(i);
        }
    }

    // Step 3: DFS on transpose graph using topological sort ordering
    int count = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        if (!visited[top])
        {
            count++;
            reverseDfs(top, visited, transpose);
        }
    }

    return count;
}

int main()
{

    return 0;
}