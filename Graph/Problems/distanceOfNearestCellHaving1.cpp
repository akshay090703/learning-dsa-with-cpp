//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Time Complexity: O(n*m)
    // Auxiliary Space: O(n*m)
    vector<vector<int>> distNearestCellOf1(vector<vector<int>> &grid, vector<vector<bool>> &isVisited, queue<pair<pair<int, int>, int>> &q, int n, int m)
    {
        vector<vector<int>> distance(n, vector<int>(m, 0));

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            distance[row][col] = dist;

            vector<pair<int, int>> neighbours;
            if (row - 1 >= 0 and !isVisited[row - 1][col])
                neighbours.push_back({row - 1, col});
            if (row + 1 < n and !isVisited[row + 1][col])
                neighbours.push_back({row + 1, col});
            if (col - 1 >= 0 and !isVisited[row][col - 1])
                neighbours.push_back({row, col - 1});
            if (col + 1 < m and !isVisited[row][col + 1])
                neighbours.push_back({row, col + 1});

            for (auto p : neighbours)
            {
                if (!isVisited[p.first][p.second])
                {
                    isVisited[p.first][p.second] = true;
                    q.push({{p.first, p.second}, dist + 1});
                }
            }
        }

        return distance;
    }

    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({{i, j}, 0});
                    isVisited[i][j] = true;
                }
            }
        }

        return distNearestCellOf1(grid, isVisited, q, n, m);
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
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends