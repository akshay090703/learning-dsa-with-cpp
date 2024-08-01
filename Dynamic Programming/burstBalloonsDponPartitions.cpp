//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Recursion
    // TC -> O(exponential) * O(n)
    // SC -> O(n)
    // int solve(vector<int> &arr, int start, int end) {
    //     if(start > end) return 0;

    //     int maxCoins = 0;
    //     for(int k = start; k <= end; k++) {
    //         int coins = (arr[start - 1] * arr[k] * arr[end + 1]) + solve(arr, start, k - 1) + solve(arr, k + 1, end);

    //         maxCoins = max(maxCoins, coins);
    //     }

    //     return maxCoins;
    // }

    // Memoization
    // TC -> O(n^3)
    // SC -> O(n^2) + O(n)
    // int solve(vector<int> &arr, int start, int end, vector<vector<int>> &dp) {
    //     if(start > end) return 0;

    //     if(dp[start][end] != -1) return dp[start][end];

    //     int maxCoins = 0;
    //     for(int k = start; k <= end; k++) {
    //         int coins = (arr[start - 1] * arr[k] * arr[end + 1]) + solve(arr, start, k - 1, dp) + solve(arr, k + 1, end, dp);

    //         maxCoins = max(maxCoins, coins);
    //     }

    //     return dp[start][end] = maxCoins;
    // }

    // Tabulation
    // TC -> O(n^3)
    // SC -> O(n^2) + O(n)
    int solve(vector<int> &arr, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int start = n - 2; start >= 1; start--)
        {
            for (int end = start; end <= n - 2; end++)
            {
                int maxCoins = 0;
                for (int k = start; k <= end; k++)
                {
                    int coins = (arr[start - 1] * arr[k] * arr[end + 1]) + dp[start][k - 1] + dp[k + 1][end];

                    maxCoins = max(maxCoins, coins);
                }

                dp[start][end] = maxCoins;
            }
        }

        return dp[1][n - 2];
    }

    int maxCoins(int N, vector<int> &arr)
    {
        arr.insert(arr.begin(), 1);
        arr.push_back(1);
        N = arr.size();

        // vector<vector<int>> dp(N, vector<int> (N, -1));
        // return solve(arr, 1, N - 2, dp);

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

        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends