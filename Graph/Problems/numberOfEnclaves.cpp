//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void bfs(vector<vector<int>> &grid, vector<vector<bool>> &isVisited, int row, int col)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});
        isVisited[row][col] = true;

        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            vector<pair<int, int>> neighbours;
            if (i - 1 >= 0 and grid[i - 1][j] == 1)
                neighbours.push_back({i - 1, j});
            if (i + 1 < n and grid[i + 1][j] == 1)
                neighbours.push_back({i + 1, j});
            if (j - 1 >= 0 and grid[i][j - 1] == 1)
                neighbours.push_back({i, j - 1});
            if (j + 1 < m and grid[i][j + 1] == 1)
                neighbours.push_back({i, j + 1});

            for (auto p : neighbours)
            {
                if (!isVisited[p.first][p.second])
                {
                    isVisited[p.first][p.second] = true;
                    q.push({p.first, p.second});
                }
            }
        }
    }

    // Time Complexity: O(n * m)
    // Space Complexity: O(n * m)
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] == 1 and !isVisited[0][j])
                bfs(grid, isVisited, 0, j);

            if (grid[n - 1][j] == 1 and !isVisited[n - 1][j])
                bfs(grid, isVisited, n - 1, j);
        }

        for (int i = 1; i < n - 1; i++)
        {
            if (grid[i][0] == 1 and !isVisited[i][0])
                bfs(grid, isVisited, i, 0);

            if (grid[i][m - 1] == 1 and !isVisited[i][m - 1])
                bfs(grid, isVisited, i, m - 1);
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 and !isVisited[i][j])
                    count++;
            }
        }

        return count;
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
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends