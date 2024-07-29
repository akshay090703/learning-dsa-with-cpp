//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Recursion with memoization
    // TC -> O(n * m)
    // SC -> O(n * m) + O(n + m)
    // int solve(string &str1, string &str2, int n, int m, vector<vector<int>> &dp) {
    //     if(n == 0 or m == 0) return 0;

    //     if(dp[n][m] != -1) return dp[n][m];

    //     if(str1[n - 1] == str2[m - 1])
    //         return dp[n][m] = 1 + solve(str1, str2, n - 1, m - 1, dp);

    //     return dp[n][m] = 0 + max(solve(str1, str2, n - 1, m, dp), solve(str1, str2, n, m - 1, dp));
    // }

    // Tabulation
    // TC -> O(n * m) + O(n + m)
    // SC -> O(n * m) + O(length of supersequence)
    // int solve(string &str1, string &str2, int n, int m) {
    //     vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

    //     for(int i = 1; i<=n; i++) {
    //         for(int j = 1; j<=m; j++) {
    //             if(str1[i - 1] == str2[j - 1])
    //                 dp[i][j] = 1 + dp[i - 1][j - 1];
    //             else
    //                 dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
    //         }
    //     }

    //     // string result = "";
    //     // int i = m, j = n;

    //     // while(i > 0 and j > 0) {
    //     //     if(str1[i - 1] == str2[j - 1]) {
    //     //         result.push_back(str1[i - 1]);
    //     //         i--;
    //     //         j--;
    //     //     } else {
    //     //         if(dp[i - 1][j] >= dp[i][j - 1]) {
    //     //             result.push_back(str1[i - 1]);
    //     //             i--;
    //     //         } else {
    //     //             result.push_back(str2[j - 1]);
    //     //             j--;
    //     //         }
    //     //     }
    //     // }

    //     // reverse(result.begin(), result.end());

    //     return dp[n][m];
    // }

    // Space Optimization
    // TC -> O(n * m)
    // SC -> O(m) + O(m)
    int solve(string &str1, string &str2, int n, int m)
    {
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

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

    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int n, int m)
    {
        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        // return solve(X, Y, n, m, dp);

        return (n + m) - solve(X, Y, n, m);
    }
};

//{ Driver Code Starts.

int main()
{

    int t;

    // taking total testcases
    cin >> t;
    while (t--)
    {
        string X, Y;
        // taking String X and Y
        cin >> X >> Y;

        // calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size()) << endl;
    }
    return 0;
}

// } Driver Code Ends