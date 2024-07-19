//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    const int MOD = 1000000007;

    // Recursion
    // TC -> O(2^(m*n))
    // SC -> O(path length)
    // int solve(int n, int m, vector<vector<int>> &grid) {
    //     if(n == 0 and m == 0) return 1;
    //     else if(n < 0 or m < 0 or grid[n][m] == 0) return 0;

    //     int left = 0, top = 0;

    //     left += solve(n, m - 1, grid);
    //     top += solve(n - 1, m, grid);

    //     return top + left;
    // }

    // Memoization
    // TC -> O(n*m)
    // SC -> O(path length) + O(n*m)
    // int solve(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    //     if(n == 0 and m == 0) return dp[0][0] = 1;

    //     if(dp[n][m] != -1) return dp[n][m];

    //     int left = 0, top = 0;

    //     if(m - 1 >= 0 and grid[n][m - 1] != 0) left += solve(n, m - 1, grid, dp);
    //     if(n - 1 >= 0 and grid[n - 1][m] != 0) top += solve(n - 1, m, grid, dp);

    //     return dp[n][m] = (top + left) % MOD;
    // }

    // Tabulation
    // TC -> O(n*m)
    // SC -> O(n*m)
    // int solve(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    //     for(int i = 0; i<=n; i++) {
    //         for(int j = 0; j <= m; j++) {
    //             if(i == 0 and j == 0) {
    //                 dp[0][0] = 1;
    //                 continue;
    //             }

    //             int left = 0, top = 0;

    //             if(i - 1 >= 0 and grid[i - 1][j] != 0) top = dp[i - 1][j];
    //             if(j - 1 >= 0 and grid[i][j - 1] != 0) left = dp[i][j - 1];

    //             dp[i][j] = (top + left) % MOD;
    //         }
    //     }

    //     return dp[n][m];
    // }

    // Space Optimization
    // TC -> O(n*m)
    // SC -> O(n) + O(n)
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        vector<int> dp(m + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            vector<int> temp(m + 1, -1);

            for (int j = 0; j <= m; j++)
            {
                if (i == 0 and j == 0)
                {
                    temp[j] = 1;
                    continue;
                }

                int top = 0, left = 0;

                if (i - 1 >= 0 and grid[i - 1][j] != 0)
                    top = dp[j];
                if (j - 1 >= 0 and grid[i][j - 1] != 0)
                    left = temp[j - 1];

                temp[j] = (top + left) % MOD;
            }

            dp = temp;
        }

        return dp[m];
    }

    int uniquePaths(int n, int m, vector<vector<int>> &grid)
    {
        if (grid[n - 1][m - 1] == 0 or grid[0][0] == 0)
            return 0;

        return solve(n - 1, m - 1, grid) % MOD;

        // vector<vector<int>> dp(n, vector<int> (m, -1));
        // return solve(n - 1, m - 1, grid, dp) % MOD;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n, m, grid) << endl;
    }
    return 0;
}
// } Driver Code Ends