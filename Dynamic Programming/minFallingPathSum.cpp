#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursion
    // TC -> O(3^(n*n))
    // SC -> O(path length)
    // int solve(vector<vector<int>> &matrix, int row, int col) {
    //     if(col < 0 or col >= matrix[row].size()) return INT_MAX;

    //     if(row == 0) return matrix[row][col];

    //     int top = solve(matrix, row - 1, col);
    //     int topLeft = solve(matrix, row - 1, col - 1);
    //     int topRight = solve(matrix, row - 1, col + 1);

    //     return min(top, min(topLeft, topRight)) + matrix[row][col];
    // }

    // Memoization
    // TC -> O(n*n)
    // SC -> O(n*n)
    // int solve(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp) {
    //     if(col < 0 or col >= matrix[0].size()) return INT_MAX;

    //     if(row == 0) return dp[0][col] = matrix[0][col];

    //     if(dp[row][col] != -1) return dp[row][col];

    //     int top = solve(matrix, row - 1, col, dp);
    //     int topLeft = solve(matrix, row - 1, col - 1, dp);
    //     int topRight = solve(matrix, row - 1, col + 1, dp);

    //     return dp[row][col] = min(top, min(topLeft, topRight)) + matrix[row][col];
    // }

    // Tabulation
    // Tc -> O(n*n)
    // Sc -> O(n*n)
    // int solve(vector<vector<int>> &matrix, int n, vector<vector<int>> &dp) {
    //     for(int i = 0; i<=n; i++) {
    //         dp[0][i] = matrix[0][i];
    //     }

    //     for(int i = 1; i<=n; i++) {
    //         for(int j = 0; j<=n; j++) {
    //             int top = INT_MAX, topLeft = INT_MAX, topRight = INT_MAX;

    //             top = dp[i - 1][j];
    //             if(j - 1 >= 0) topLeft = dp[i - 1][j - 1];
    //             if(j + 1 <= n) topRight = dp[i - 1][j + 1];

    //             dp[i][j] = min(top, min(topLeft, topRight)) + matrix[i][j];
    //         }
    //     }

    //     return *min_element(dp[n].begin(), dp[n].end());
    // }

    // Space Optimization
    // TC -> O(N^2)
    // SC -> O(N) + O(N)
    int solve(vector<vector<int>> &matrix, int n)
    {
        vector<int> dp(matrix[0].begin(), matrix[0].end());
        vector<int> temp(n + 1);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                int top = INT_MAX, topLeft = INT_MAX, topRight = INT_MAX;

                top = dp[j];
                if (j - 1 >= 0)
                    topLeft = dp[j - 1];
                if (j + 1 <= n)
                    topRight = dp[j + 1];

                temp[j] = min(top, min(topLeft, topRight)) + matrix[i][j];
            }

            dp = temp;
        }

        return *min_element(dp.begin(), dp.end());
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        return solve(matrix, n - 1);

        // vector<vector<int>> dp(n, vector<int> (n, -1));
        // return solve(matrix, n - 1, dp);

        // int minPath = INT_MAX;
        // for(int i = n - 1; i>=0; i--) {
        //     // minPath = min(minPath, solve(matrix, n - 1, i));
        //     minPath = min(minPath, solve(matrix, n - 1, i, dp));
        // }
        // return minPath;
    }
};

int main()
{

    return 0;
}