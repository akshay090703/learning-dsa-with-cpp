//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void dfs(vector<vector<char>> &temp, vector<vector<bool>> &isVisited, int i, int j, int n, int m)
    {
        isVisited[i][j] = true;

        vector<pair<int, int>> neighbours;
        if (i - 1 >= 0 and temp[i - 1][j] == 'O')
            neighbours.push_back({i - 1, j});
        if (i + 1 < n and temp[i + 1][j] == 'O')
            neighbours.push_back({i + 1, j});
        if (j - 1 >= 0 and temp[i][j - 1] == 'O')
            neighbours.push_back({i, j - 1});
        if (j + 1 < m and temp[i][j + 1] == 'O')
            neighbours.push_back({i, j + 1});

        for (auto p : neighbours)
        {
            if (!isVisited[p.first][p.second])
            {
                dfs(temp, isVisited, p.first, p.second, n, m);
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> &mat)
    {
        vector<vector<char>> temp(mat.begin(), mat.end());
        vector<vector<bool>> isVisited(n, vector<bool>(m, false));

        for (int j = 0; j < m; j++)
        {
            if (temp[0][j] == 'O' and !isVisited[0][j])
            {
                dfs(temp, isVisited, 0, j, n, m);
            }

            if (temp[n - 1][j] == 'O' and !isVisited[n - 1][j])
            {
                dfs(temp, isVisited, n - 1, j, n, m);
            }
        }

        for (int i = 1; i < n; i++)
        {
            if (temp[i][0] == 'O' and !isVisited[i][0])
            {
                dfs(temp, isVisited, i, 0, n, m);
            }

            if (temp[i][m - 1] == 'O' and !isVisited[i][m - 1])
            {
                dfs(temp, isVisited, i, m - 1, n, m);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (temp[i][j] == 'O' and !isVisited[i][j])
                    temp[i][j] = 'X';
            }
        }

        return temp;
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
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends