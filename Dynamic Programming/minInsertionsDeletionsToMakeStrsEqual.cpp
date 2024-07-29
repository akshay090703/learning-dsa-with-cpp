//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    // Recursion with memoization
    // TC -> O(n * m)
    // SC -> O(n * m) + O(n + m)
    // 	int solve(string &str1, string &str2, int n, int m, vector<vector<int>> &dp) {
    // 	    if(n == 0 or m == 0) return 0;

    // 	    if(dp[n][m] != -1) return dp[n][m];

    // 	    if(str1[n - 1] == str2[m - 1])
    // 	        return dp[n][m] = 1 + solve(str1, str2, n - 1, m - 1, dp);

    // 	    return dp[n][m] = 0 + max(solve(str1, str2, n, m - 1, dp), solve(str1, str2, n - 1, m, dp));
    // 	}

    // Tabulation
    // TC -> O(n * m)
    // SC -> O(n * m)
    // 	int solve(string &str1, string &str2, int n, int m) {
    // 	    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

    // 	    for(int i = 1; i<=n; i++) {
    // 	        for(int j = 1; j<=m; j++) {
    //         	    if(str1[i - 1] == str2[j - 1])
    //         	        dp[i][j] = 1 + dp[i - 1][j - 1];
    //         	    else
    //         	        dp[i][j] = 0 + max(dp[i][j - 1], dp[i - 1][j]);
    // 	        }
    // 	    }

    // 	    return dp[n][m];
    // 	}

    // Space Optimization
    // TC -> O(n * m)
    // SC -> O(n) + O(n)
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
                    curr[j] = 0 + max(curr[j - 1], prev[j]);
            }

            prev = curr;
        }

        return prev[m];
    }

    int minOperations(string str1, string str2)
    {
        int n = str1.length();
        int m = str2.length();

        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        // return (n + m) - (2 * solve(str1, str2, n, m, dp));

        return (n + m) - (2 * solve(str1, str2, n, m));
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        Solution ob;
        cout << ob.minOperations(s1, s2) << "\n";
    }
    return 0;
}

// } Driver Code Ends