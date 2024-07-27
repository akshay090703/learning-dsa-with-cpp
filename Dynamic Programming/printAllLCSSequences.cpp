//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Recursion with Memoization
    // TC -> O(n * m)
    // SC -> O(n * m) + O(n + m)
    // int solve(string &s, int n, string &t, int m, vector<string> &result, vector<vector<int>> &dp) {
    //     if(n == 0 or m == 0) return 0;

    //     if(dp[n][m] != -1) return dp[n][m];

    //     if(s[n - 1] == t[m - 1])
    //         return dp[n][m] = 1 + solve(s, n - 1, t, m - 1, result, dp);

    //     return dp[n][m] = 0 + max(solve(s, n - 1, t, m, result, dp), solve(s, n, t, m - 1, result, dp));
    // }

    // Tabulation
    // TC -> O(n * m)
    // SC -> O(n * m)
    vector<vector<int>> solve(string &s, int n, string &t, int m)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // for(int i = 0; i<=m; i++) dp[0][i] = 0;
        // for(int i = 0; i<=n; i++) dp[i][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp;
    }

    void backtrackAllLCS(const vector<vector<int>> &dp, const string &s, const string &t, int i, int j, string &currentLCS, set<string> &allLCS, unordered_map<string, set<string>> &memo)
    {
        if (i == 0 or j == 0)
        {
            reverse(currentLCS.begin(), currentLCS.end());
            allLCS.insert(currentLCS);
            reverse(currentLCS.begin(), currentLCS.end()); // to restore for other recursive calls
            return;
        }

        string key = to_string(i) + "," + to_string(j) + "," + currentLCS;
        if (memo.find(key) != memo.end())
        {
            allLCS.insert(memo[key].begin(), memo[key].end());
            return;
        }

        if (s[i - 1] == t[j - 1])
        {
            currentLCS.push_back(s[i - 1]);
            backtrackAllLCS(dp, s, t, i - 1, j - 1, currentLCS, allLCS, memo);
            currentLCS.pop_back();
        }
        else
        {
            if (dp[i - 1][j] >= dp[i][j - 1])
            {
                backtrackAllLCS(dp, s, t, i - 1, j, currentLCS, allLCS, memo);
            }

            if (dp[i - 1][j] <= dp[i][j - 1])
            {
                backtrackAllLCS(dp, s, t, i, j - 1, currentLCS, allLCS, memo);
            }
        }

        memo[key] = allLCS;
    }

    // Main function to find all LCS
    vector<string> all_longest_common_subsequences(string &s, string &t)
    {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp = solve(s, n, t, m);
        set<string> allLCS;
        string currentLCS;
        unordered_map<string, set<string>> memo;

        backtrackAllLCS(dp, s, t, n, m, currentLCS, allLCS, memo);

        vector<string> result(allLCS.begin(), allLCS.end());

        return result;
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
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends