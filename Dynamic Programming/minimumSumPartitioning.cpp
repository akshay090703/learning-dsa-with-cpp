//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    // simple recursive subsequence problem code with memoization
    // TC -> O(target * n)
    // SC -> O(target * n) + O(n)
    // bool solve(int arr[], int n, int sum, vector<vector<int>> &dp) {
    //     if(sum == 0) return true;
    //     if(n == 0) return arr[0] == sum;

    //     if(dp[n][sum] != -1) return dp[n][sum];

    //     bool pick = false;
    //     if(arr[n] <= sum) pick = solve(arr, n - 1, sum - arr[n]);

    //     bool notPick = solve(arr, n - 1, sum);

    //     return dp[n][sum] = pick || notPick;
    // }

    // Tabulation
    // TC -> O(n * target)
    // SC -> O(n * target)
    // int solve(int arr[], int n, int sum, vector<vector<bool>> &dp) {
    //     for(int i = 0; i<=n; i++) dp[i][0] = true;
    //     if(arr[0] <= sum) dp[0][arr[0]] = true;

    //     for(int i = 1; i<=n; i++) {
    //         for(int target = 1; target <= sum; target++) {
    //             bool pick = false;
    //             if(arr[i] <= target) pick = dp[i - 1][target - arr[i]];

    //             bool notPick = dp[i - 1][target];

    //             dp[i][target] = pick || notPick;
    //         }
    //     }

    //     int minDiff = INT_MAX;
    //     for(int i = 1; i<=sum; i++) {
    //         if(dp[n - 1][i]) minDiff = min(minDiff, abs(sum - (2 * i)));
    //     }

    //     return minDiff;
    // }

    // Space Optimization
    // TC -> O(n * target)
    // SC -> O(n) + O(n)
    int solve(int arr[], int n, int sum)
    {
        vector<bool> curr(sum + 1, false);
        vector<bool> prev(sum + 1, false);

        curr[0] = prev[0] = true;
        if (arr[0] <= sum)
            prev[arr[0]] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int target = 1; target <= sum; target++)
            {
                bool pick = false;
                if (arr[i] <= target)
                    pick = prev[target - arr[i]];

                bool notPick = prev[target];

                curr[target] = pick || notPick;
            }

            prev = curr;
        }

        int minDiff = INT_MAX;
        for (int i = 1; i <= sum; i++)
        {
            if (prev[i])
                minDiff = min(minDiff, abs(sum - (2 * i)));
        }

        return minDiff;
    }

    int minDifference(int arr[], int n)
    {
        if (n == 1)
            return arr[0];
        if (n == 2)
            return abs(arr[0] - arr[1]);

        int sum = accumulate(arr, arr + n, 0);

        // vector<vector<bool>> dp(n, vector<bool> (sum + 1, false));
        // return solve(arr, n - 1, sum, dp);

        return solve(arr, n - 1, sum);
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

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends