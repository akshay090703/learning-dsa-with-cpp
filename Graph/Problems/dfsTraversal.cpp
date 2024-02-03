#include <unordered_map>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

// Time Complexity:
// Overall: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
// prepareAdjList: O(E) to iterate through the input edges and create the adjacency list.
// dfs: O(V + E) in the worst case, where it visits all vertices and edges in a connected component.
// depthFirstSearch: O(V + E) due to prepareAdjList and potentially calling dfs for each vertex.

// Space Complexity:
// O(V + E) in the worst case, considering the following data structures:
// adjList (adjacency list): O(V + E) to store vertices and their neighbors.
// isVisited (visited map): O(V) to track visited vertices.
// ans (resultant vector of components): O(V) in the worst case, where each vertex might form its own component.
// Recursion stack for dfs: O(V) in the worst case, due to nested calls for each vertex in a path.

void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<vector<int>> &adj)
{
    for (int i = 0; i < adj.size(); i++)
    {
        int u = adj[i][0];
        int v = adj[i][1];

        // undirected graph
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &isVisited, int node, vector<int> &component)
{
    if (isVisited[node])
        return;

    isVisited[node] = true;
    component.push_back(node);

    // call dfs for all neighbors if not visited
    for (auto i : adjList[node])
    {
        dfs(adjList, isVisited, i, component);
    }
}

// Time Complexity -> O(V + E)
// Space Complexity -> O(V + E)
vector<vector<int>> depthFirstSearch(int vertex, int E, vector<vector<int>> &adj)
{
    unordered_map<int, list<int>> adjList;
    vector<vector<int>> ans;
    unordered_map<int, bool> isVisited;

    prepareAdjList(adjList, adj);

    for (int i = 0; i < vertex; i++)
    {
        if (!isVisited[i])
        {
            vector<int> component;
            dfs(adjList, isVisited, i, component);
            ans.push_back(component);
        }
    }

    return ans;
}

int main()
{

    return 0;
}