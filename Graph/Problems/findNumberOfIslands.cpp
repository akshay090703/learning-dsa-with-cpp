//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Time Complexity: O(n*m)
    // Space Complexity: O(n*m)
    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &isVisited, queue<pair<int, int>> &q, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();

        q.push({i, j});
        isVisited[i][j] = true;

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            vector<pair<int, int>> neighbours;
            for (int a = col - 1; a <= col + 1; a++)
            {
                if (row - 1 >= 0 and a < m and a >= 0 and grid[row - 1][a] == '1')
                    neighbours.push_back({row - 1, a});
                if (row + 1 < n and a < m and a >= 0 and grid[row + 1][a] == '1')
                    neighbours.push_back({row + 1, a});
            }

            if (col - 1 >= 0 and grid[row][col - 1] == '1')
                neighbours.push_back({row, col - 1});
            if (col + 1 < m and grid[row][col + 1] == '1')
                neighbours.push_back({row, col + 1});

            for (auto p : neighbours)
            {
                if (!isVisited[p.first][p.second])
                {
                    isVisited[p.first][p.second] = true;
                    q.push(p);
                }
            }
        }
    }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        int islands = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' and !isVisited[i][j])
                {
                    bfs(grid, isVisited, q, i, j);
                    islands++;
                }
            }
        }

        return islands;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends