//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Recursion
    // TC -> O(exponential)
    // SC -> O(n)
    // int solve(vector<int> &arr, int start, int n, int len) {
    //     if(start >= n) return 0;

    //     int maxSum = 0;
    //     int maxVal = arr[start];

    //     for(int k = 1; k <= len and start + k <= n; k++) {
    //         maxVal = max(maxVal, arr[start + k - 1]);
    //         maxSum = max(maxSum, (maxVal * k) + solve(arr, start + k, n, len));
    //     }

    //     return maxSum;
    // }

    // Memoization
    // TC -> O(n*n*k)
    // SC -> O(n) + O(n)
    // int solve(vector<int> &arr, int start, int n, int len, vector<int> &dp) {
    //     if(start >= n) return 0;

    //     if(dp[start] != -1) return dp[start];

    //     int maxSum = 0;
    //     int maxVal = arr[start];

    //     for(int k = 1; k <= len and start + k <= n; k++) {
    //         maxVal = max(maxVal, arr[start + k - 1]);
    //         maxSum = max(maxSum, (maxVal * k) + solve(arr, start + k, n, len, dp));
    //     }

    //     return dp[start] = maxSum;
    // }

    // Tabulation
    // TC -> O(n*n*k)
    // SC -> O(n)
    int solve(vector<int> &arr, int n, int len)
    {
        vector<int> dp(n + 1, 0);

        for (int start = n - 1; start >= 0; start--)
        {
            int maxSum = 0;
            int maxVal = arr[start];

            for (int k = 1; k <= len and start + k <= n; k++)
            {
                maxVal = max(maxVal, arr[start + k - 1]);
                maxSum = max(maxSum, (maxVal * k) + dp[start + k]);
            }

            dp[start] = maxSum;
        }

        return dp[0];
    }

    int solve(int n, int k, vector<int> &arr)
    {
        // vector<int> dp(n, -1);
        // return solve(arr, 0, n, k, dp);

        return solve(arr, n, k);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr;

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.solve(n, k, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends