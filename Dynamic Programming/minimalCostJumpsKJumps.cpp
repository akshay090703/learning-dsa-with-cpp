//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Recursion
    // Time Complexity -> O(k^n)
    // Space Complexity -> O(k^n)
    // int solve(vector<int> &height, int n, int k) {
    //     if(n <= 0) return 0;

    //     int minCost = INT_MAX;
    //     for(int i = 1; i<=k; i++) {
    //         if(n - i >= 0) minCost = min(minCost, solve(height, n - i, k) + abs(height[n] - height[n - i]));
    //     }

    //     return minCost;
    // }

    // Using Memoization
    // Time Complexity -> O(n*k)
    // Space Complexity -> O(n) + O(n)
    // int solve(vector<int> &height, int n, int k, vector<int> &dp) {
    //     if(n <= 0) {
    //         return dp[0] = 0;
    //     }

    //     if(dp[n] != -1) {
    //         return dp[n];
    //     }

    //     int minCost = INT_MAX;
    //     for(int i = 1; i<=k; i++) {
    //         if(n - i >= 0) minCost = min(minCost, solve(height, n - i, k, dp) + abs(height[n] - height[n - i]));
    //     }

    //     return dp[n] = minCost;
    // }

    // Using Tabulation
    // Time Complexity -> O(n*k)
    // Space Complexity -> O(n)
    int solve(vector<int> &heights, int n, int k, vector<int> &dp)
    {
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            int minCost = INT_MAX;

            for (int j = 1; j <= k; j++)
            {
                if (i - j >= 0)
                    minCost = min(minCost, dp[i - j] + abs(heights[i] - heights[i - j]));
            }

            dp[i] = minCost;
        }

        return dp[n];
    }

    int minimizeCost(vector<int> &height, int n, int k)
    {
        // return solve(height, n - 1, k);

        vector<int> dp(n + 1, -1);
        return solve(height, n - 1, k, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends