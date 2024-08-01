//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Recursion
    // TC -> exponential
    // SC -> O(n)
    // int solve(int arr[], int start, int end) {
    //     if(start == end) return 0;

    //     int minOperations = INT_MAX;
    //     for(int k = start; k <= end - 1; k++) {
    //         int operations = (arr[start - 1] * arr[k] * arr[end]) + solve(arr, start, k) + solve(arr, k + 1, end);

    //         minOperations = min(minOperations, operations);
    //     }

    //     return minOperations;
    // }

    // Memoization
    // TC -> exponential
    // SC -> O(n*n) + O(n)
    // int solve(int arr[], int start, int end, vector<vector<int>> &dp) {
    //     if(start == end) return 0;

    //     if(dp[start][end] != -1) return dp[start][end];

    //     int minOperations = INT_MAX;
    //     for(int k = start; k <= end - 1; k++) {
    //         int operations = (arr[start - 1] * arr[k] * arr[end]) + solve(arr, start, k, dp) + solve(arr, k + 1, end, dp);

    //         minOperations = min(minOperations, operations);
    //     }

    //     return dp[start][end] = minOperations;
    // }

    // Tabulation
    // TC -> O(n^3)
    // SC -> O(n^2)
    int solve(int arr[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int start = n - 1; start >= 1; start--)
        {
            for (int end = start + 1; end <= n - 1; end++)
            {
                int minOperations = INT_MAX;
                for (int k = start; k <= end - 1; k++)
                {
                    int operations = (arr[start - 1] * arr[k] * arr[end]) + dp[start][k] + dp[k + 1][end];

                    minOperations = min(minOperations, operations);
                }

                dp[start][end] = minOperations;
            }
        }

        return dp[1][n - 1];
    }

    int matrixMultiplication(int N, int arr[])
    {
        // vector<vector<int>> dp(N, vector<int> (N, -1));
        // return solve(arr, 1, N - 1, dp);

        return solve(arr, N);
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
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends