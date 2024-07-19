//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Using Recursion
    // Time Complexity -> O(2^n)
    // Space Complexity -> O(2^n)
    // int solve(vector<int> &height, int n) {
    //     if(n <= 0) return 0;

    //     int left = solve(height, n - 1) + abs(height[n] - height[n - 1]);
    //     int right = solve(height, n - 2) + abs(height[n] - height[n - 2]);

    //     return min(left, right);
    // }

    // Using Memoization
    // Time Complexity -> O(n)
    // Space Complexity -> O(n) + O(n)
    // int solve(vector<int> &height, int n, vector<int> &dp) {
    //     if(n <= 0) return dp[0] = 0;

    //     if(dp[n] != INT_MAX) return dp[n];

    //     int left = INT_MAX, right = INT_MAX;

    //     left = solve(height, n - 1, dp) + abs(height[n] - height[n - 1]);
    //     if(n > 1) right = solve(height, n - 2, dp) + abs(height[n] - height[n - 2]);

    //     return dp[n] = min(left, right);
    // }

    // Using Tabulation
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)
    // int solve(vector<int> &height, int n, vector<int> &dp) {
    //     dp[0] = 0;

    //     for(int i = 1; i <= n; i++) {
    //         int left = INT_MAX, right = INT_MAX;

    //         left = dp[i - 1] + abs(height[i] - height[i - 1]);
    //         if(i > 1) right = dp[i - 2] + abs(height[i] - height[i - 2]);

    //         dp[i] = min(left, right);
    //     }

    //     return dp[n];
    // }

    // Using Space Optimization
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)
    int solve(vector<int> &height, int n)
    {
        int prev = 0;
        int prevPrev = 0;

        for (int i = 1; i <= n; i++)
        {
            int left = INT_MAX, right = INT_MAX;

            left = prev + abs(height[i] - height[i - 1]);
            if (i > 1)
                right = prevPrev + abs(height[i] - height[i - 2]);

            prevPrev = prev;
            prev = min(left, right);
        }

        return prev;
    }

    int minimumEnergy(vector<int> &height, int n)
    {
        // return solve(height, n - 1);

        // vector<int> dp(n + 1, INT_MAX);
        // return solve(height, n - 1, dp);

        return solve(height, n - 1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends