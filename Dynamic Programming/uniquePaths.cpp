#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Using recursion
    // Time Complexity -> O(2^(m*n))
    // Space Complexity -> O(path length)
    // int solve(int m, int n) {
    //     if(m == 0 or m == 0) return 1;
    //     else if(m < 0  or n < 0) return 0;

    //     int top = 0, left = 0;

    //     top += solve(m - 1, n);
    //     left += solve(m, n - 1);

    //     return top + left;
    // }

    // Using memoization
    // Time Complexity -> O(m*n)
    // Space Complexity -> O(m*n) + O(path length)
    // int solve(int m, int n, vector<vector<int>> &dp) {
    //     if(m == 0 or n == 0) return dp[0][0] = 1;
    //     else if(m < 0 or n < 0) return 0;

    //     if(dp[m][n] != -1) return dp[m][n];

    //     int top = 0, left = 0;

    //     top += solve(m - 1, n, dp);
    //     left += solve(m, n - 1, dp);

    //     return dp[m][n] = top + left;
    // }

    // Tabulation
    // Time Complexity -> O(m*n)
    // Space Complexity -> O(m*n)
    // int solve(int m, int n, vector<vector<int>> &dp) {
    //     dp[0][0] = 1;

    //     for(int i = 0; i <= m; i++) {
    //         for(int j = 0; j <= n; j++) {
    //             if(i == 0 and j == 0) continue;

    //             int top = 0, left = 0;

    //             if(i - 1 >= 0) top += dp[i - 1][j];
    //             if(j - 1 >= 0) left += dp[i][j - 1];

    //             dp[i][j] = top + left;
    //         }
    //     }

    //     return dp[m][n];
    // }

    // Using Space Optimization
    // Time Complexity -> O(m*n)
    // Space Complexity -> O(n)
    int solve(int m, int n)
    {
        vector<int> dp(n + 1, 0);

        for (int i = 0; i <= m; i++)
        {
            vector<int> temp(n + 1, -1);
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 and j == 0)
                {
                    temp[j] = 1;
                    continue;
                }

                int top = 0, left = 0;

                if (i - 1 >= 0)
                    top = dp[j];
                if (j - 1 >= 0)
                    left = temp[j - 1];

                temp[j] = top + left;
            }

            dp = temp;
        }

        return dp[n];
    }

    int uniquePaths(int m, int n)
    {
        return solve(m - 1, n - 1);

        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return solve(m - 1, n - 1, dp);
    }
};

int main()
{

    return 0;
}