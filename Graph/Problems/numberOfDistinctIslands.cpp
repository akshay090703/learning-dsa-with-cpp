//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void bfs(vector<vector<int>> &grid, vector<vector<bool>> &isVisited,
             set<set<pair<int, int>>> &uniqueIslands, int row, int col)
    {
        int n = grid.size();
        int m = grid[0].size();

        isVisited[row][col] = true;
        queue<pair<int, int>> q;
        q.push({row, col});

        set<pair<int, int>> st;
        int initialRow = row;
        int initialCol = col;
        st.insert({row - initialRow, col - initialCol});

        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            st.insert({i - initialRow, j - initialCol});

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

        uniqueIslands.insert(st);
    }

    // TC -> O(n * m)
    // SC -> O(n * m)
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        set<set<pair<int, int>>> uniqueIslands;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 and !isVisited[i][j])
                {
                    bfs(grid, isVisited, uniqueIslands, i, j);
                }
            }
        }

        return uniqueIslands.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends