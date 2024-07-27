//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Recursion with Memoization
    // TC -> O(n * n)
    // SC -> O(n * n) + O(n + n)
    // int solve(string &s, string &t, int n, int m, vector<vector<int>> &dp) {
    //     if(n == 0 or m == 0) return 0;

    //     if(dp[n][m] != -1) return dp[n][m];

    //     if(s[n - 1] == t[m - 1])
    //         return dp[n][m] = 1 + solve(s, t, n - 1, m - 1, dp);

    //     return dp[n][m] = 0 + max(solve(s, t, n, m - 1, dp), solve(s, t, n - 1, m, dp));
    // }

    // Tabulation
    // TC -> O(n * n)
    // SC -> O(n * n)
    // int solve(string &s, string &t, int n, int m) {
    //     vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

    //     for(int i = 1; i<=n; i++) {
    //         for(int j = 1; j<=m; j++) {
    //             if(s[i - 1] == t[j - 1])
    //                 dp[i][j] = 1 + dp[i - 1][j - 1];
    //             else
    //                 dp[i][j] = 0 + max(dp[i][j - 1], dp[i - 1][j]);
    //         }
    //     }

    //     return dp[n][m];
    // }

    // Space Optimization
    // TC -> O(n * n)
    // SC -> O(n) + O(n)
    int solve(string &s, string &t, int n, int m)
    {
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = 0 + max(curr[j - 1], prev[j]);
            }

            prev = curr;
        }

        return prev[m];
    }

    int longestPalinSubseq(string A)
    {
        int n = A.length();
        string t = A;
        reverse(t.begin(), t.end());

        // vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        // return solve(A, t, n, n, dp);
        return solve(A, t, n, n);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends