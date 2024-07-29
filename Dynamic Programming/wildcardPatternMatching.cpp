//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // bool isLeadingAsterik(string &p, int m) {
    //     while(m--) if(p[m] != '*') return false;

    //     return true;
    // }

    // Recursion
    // TC -> O(2^m * 2^n)
    // SC -> O(n + m)
    // bool solve(string &s, int n, string &p, int m) {
    //     if(n == 0 and (m == 0 or isLeadingAsterik(p, m))) return true;
    //     if((n == 0 and m > 0) or (n > 0 and m == 0)) return false;

    //     bool isMatch = false;

    //     if(p[m - 1] == '*') {
    //         isMatch = solve(s, n, p, m - 1) || solve(s, n - 1, p, m);
    //     } else if(s[n - 1] == p[m - 1] or p[m - 1] == '?') {
    //         isMatch = solve(s, n - 1, p, m - 1);
    //     }

    //     return isMatch;
    // }

    // Memoization
    // TC -> O(m * n)
    // SC -> O(m * n) + O(n + m)
    // bool solve(string &s, int n, string &p, int m, vector<vector<int>> &dp) {
    //     if(n == 0 and (m == 0 or isLeadingAsterik(p, m))) return true;
    //     if((n == 0 and m > 0) or (n > 0 and m == 0)) return false;

    //     if(dp[n][m] != -1) return dp[n][m];

    //     bool isMatch = false;

    //     if(p[m - 1] == '*') {
    //         isMatch = solve(s, n, p, m - 1, dp) || solve(s, n - 1, p, m, dp);
    //     } else if(s[n - 1] == p[m - 1] or p[m - 1] == '?') {
    //         isMatch = solve(s, n - 1, p, m - 1, dp);
    //     }

    //     return dp[n][m] = isMatch;
    // }

    // Tabulation
    // TC -> O(m * n)
    // SC -> O(m * n) + O(n + m)
    // bool solve(string &s, int n, string &p, int m) {
    //     vector<vector<bool>> dp(n + 1, vector<bool> (m + 1, false));
    //     dp[0][0] = true;

    //     for(int j = 1; j<=m; j++) {
    //         if(p[j - 1] != '*') break;
    //         dp[0][j] = true;
    //     }

    //     for(int i = 1; i<=n; i++) {
    //         for(int j = 1; j<=m; j++) {
    //             bool isMatch = false;

    //             if(p[j - 1] == '*') {
    //                 isMatch = dp[i][j - 1] || dp[i - 1][j];
    //             } else if(s[i - 1] == p[j - 1] or p[j - 1] == '?') {
    //                 isMatch = dp[i - 1][j - 1];
    //             }

    //             dp[i][j] = isMatch;
    //         }
    //     }

    //     return dp[n][m];
    // }

    // Space Optimization
    // TC -> O(m * n)
    // SC -> O(m) + O(m)
    bool solve(string &s, int n, string &p, int m)
    {
        vector<bool> prev(m + 1, false), curr(m + 1, false);
        prev[0] = true;

        for (int j = 1; j <= m; j++)
        {
            if (p[j - 1] != '*')
                break;
            prev[j] = true;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                bool isMatch = false;

                if (p[j - 1] == '*')
                {
                    isMatch = curr[j - 1] || prev[j];
                }
                else if (s[i - 1] == p[j - 1] or p[j - 1] == '?')
                {
                    isMatch = prev[j - 1];
                }

                curr[j] = isMatch;
            }

            prev = curr;
        }

        return prev[m];
    }

    /*You are required to complete this method*/
    int wildCard(string pattern, string str)
    {
        int n = str.length();
        int m = pattern.length();

        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        // return solve(str, n, pattern, m, dp);

        return solve(str, n, pattern, m);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends