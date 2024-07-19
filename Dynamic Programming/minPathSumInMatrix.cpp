#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Using Recursion
    // TC -> O(2^(m*n))
    // SC -> O(path length)
    // int solve(vector<vector<int>> &grid, int m, int n) {
    //     if(m == 0 and n == 0) return grid[0][0];

    //     int top = INT_MAX, left = INT_MAX;

    //     if(m - 1 >= 0) top = solve(grid, m - 1, n);
    //     if(n - 1 >= 0) left = solve(grid, m, n - 1);

    //     return grid[m][n] + min(top, left);
    // }

    // Using Memoization
    // TC -> O(m*n)
    // SC -> O(m*n) + O(path length)
    // int solve(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp) {
    //     if(m == 0 and n == 0) return dp[0][0] = grid[0][0];

    //     if(dp[m][n] != -1) return dp[m][n];

    //     int top = INT_MAX, left = INT_MAX;

    //     if(m - 1 >= 0) top = solve(grid, m - 1, n, dp);
    //     if(n - 1 >= 0) left = solve(grid, m, n - 1, dp);

    //     return dp[m][n] = grid[m][n] + min(top, left);
    // }

    // Using Tabulation
    // TC -> O(m*n)
    // SC -> O(m*n)
    // int solve(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp) {
    //     dp[0][0] = grid[0][0];

    //     for(int i = 0; i<=m; i++) {
    //         for(int j = 0; j<=n; j++) {
    //             if(i == 0 and j == 0) continue;

    //             int top = INT_MAX, left = INT_MAX;

    //             if(i - 1 >= 0) top = dp[i - 1][j];
    //             if(j - 1 >= 0) left = dp[i][j - 1];

    //             dp[i][j] = min(left, top) + grid[i][j];
    //         }
    //     }

    //     return dp[m][n];
    // }

    // Space Optimization
    // TC -> O(m*n)
    // SC -> O(n) + O(n)
    int solve(vector<vector<int>> &grid, int m, int n)
    {
        vector<int> dp(n + 1, INT_MAX);

        for (int i = 0; i <= m; i++)
        {
            vector<int> temp(n + 1, -1);
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 and j == 0)
                {
                    temp[j] = grid[i][j];
                    continue;
                }

                int top = i - 1 >= 0 ? dp[j] : INT_MAX;
                int left = j - 1 >= 0 ? temp[j - 1] : INT_MAX;

                temp[j] = grid[i][j] + min(top, left);
            }

            dp = temp;
        }

        return dp[n];
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        return solve(grid, m - 1, n - 1);

        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return solve(grid, m - 1, n - 1, dp);
    }
};

int main()
{

    return 0;
}