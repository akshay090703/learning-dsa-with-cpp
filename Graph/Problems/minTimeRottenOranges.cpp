//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int bfs(vector<vector<int>> &grid, vector<pair<int, int>> &rotten, int freshOranges, int n, int m)
    {
        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for (auto p : rotten)
        {
            isVisited[p.first][p.second] = true;
            q.push({p.first, p.second});
        }

        int time = -1;
        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                vector<pair<int, int>> neighbours;
                if (row - 1 >= 0 and grid[row - 1][col] == 1)
                    neighbours.push_back({row - 1, col});
                if (row + 1 < n and grid[row + 1][col] == 1)
                    neighbours.push_back({row + 1, col});
                if (col - 1 >= 0 and grid[row][col - 1] == 1)
                    neighbours.push_back({row, col - 1});
                if (col + 1 < m and grid[row][col + 1] == 1)
                    neighbours.push_back({row, col + 1});

                for (auto p : neighbours)
                {
                    if (!isVisited[p.first][p.second])
                    {
                        freshOranges--;
                        isVisited[p.first][p.second] = true;
                        q.push({p.first, p.second});
                    }
                }
            }

            time++;
        }

        if (freshOranges > 0)
            return -1;

        return time;
    }

    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int freshOranges = 0;
        vector<pair<int, int>> rotten;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    rotten.push_back({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    freshOranges++;
                }
            }
        }

        if (freshOranges == 0)
            return 0;

        return bfs(grid, rotten, freshOranges, n, m);
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
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends