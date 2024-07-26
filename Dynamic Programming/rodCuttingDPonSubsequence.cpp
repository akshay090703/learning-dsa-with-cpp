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
    // TC -> O(n * inches)
    // SC -> O(n * inches) + O(n)
    // int solve(int price[], int n, int inches, vector<vector<int>> &dp) {
    //     if(n == 0) {
    //         return inches * price[0];
    //     }

    //     if(dp[n][inches] != -1) return dp[n][inches];

    //     int pick = INT_MIN;
    //     if(n + 1 <= inches) pick = solve(price, n, inches - (n + 1), dp) + price[n];

    //     int notPick = solve(price, n - 1, inches, dp);

    //     return dp[n][inches] = max(pick, notPick);
    // }

    // Tabulation
    // TC -> O(n * inches)
    // SC -> O(n * inches)
    // int solve(int price[], int n, int inches, vector<vector<int>> &dp) {
    //     for(int i = 0; i<=inches; i++) {
    //         dp[0][i] = i * price[0];
    //     }

    //     for(int i = 1; i<=n; i++) {
    //         for(int j = 0; j<=inches; j++) {
    //             int pick = INT_MIN;
    //             if(i + 1 <= j) pick = dp[i][j - (i + 1)] + price[i];

    //             int notPick = dp[i - 1][j];

    //             dp[i][j] = max(pick, notPick);
    //         }
    //     }

    //     return dp[n][inches];
    // }

    // Space Optimization
    // TC -> O(n * inches)
    // SC -> O(n)
    int solve(int price[], int n, int inches)
    {
        vector<int> dp(inches + 1, 0);

        for (int i = 0; i <= inches; i++)
        {
            dp[i] = i * price[0];
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= inches; j++)
            {
                int pick = INT_MIN;
                if (i + 1 <= j)
                    pick = dp[j - (i + 1)] + price[i];

                int notPick = dp[j];

                dp[j] = max(pick, notPick);
            }
        }

        return dp[inches];
    }

    int cutRod(int price[], int n)
    {
        // vector<vector<int>> dp(n, vector<int> (n + 1, 0));
        // return solve(price, n - 1, n, dp);

        return solve(price, n - 1, n);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends