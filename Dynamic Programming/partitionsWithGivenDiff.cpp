//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    const int MOD = 1000000007;

    // Using Recursion with Memoization
    // TC -> O(n * target)
    // SC -> O(n * target) + O(n)
    // int solve(vector<int> &arr, int n, int sum, vector<vector<int>> &dp) {
    //     // Used to tackle cases with 0s
    //     if(n == 0) {
    //         if(sum == 0 and arr[0] == 0) return 2;
    //         if(sum == arr[0] or sum == 0) return 1;
    //         return 0;
    //     };

    //     if(dp[n][sum] != -1) return dp[n][sum];

    //     int pick = 0;
    //     if(arr[n] <= sum) pick = solve(arr, n - 1, sum - arr[n], dp);

    //     int notPick = solve(arr, n - 1, sum, dp);

    //     return dp[n][sum] = (pick + notPick) % MOD;
    // }

    // Using Tabulation
    // TC -> O(n * target)
    // SC -> O(n * target)
    // int solve(vector<int> &arr, int n, int sum, vector<vector<int>> &dp) {
    // for(int i = 0; i <= n; i++) dp[i][0] = 1;
    // if(arr[0] <= sum) dp[0][arr[0]] = 1;

    // for(int i = 1; i<=n; i++) {
    //     for(int target = 1; target<=sum; target++) {
    //             int pick = 0;
    //             if(arr[i] <= target) pick = dp[i - 1][target - arr[i]];

    //             int notPick = dp[i - 1][target];

    //             dp[i][target] = (pick + notPick) % MOD;
    //     }
    // }

    // return dp[n][sum];
    // }

    // Using Space Optimization
    // TC -> O(n * target)
    // SC -> O(n) + O(n)
    int solve(vector<int> &arr, int n, int sum)
    {
        vector<int> curr(sum + 1, 0), prev(sum + 1, 0);

        curr[0] = prev[0] = 1;
        if (arr[0] <= sum)
            prev[arr[0]] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int target = 1; target <= sum; target++)
            {
                int pick = 0;
                if (arr[i] <= target)
                    pick = prev[target - arr[i]];

                int notPick = prev[target];

                curr[target] = (pick + notPick) % MOD;
            }

            prev = curr;
        }

        return prev[sum];
    }

    int countPartitions(int n, int d, vector<int> &arr)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);

        if ((sum % 2 == 1 and d % 2 == 0) or (sum % 2 == 0 and d % 2 == 1))
            return 0;

        int reqSum = (sum / 2) - (d / 2);

        if (reqSum < 0)
            return 0;

        vector<int> nums;

        int zeros = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                zeros++;
            }
            else
            {
                nums.push_back(arr[i]);
            }
        };

        // vector<vector<int>> dp(n, vector<int> (reqSum + 1, 0));
        int result = nums.size() == 0 ? 1 : solve(nums, nums.size() - 1, reqSum);

        for (int i = 0; i < zeros; i++)
        {
            result = (result * 2) % MOD;
        }

        return result;

        // return solve(arr, n - 1, reqSum);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends