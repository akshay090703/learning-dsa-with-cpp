#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <stack>
#include <limits.h>
using namespace std;

struct Graph
{
    unordered_map<int, list<pair<int, int>>> adjList; // (neighbour node, weight)

    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adjList[u].push_back(p);
    }

    void printAdj()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "{" << j.first << ", " << j.second << "}, ";
            }
            cout << endl;
        }
    }

    void dfs(unordered_map<int, bool> &isVisited, int node, stack<int> &st)
    {
        isVisited[node] = true;

        for (auto neighbour : this->adjList[node])
        {
            if (!isVisited[neighbour.first])
            {
                dfs(isVisited, neighbour.first, st);
            }
        }
        st.push(node);
    }

    // Time Complexity -> O(n + e)
    // Space Complexity -> O(n + e)
    void getShortestPath(int src, vector<int> &dist, stack<int> &st)
    {
        dist[src] = 0; // initialising

        while (!st.empty())
        {
            int top = st.top();
            st.pop();

            if (dist[top] != INT_MAX)
            {
                for (auto i : adjList[top])
                {
                    if (dist[top] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdj();

    int n = 6;
    // Topological Sort
    unordered_map<int, bool> isVisited;
    stack<int> st;
    for (int i = 0; i <= n; i++)
    {
        if (!isVisited[i])
        {
            g.dfs(isVisited, i, st);
        }
    }

    int src = 1; // source node
    vector<int> dist(n);

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    g.getShortestPath(src, dist, st);

    cout << "Answer of shortest path in weighted DAG from node '1': \n";
    for (int i = 0; i < dist.size(); i++)
    {
        cout << src << "-" << i << " -> " << dist[i] << endl;
    }
    // answer should be:{INT_MAX, 0, 2, 6, 5, 3}

    return 0;
}