//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define ll long long
const int MOD = 1003;

class Solution
{
public:
    // Recursion
    // TC -> O(exponential)
    // SC -> O(n)
    // int solve(string &s, int start, int end, bool isTrue) {
    //     if(start > end) return 0;
    //     if(start == end) {
    //         if(isTrue) return s[start] == 'T';
    //         else return s[start] == 'F';
    //     }

    //     ll ways = 0;
    //     for(int k = start + 1; k <= end - 1; k++) {
    //         ll lT = solve(s, start, k - 1, true);
    //         ll lF = solve(s, start, k - 1, false);
    //         ll rT = solve(s, k + 1, end, true);
    //         ll rF = solve(s, k + 1, end, false);

    //         if(s[k] == '&') {
    //             if(isTrue)
    //                 ways = (ways + (lT * rT) % MOD) % MOD;
    //             else
    //                 ways = (ways + (lT * rF) % MOD + (lF * rT) % MOD + (lF * rF) % MOD) % MOD;
    //         } else if(s[k] == '|') {
    //             if(isTrue)
    //                 ways = (ways + (lT * rF) % MOD + (lF * rT) % MOD + (lT * rT) % MOD) % MOD;
    //             else
    //                 ways = (ways + (lF * rF) % MOD) % MOD;
    //         } else {
    //             if(isTrue)
    //                 ways = (ways + (lT * rF) % MOD + (lF * rT) % MOD) % MOD;
    //             else
    //                 ways = (ways + (lT * rT) % MOD + (lF * rF) % MOD) % MOD;
    //         }
    //     }

    //     return ways;
    // }

    // Memoization
    // TC -> O(n^3 * 2)
    // SC -> O(n^2) + O(n)
    // int solve(string &s, int start, int end, bool isTrue, vector<vector<vector<ll>>> &dp) {
    //     if(start > end) return 0;
    //     if(start == end) {
    //         if(isTrue) return s[start] == 'T';
    //         else return s[start] == 'F';
    //     }

    //     if(dp[start][end][isTrue] != -1) return dp[start][end][isTrue];

    //     ll ways = 0;
    //     for(int k = start + 1; k <= end - 1; k++) {
    //         ll lT = solve(s, start, k - 1, true, dp);
    //         ll lF = solve(s, start, k - 1, false, dp);
    //         ll rT = solve(s, k + 1, end, true, dp);
    //         ll rF = solve(s, k + 1, end, false, dp);

    //         if(s[k] == '&') {
    //             if(isTrue)
    //                 ways = (ways + (lT * rT) % MOD) % MOD;
    //             else
    //                 ways = (ways + (lT * rF) % MOD + (lF * rT) % MOD + (lF * rF) % MOD) % MOD;
    //         } else if(s[k] == '|') {
    //             if(isTrue)
    //                 ways = (ways + (lT * rF) % MOD + (lF * rT) % MOD + (lT * rT) % MOD) % MOD;
    //             else
    //                 ways = (ways + (lF * rF) % MOD) % MOD;
    //         } else {
    //             if(isTrue)
    //                 ways = (ways + (lT * rF) % MOD + (lF * rT) % MOD) % MOD;
    //             else
    //                 ways = (ways + (lT * rT) % MOD + (lF * rF) % MOD) % MOD;
    //         }
    //     }

    //     return dp[start][end][isTrue] = ways;
    // }

    // Tabulation
    // TC -> O(n^3 * 2)
    // SC -> O(n^2)
    int solve(string &s, int n)
    {
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'T')
            {
                dp[i][i][0] = 0;
                dp[i][i][1] = 1;
            }
            else if (s[i] == 'F')
            {
                dp[i][i][0] = 1;
                dp[i][i][1] = 0;
            }
        }

        for (int len = 3; len <= n; len += 2)
        {
            for (int start = 0; start <= n - len; start++)
            {
                int end = start + len - 1;
                for (int isTrue = 0; isTrue <= 1; isTrue++)
                {
                    ll ways = 0;
                    for (int k = start + 1; k <= end - 1; k += 2)
                    {
                        ll lT = dp[start][k - 1][1];
                        ll lF = dp[start][k - 1][0];
                        ll rT = dp[k + 1][end][1];
                        ll rF = dp[k + 1][end][0];

                        if (s[k] == '&')
                        {
                            if (isTrue)
                                ways = (ways + (lT * rT) % MOD) % MOD;
                            else
                                ways = (ways + (lT * rF) % MOD + (lF * rT) % MOD + (lF * rF) % MOD) % MOD;
                        }
                        else if (s[k] == '|')
                        {
                            if (isTrue)
                                ways = (ways + (lT * rF) % MOD + (lF * rT) % MOD + (lT * rT) % MOD) % MOD;
                            else
                                ways = (ways + (lF * rF) % MOD) % MOD;
                        }
                        else if (s[k] == '^')
                        {
                            if (isTrue)
                                ways = (ways + (lT * rF) % MOD + (lF * rT) % MOD) % MOD;
                            else
                                ways = (ways + (lT * rT) % MOD + (lF * rF) % MOD) % MOD;
                        }
                    }

                    dp[start][end][isTrue] = ways;
                }
            }
        }

        return dp[0][n - 1][1];
    }

    int countWays(int n, string s)
    {
        // vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (n, vector<ll> (2, -1)));
        // return solve(s, 0, n - 1, true, dp);

        return solve(s, n);
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
        string s;
        cin >> s;

        Solution ob;
        cout << ob.countWays(n, s) << "\n";
    }
    return 0;
}
// } Driver Code Ends