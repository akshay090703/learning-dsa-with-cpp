//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Recursion with Memoization
    // TC -> O(n * m)
    // SC -> O(n * m * max(n, m)) + O(n + m)
    // int solve(string &S1, string &S2, int n, int m, int count, vector<vector<vector<int>>> &dp) {
    //     if(n == 0 or m == 0) return count;

    //     if(dp[n][m][count] != -1) return dp[n][m][count];

    //     int currCount = count;

    //     if(S1[n - 1] == S2[m - 1]) {
    //         currCount = solve(S1, S2, n - 1, m - 1, count + 1, dp);
    //     }

    //     int skip1 = solve(S1, S2, n - 1, m, 0, dp);
    //     int skip2 = solve(S1, S2, n, m - 1, 0, dp);

    //     return dp[n][m][count] = max(currCount, max(skip1, skip2));
    // }

    // Tabulation
    // TC -> O(n * m)
    // SC -> O(n * m)
    // int solve(string &S1, string &S2, int n, int m, int count, vector<vector<int>> &dp) {
    //     for(int i = 1; i<=n; i++) {
    //         for(int j = 1; j<=m; j++) {
    //             if(S1[i - 1] == S2[j - 1]) {
    //                 dp[i][j] = dp[i - 1][j - 1] + 1;
    //             }
    //         }
    //     }

    //     int maxSubstr = 0;
    //     for(int i = 1; i<=n; i++) {
    //         maxSubstr = max(maxSubstr, *max_element(dp[i].begin(), dp[i].end()));
    //     }

    //     return maxSubstr;
    // }

    // Space Optimization
    // TC -> O(n * m)
    // SC -> O(m) + O(m)
    int solve(string &S1, string &S2, int n, int m)
    {
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        int maxSubstr = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (S1[i - 1] == S2[j - 1])
                {
                    curr[j] = prev[j - 1] + 1;
                    maxSubstr = max(maxSubstr, curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }

            prev = curr;
        }

        return maxSubstr;
    }

    int longestCommonSubstr(string &S1, string &S2, int n, int m)
    {
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (m + 1, vector<int> (max(n, m) + 1, -1)));
        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        // return solve(S1, S2, n, m, 0, dp);

        return solve(S1, S2, n, m);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends