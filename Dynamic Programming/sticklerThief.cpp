//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
public:
    // Using Recursion
    // Time Complexity -> O(2^n)
    // Space Complexity -> O(2^n)
    // int solve(int arr[], int n) {
    //     if(n == 0) return arr[0];
    //     if(n < 0) return 0;

    //     int pick = solve(arr, n - 2) + arr[n];
    //     int notPick = solve(arr, n - 1);

    //     return max(pick, notPick);
    // }

    // using Memoization
    // Time Complexity -> O(n)
    // Space Complexity -> O(n) + O(n)
    // int solve(int arr[], int n, vector<int> &dp) {
    //     if(n == 0) return dp[0] = arr[0];
    //     if(n < 0) return 0;

    //     if(dp[n] != -1) return dp[n];

    //     int pick = solve(arr, n - 2, dp) + arr[n];
    //     int notPick = solve(arr, n - 1, dp);

    //     return dp[n] = max(pick, notPick);
    // }

    // Using Tabulation
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)
    // int solve(int arr[], int n, vector<int> &dp) {
    //     dp[0] = arr[0];

    //     for(int i = 1; i<=n; i++) {
    //         int pick = INT_MIN, notPick = INT_MIN;

    //         if(i - 2 >= 0) pick = dp[i - 2] + arr[i];
    //         else pick = arr[i];

    //         notPick = dp[i - 1];

    //         dp[i] = max(pick, notPick);
    //     }

    //     return dp[n];
    // }

    // Space Optimization
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)
    int solve(int arr[], int n)
    {
        int prev = arr[0];
        int prevPrev = 0;

        for (int i = 1; i < n; i++)
        {
            int curr = max(prev, prevPrev + arr[i]);

            prevPrev = prev;
            prev = curr;
        }

        return prev;
    }

    int FindMaxSum(int arr[], int n)
    {
        // return solve(arr, n - 1);

        // vector<int> dp(n, -1);
        // return solve(arr, n - 1, dp);

        return solve(arr, n);
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking number of houses
        int n;
        cin >> n;
        int a[n];

        // inserting money of each house in the array
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        // calling function FindMaxSum()
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends