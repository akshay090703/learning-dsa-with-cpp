//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> adjMat(n, vector<int>(n, 1e9));
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int dist = edges[i][2];

            adjMat[u][v] = dist;
            adjMat[v][u] = dist;
        }

        for (int i = 0; i < n; i++)
            adjMat[i][i] = 0;

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                }
            }
        }

        for (int i = 0; i < n; i++)
            if (adjMat[i][i] < 0)
                cout << "There is a negative cycle." << endl;

        int smallestCity = -1;
        int minNeighbours = 1e9;
        for (int i = 0; i < n; i++)
        {
            int neighbours = 0;

            for (int j = 0; j < n; j++)
            {
                if (adjMat[i][j] <= distanceThreshold)
                    neighbours++;
            }

            if (neighbours <= minNeighbours)
            {
                minNeighbours = neighbours;
                smallestCity = i;
            }
        }

        return smallestCity;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends