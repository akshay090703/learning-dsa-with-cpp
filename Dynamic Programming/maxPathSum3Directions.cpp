//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Recursion
    // TC -> O(n * 3^(n*n))
    // SC -> O(path sum)
    // int solve(int n, int m, vector<vector<int>> &mat, int N) {
    //     if(n < 0 or m < 0 or m < N) return 0;
    //     if(n == 0) return mat[0][m];

    //     int top = INT_MIN, topLeft = INT_MIN, topRight = INT_MIN;

    //     top = solve(n - 1, m, mat);
    //     topLeft = solve(n - 1, m - 1, mat);
    //     topRight = solve(n - 1, m + 1, mat);

    //     return max(top, max(topLeft, topRight)) + mat[n][m];
    // }

    // Memoization
    // TC -> O(n * n * n)
    // SC -> O(n * n)
    // int solve(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp, int N) {
    //     if(n < 0 or m < 0 or m >= N) return 0;
    //     if(n == 0) return dp[0][m] = mat[0][m];

    //     if(dp[n][m] != -1) return dp[n][m];

    //     int top = INT_MIN, topLeft = INT_MIN, topRight = INT_MIN;

    //     top = solve(n - 1, m, mat, dp, N);
    //     topLeft = solve(n - 1, m - 1, mat, dp, N);
    //     topRight = solve(n - 1, m + 1, mat, dp, N);

    //     return dp[n][m] = max(top, max(topRight, topLeft)) + mat[n][m];
    // }

    // Tabulation
    // TC -> O(n^2)
    // SC -> O(n^2)
    // int solve(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp, int N) {
    //     for(int i = 0; i<=m; i++) {
    //         dp[0][i] = mat[0][i];
    //     }

    //     for(int i = 1; i<=n; i++) {
    //         for(int j = 0; j <= m; j++) {
    //             int top = INT_MIN, topLeft = INT_MIN, topRight = INT_MIN;

    //             top = dp[i - 1][j];
    //             if(j - 1 >= 0) topLeft = dp[i - 1][j - 1];
    //             if(j + 1 < N) topRight = dp[i - 1][j + 1];

    //             dp[i][j] = max(top, max(topLeft, topRight)) + mat[i][j];
    //         }
    //     }

    //     return *max_element(dp[n].begin(), dp[n].end());
    // }

    // Space Optimization
    // TC -> O(n^2)
    // SC -> O(n) + O(n)
    int solve(int n, vector<vector<int>> &mat, int N)
    {
        vector<int> dp(n + 1);
        for (int i = 0; i <= n; i++)
        {
            dp[i] = mat[0][i];
        }

        for (int i = 1; i <= n; i++)
        {
            vector<int> temp(n + 1);

            for (int j = 0; j <= n; j++)
            {
                int top = INT_MIN, topLeft = INT_MIN, topRight = INT_MIN;

                top = dp[j];
                if (j - 1 >= 0)
                    topLeft = dp[j - 1];
                if (j + 1 < N)
                    topRight = dp[j + 1];

                temp[j] = max(top, max(topLeft, topRight)) + mat[i][j];
            }

            dp = temp;
        }

        return *max_element(dp.begin(), dp.end());
    }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // vector<vector<int>> dp(N, vector<int> (N, -1));
        // return solve(N - 1, N - 1, Matrix, dp, N);

        // int maxPathSum = 0;
        // for(int j = N - 1; j >= 0; j--) {
        //     // maxPathSum = max(maxPathSum, solve(N - 1, j, Matrix, N));
        //     maxPathSum = max(maxPathSum, solve(N - 1, j, Matrix, dp, N));
        // }
        // return maxPathSum;

        return solve(N - 1, Matrix, N);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> Matrix[(i / N)][i % N];

        Solution ob;
        cout << ob.maximumPath(N, Matrix) << "\n";
    }
    return 0;
}
// } Driver Code Ends