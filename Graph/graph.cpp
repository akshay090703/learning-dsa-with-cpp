#include <unordered_map>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>

// using Adjacency List
// struct Graph
// {
//     unordered_map<T, list<T>> adj;

//     // Time Complexity -> O(1)
//     void addEdge(T u, T v, bool direction)
//     {
//         // direction = 0 -> undirected graph
//         // direction = 1 -> directed graph

//         // create an edge from u to v
//         adj[u].push_back(v);

//         if (!direction) // undirected graph
//         {
//             adj[v].push_back(u);
//         }
//     }

//     // Time Complexity -> O(n*m)
//     // Space Complexity -> O(1)
//     void printAdjList()
//     {
//         for (auto i : adj)
//         {
//             cout << i.first << "-> ";
//             for (auto j : i.second)
//             {
//                 cout << j << ", ";
//             }
//             cout << endl;
//         }
//     }
// };

// Using Adjacency Matrix
class Graph
{
    int vertices;
    vector<vector<int>> adj;

public:
    Graph(int vertices) : vertices(vertices), adj(vertices, vector<int>(vertices, 0)){};

    // direction = 0 -> undirected graph
    // direction = 1 -> directed graph

    void addEdge(int start, int end, bool direction)
    {
        if (start >= 0 && start < vertices && end >= 0 && end < vertices)
        {
            adj[start][end]++;

            if (!direction)
            {
                adj[end][start]++;
            }
        }
        else
        {
            cout << "Invalid vertices!" << endl;
        }
    }

    void printMatrix()
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    Graph<int> g(n);

    // Time Complexity -> O(m)
    // Space Complexity -> O(n+m)
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0); // undirected
    }

    // printing graph
    // cout << "Adjacency List: " << endl;
    // g.printAdjList();
    cout << "Adjacency Matrix: " << endl;
    g.printMatrix();

    return 0;
}