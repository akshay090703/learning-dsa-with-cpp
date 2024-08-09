//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // TC -> O(n * m)
    // SC -> O(n * m)
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[source.first][source.second] != 1 or grid[destination.first][destination.second] != 1)
            return -1;

        vector<vector<bool>> isVisited(n, vector<bool>(m, false));

        // no need here as all node weights are equal so it will be store in increasing
        // order by default even in a queue
        // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

        // distance , {row, col}
        queue<pair<int, pair<int, int>>> q;

        // here the level number is the distance, and as soon as we find the destination, we return
        q.push({0, {source.first, source.second}});
        isVisited[source.first][source.second] = true;
        while (!q.empty())
        {
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            if (row == destination.first and col == destination.second)
                return dist;

            vector<pair<int, int>> neighbours;
            if (row - 1 >= 0 and grid[row - 1][col] == 1)
                neighbours.push_back({row - 1, col});
            if (row + 1 < n and grid[row + 1][col] == 1)
                neighbours.push_back({row + 1, col});
            if (col - 1 >= 0 and grid[row][col - 1] == 1)
                neighbours.push_back({row, col - 1});
            if (col + 1 < m and grid[row][col + 1] == 1)
                neighbours.push_back({row, col + 1});

            for (auto neighbour : neighbours)
            {
                int nRow = neighbour.first;
                int nCol = neighbour.second;

                if (!isVisited[nRow][nCol])
                {
                    isVisited[nRow][nCol] = true;
                    q.push({dist + 1, {nRow, nCol}});
                }
            }
        }

        return -1;
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
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends