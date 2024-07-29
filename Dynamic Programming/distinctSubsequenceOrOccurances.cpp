//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
public:
    const int MOD = 1000000007;

    // Recursion
    // TC -> O(2^n * 2^m)
    // SC -> O(n + m)
    // int solve(string &s, string &t, int n, int m) {
    //     if(m == 0) return 1;
    //     if(n == 0) return 0;

    //     if(s[n - 1] == t[m - 1])
    //         return (solve(s, t, n - 1, m - 1) + solve(s, t, n - 1, m)) % MOD;

    //     return solve(s, t, n - 1, m) % MOD;
    // }

    // Memoization
    // TC -> O(2^n * 2^m)
    // SC -> O(n * m) + O(n + m)
    // int solve(string &s, string &t, int n, int m, vector<vector<int>> &dp) {
    //     if(m == 0) return 1;
    //     if(n == 0) return 0;

    //     if(dp[n][m] != -1) return dp[n][m];

    //     if(s[n - 1] == t[m - 1])
    //         return dp[n][m] = (solve(s, t, n - 1, m - 1, dp) + solve(s, t, n - 1, m, dp)) % MOD;

    //     return dp[n][m] = solve(s, t, n - 1, m, dp) % MOD;
    // }

    // Tabulation
    // TC -> O(n * m)
    // SC -> O(n * m)
    // int solve(string &s, string &t, int n, int m) {
    //     vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    //     for(int i = 0; i<=n; i++) dp[i][0] = 1;

    //     for(int i = 1; i<=n; i++) {
    //         for(int j = 1; j<=m; j++) {
    //             if(s[i - 1] == t[j - 1])
    //                 dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
    //             else
    //                 dp[i][j] = dp[i - 1][j] % MOD;
    //         }
    //     }

    //     return dp[n][m];
    // }

    // Space Optimization
    // TC -> O(n * m)
    // SC -> O(m)
    int solve(string &s, string &t, int n, int m)
    {
        vector<int> prev(m + 1, 0);
        prev[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j > 0; j--)
            {
                if (s[i - 1] == t[j - 1])
                    prev[j] = (prev[j - 1] + prev[j]) % MOD;
                else
                    prev[j] = prev[j] % MOD;
            }
        }

        return prev[m];
    }

    int subsequenceCount(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        // return solve(s, t, n, m, dp);

        return solve(s, t, n, m);
    }
};

//{ Driver Code Starts.

//  Driver code to check above method
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        string tt;
        cin >> s;
        cin >> tt;

        Solution ob;
        cout << ob.subsequenceCount(s, tt) << endl;
    }
}
// } Driver Code Ends