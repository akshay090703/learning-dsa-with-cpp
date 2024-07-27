//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
public:
    // Recursion
    // TC -> O(2^n * 2^m)
    // SC -> O(n + m)
    // int solve(string &str1, int n, string &str2, int m) {
    //     if(n == 0 or m == 0) return 0;

    //     if(str1[n - 1] == str2[m - 1])
    //         return 1 + solve(str1, n - 1, str2, m - 1);

    //     return 0 + max(solve(str1, n - 1, str2, m), solve(str1, n, str2, m - 1));
    // }

    // Memoization
    // TC -> O(n*m)
    // SC -> O(n*m) + O(n + m)
    // int solve(string &str1, int n, string &str2, int m, vector<vector<int>> &dp) {
    //     if(n == 0 or m == 0) return 0;

    //     if(dp[n][m] != -1) return dp[n][m];

    //     if(str1[n - 1] == str2[m - 1])
    //         return dp[n][m] = 1 + solve(str1, n - 1, str2, m - 1, dp);

    //     return dp[n][m] = 0 + max(solve(str1, n - 1, str2, m, dp), solve(str1, n, str2, m - 1, dp));
    // }

    // Tabulation
    // TC -> O(n*m)
    // SC -> O(n*m)
    // int solve(string &str1, int n, string &str2, int m, vector<vector<int>> &dp) {
    //     for(int i = 0; i<=m; i++) dp[0][i] = 0;
    //     for(int i = 0; i<=n; i++) dp[i][0] = 0;

    //     for(int i = 1; i<=n; i++) {
    //         for(int j = 1; j<=m; j++) {
    //             if(str1[i - 1] == str2[j - 1])
    //                 dp[i][j] = 1 + dp[i - 1][j - 1];
    //             else
    //                 dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
    //         }
    //     }

    //     return dp[n][m];
    // }

    // Space Optimization
    // TC -> O(n*m)
    // SC -> O(n) + O(n)
    int solve(string &str1, int n, string &str2, int m)
    {
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // for(int i = 0; i<=m; i++) dp[0][i] = 0;
        // for(int i = 0; i<=n; i++) dp[i][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = 0 + max(prev[j], curr[j - 1]);
            }

            prev = curr;
        }

        return prev[m];
    }

    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string str1, string str2)
    {
        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        // return solve(str1, n, str2, m, dp);

        return solve(str1, n, str2, m);
    }
};

//{ Driver Code Starts.
int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m; // Take size of both the strings as input
        string str1, str2;
        cin >> str1 >> str2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, str1, str2) << endl;
    }
    return 0;
}

// } Driver Code Ends