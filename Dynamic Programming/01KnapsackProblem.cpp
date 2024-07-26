//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Recursion with Memoization
    // TC -> O(n*w)
    // SC -> O(n*w) + O(n)
    // int solve(int W, int wt[], int val[], int n, vector<vector<int>> &dp) {
    //     if(n == 0) {
    //         if(wt[0] <= W) return val[0];
    //         return 0;
    //     }

    //     if(dp[n][W] != -1) return dp[n][W];

    //     int pick = INT_MIN;
    //     if(wt[n] <= W) pick = solve(W - wt[n], wt, val, n - 1, dp) + val[n];

    //     int notPick = solve(W, wt, val, n - 1, dp);

    //     return dp[n][W] = max(pick, notPick);
    // }

    // Tabulation
    // TC -> O(n*w)
    // SC -> O(n*w)
    // int solve(int W, int wt[], int val[], int n, vector<vector<int>> &dp) {
    //     for(int i = wt[0]; i<=W; i++) {
    //         dp[0][i] = val[0];
    //     }

    //     for(int i = 1; i<=n; i++) {
    //         for(int j = 0; j<=W; j++) {
    //             int pick = INT_MIN;
    //             if(wt[i] <= j) pick = dp[i - 1][j - wt[i]] + val[i];

    //             int notPick = dp[i - 1][j];

    //             dp[i][j] = max(pick, notPick);
    //         }
    //     }

    //     return dp[n][W];
    // }

    // Space Optimization
    // TC -> O(n*w)
    // SC -> O(n)
    int solve(int W, int wt[], int val[], int n)
    {
        vector<int> prev(W + 1, 0);

        for (int i = wt[0]; i <= W; i++)
        {
            prev[i] = val[0];
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = W; j >= 0; j--)
            {
                int pick = INT_MIN;
                if (wt[i] <= j)
                    pick = prev[j - wt[i]] + val[i];

                int notPick = prev[j];

                prev[j] = max(pick, notPick);
            }
        }

        return prev[W];
    }

    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        // vector<vector<int>> dp(n, vector<int> (W + 1, 0));
        // return solve(W, wt, val, n - 1, dp);
        return solve(W, wt, val, n - 1);
    }
};

//{ Driver Code Starts.

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        // inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        // inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        // calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
}
// } Driver Code Ends