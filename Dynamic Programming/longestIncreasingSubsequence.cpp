//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Recursion
    // TC -> O(2 ^ n)
    // SC -> O(n)
    // int solve(int a[], int n, int i, int prevIdx) {
    //     if(i == n) return 0;

    //     int take = 0;
    //     if(prevIdx == -1 or a[prevIdx] < a[i]) take = 1 + solve(a, n, i + 1, i);

    //     int notTake = 0 + solve(a, n, i + 1, prevIdx);

    //     return max(take, notTake);
    // }

    // Memoization
    // TC -> O(n * n)
    // SC -> O(n * n) + O(n)
    // int solve(int a[], int n, int i, int prevIdx, vector<vector<int>> &dp) {
    //     if(i == n) return 0;

    //     if(dp[i][prevIdx + 1] != -1) return dp[i][prevIdx + 1];

    //     int take = 0;
    //     if(prevIdx == -1 or a[prevIdx] < a[i]) take = 1 + solve(a, n, i + 1, i, dp);

    //     int notTake = 0 + solve(a, n, i + 1, prevIdx, dp);

    //     return dp[i][prevIdx + 1] = max(take, notTake);
    // }

    // Tabulation
    // TC -> O(n * n)
    // SC -> O(n * n)
    // int solve(int a[], int n) {
    //     vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

    //     for(int i = n - 1; i>=0; i--) {
    //         for(int prevIdx = i - 1; prevIdx >= -1; prevIdx--) {
    //             int take = 0;
    //             if(prevIdx == -1 or a[prevIdx] < a[i]) take = 1 + dp[i + 1][i + 1];

    //             int notTake = 0 + dp[i + 1][prevIdx + 1];

    //             dp[i][prevIdx + 1] = max(take, notTake);
    //         }
    //     }

    //     return dp[0][-1 + 1];
    // }

    // Space Optimization
    // TC -> O(n * n)
    // SC -> O(n) + O(n)
    // int solve(int a[], int n) {
    //     vector<int> next(n + 1, 0), curr(n + 1, 0);

    //     for(int i = n - 1; i>=0; i--) {
    //         for(int prevIdx = i - 1; prevIdx >= -1; prevIdx--) {
    //             int take = 0;
    //             if(prevIdx == -1 or a[prevIdx] < a[i]) take = 1 + next[i + 1];

    //             int notTake = 0 + next[prevIdx + 1];

    //             curr[prevIdx + 1] = max(take, notTake);
    //         }

    //         next = curr;
    //     }

    //     return next[-1 + 1];
    // }

    // A different Tabulation Approach
    // TC -> O(n^2)
    // SC -> O(n)
    int solve(int a[], int n)
    {
        vector<int> dp(n, 1);

        int longest = 0;
        for (int i = 0; i < n; i++)
        {
            for (int prevIdx = 0; prevIdx < i; prevIdx++)
            {
                if (a[i] > a[prevIdx])
                {
                    dp[i] = max(dp[i], dp[prevIdx] + 1);
                }
            }

            longest = max(longest, dp[i]);
        }

        return longest;
    }

    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        // return solve(a, n, 0, -1, dp);

        return solve(a, n);
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends