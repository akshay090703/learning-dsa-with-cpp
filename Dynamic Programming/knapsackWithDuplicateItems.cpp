//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Recursion with Memoization
    // TC -> O(n * w)
    // SC -> O(n * w) + O(n)
    // int solve(int n, int w, int val[], int wt[], vector<vector<long long>> &dp) {
    //     if(n == 0) {
    //         if(w % wt[0] >= 0) return (w / wt[0]) * val[0];

    //         return INT_MIN;
    //     }

    //     if(dp[n][w] != -1) return dp[n][w];

    //     long long pick = INT_MIN;
    //     if(wt[n] <= w) pick = solve(n, w - wt[n], val, wt, dp) + val[n];

    //     long long notPick = solve(n - 1, w, val, wt, dp);

    //     return dp[n][w] = max(pick, notPick);
    // }

    // Tabulation
    // TC -> O(n * w)
    // SC -> O(n * w)
    // int solve(int n, int w, int val[], int wt[], vector<vector<long long>> &dp) {
    //     for(int i = 0; i<=w; i++) {
    //         dp[0][i] = (i / wt[0]) * val[0];
    //     }

    //     for(int i = 1; i <= n; i++) {
    //         for(int j = 0; j <= w; j++) {
    //             long long pick = INT_MIN;
    //             if(wt[i] <= j) pick = dp[i][j - wt[i]] + val[i];

    //             long long notPick = dp[i - 1][j];

    //             dp[i][j] = max(pick, notPick);
    //         }
    //     }

    //     return dp[n][w];
    // }

    // Space Optimization
    // TC -> O(n * w)
    // SC -> O(n)
    int solve(int n, int w, int val[], int wt[])
    {
        vector<long long> dp(w + 1, 0);

        for (int i = 0; i <= w; i++)
        {
            dp[i] = (i / wt[0]) * val[0];
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                long long pick = INT_MIN;
                if (wt[i] <= j)
                    pick = dp[j - wt[i]] + val[i];

                long long notPick = dp[j];

                dp[j] = max(pick, notPick);
            }
        }

        return dp[w];
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        // vector<vector<long long>> dp(N, vector<long long> (W + 1, 0));
        // int result = solve(N - 1, W, val, wt, dp);
        int result = solve(N - 1, W, val, wt);

        return result < 0 ? 0 : result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}
// } Driver Code Ends