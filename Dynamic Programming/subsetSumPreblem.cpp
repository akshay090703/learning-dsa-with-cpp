//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Recursion
    // TC -> O(2^n)
    // SC -> O(n)
    // bool solve(vector<int> &arr, int n, int sum) {
    //     if(sum == 0) return true;
    //     if(n < 0) return false;

    //     bool pick = solve(arr, n - 1, sum - arr[n]);
    //     bool nonPick = pick ? true : solve(arr, n - 1, sum);

    //     return pick || nonPick;
    // }

    // Using Memoization
    // TC -> O(n * target)
    // SC -> O(n * target) + O(n)
    // bool solve(vector<int> &arr, int n, int sum, vector<vector<int>> &dp) {
    //     if(sum == 0) return 1;
    //     if(n == 0) return arr[0] == sum;

    //     if(dp[n][sum] != -1) return dp[n][sum];

    //     bool pick = false;
    //     if(arr[n] <= sum) pick = solve(arr, n - 1, sum - arr[n], dp);

    //     bool notPick = pick ? true : solve(arr, n - 1, sum, dp);

    //     return dp[n][sum] = pick || notPick;
    // }

    // Using Tabulation
    // TC -> O(n * target)
    // SC -> O(n * target)
    // bool solve(vector<int> &arr, int n, int sum, vector<vector<int>> &dp) {
    //     for(int i = 0; i<n; i++) {
    //         dp[i][0] = 1;
    //     }

    //     if(arr[0] <= sum) {
    //         dp[0][arr[0]] = 1;
    //     }

    //     for(int i = 1; i<n; i++) {
    //         for(int target = 1; target <= sum; target++) {
    //             bool pick = false;
    //             if(arr[i] <= target) pick = dp[i - 1][target - arr[i]];

    //             bool notPick = dp[i - 1][target];

    //             dp[i][target] = pick || notPick;
    //         }
    //     }

    //     return dp[n - 1][sum];
    // }

    // Using Space Optimization
    // TC -> O(n * target)
    // SC -> O(target) + O(target)
    bool solve(vector<int> &arr, int n, int sum)
    {
        vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
        prev[0] = curr[0] = true;
        if (arr[0] <= sum)
            prev[arr[0]] = 1;

        for (int i = 1; i < n; i++)
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

        return prev[sum];
    }

    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        // return solve(arr, n - 1, sum);

        // vector<vector<int>> dp(n, vector<int> (sum + 1, 0));
        // return solve(arr, n - 1, sum, dp);

        // return solve(arr, n, sum, dp);

        return solve(arr, n, sum);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0;
}

// } Driver Code Ends