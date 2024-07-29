//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Recursion
    // TC -> O(3^n * 3^m)
    // SC -> O(n + m)
    // int solve(string &word1, string &word2, int n, int m) {
    //     if(m == 0) return n;
    //     if(n == 0) return m;

    //     if(word1[n - 1] == word2[m - 1])
    //         return 0 + solve(word1, word2, n - 1, m - 1);

    //     int insert = 1 + solve(word1, word2, n, m - 1);
    //     int remov = 1 + solve(word1, word2, n - 1, m);
    //     int replace = 1 + solve(word1, word2, n - 1, m - 1);

    //     return min({insert, remov, replace});
    // }

    // Memoization
    // TC -> O(n * m)
    // SC -> O(n * m) + O(n + m)
    // int solve(string &word1, string &word2, int n, int m, vector<vector<int>> &dp) {
    //     if(m == 0) return n;
    //     if(n == 0) return m;

    //     if(dp[n][m] != -1) return dp[n][m];

    //     if(word1[n - 1] == word2[m - 1])
    //         return dp[n][m] = 0 + solve(word1, word2, n - 1, m - 1, dp);

    //     int insert = 1 + solve(word1, word2, n, m - 1, dp);
    //     int remov = 1 + solve(word1, word2, n - 1, m, dp);
    //     int replace = 1 + solve(word1, word2, n - 1, m - 1, dp);

    //     return dp[n][m] = min({insert, remov, replace});
    // }

    // Tabulation
    // TC -> O(n * m)
    // SC -> O(n * m)
    // int solve(string &word1, string &word2, int n, int m) {
    //     vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

    //     for(int i = 0; i<=n; i++) dp[i][0] = i;
    //     for(int j = 0; j<=m; j++) dp[0][j] = j;

    //     for(int i = 1; i<=n; i++) {
    //         for(int j = 1; j<=m; j++) {
    //             if(word1[i - 1] == word2[j - 1]) {
    //                 dp[i][j] = 0 + dp[i - 1][j - 1];
    //             } else {
    //                 int insert = 1 + dp[i][j - 1];
    //                 int remov = 1 + dp[i - 1][j];
    //                 int replace = 1 + dp[i - 1][j - 1];

    //                 dp[i][j] = min({insert, remov, replace});
    //             }
    //         }
    //     }

    //     return dp[n][m];
    // }

    // Space Optimization
    // TC -> O(n * m)
    // SC -> O(m) + O(m)
    int solve(string &word1, string &word2, int n, int m)
    {
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int j = 0; j <= m; j++)
            prev[j] = j;

        for (int i = 1; i <= n; i++)
        {
            curr[0] = i;

            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    curr[j] = 0 + prev[j - 1];
                }
                else
                {
                    int insert = 1 + curr[j - 1];
                    int remov = 1 + prev[j];
                    int replace = 1 + prev[j - 1];

                    curr[j] = min({insert, remov, replace});
                }
            }

            prev = curr;
        }

        return prev[m];
    }

    int editDistance(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        // return solve(s, t, n, m, dp);

        return solve(s, t, n, m);
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends