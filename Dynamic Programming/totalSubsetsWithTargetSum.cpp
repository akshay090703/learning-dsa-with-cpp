//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    const int MOD = 1000000007;

    // Using Recursion and memoization
    // TC -> O(sum * n)
    // SC -> O(sum * n) + O(n)
    // 	int solve(vector<int> &nums, int sum, int n, vector<vector<int>> &dp) {
    //         if(sum == 0) return 1;
    //         if(n == 0) return sum == nums[0];

    //         if(dp[n][sum] != -1) return dp[n][sum];

    //         int pick = 0;
    //         if(nums[n] <= sum) pick = solve(nums, sum - nums[n], n - 1, dp);

    //         int notPick = solve(nums, sum, n - 1, dp);

    //         return dp[n][sum] = (pick + notPick) % MOD;
    // 	}

    // Tabulation
    // TC -> O(sum * n)
    // SC -> O(sum * n)
    // 	int solve(vector<int> &nums, int sum, int n, vector<vector<int>> &dp) {
    // 	    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    // 	    if(nums[0] <= sum) dp[0][nums[0]] = 1;

    // 	    for(int i = 1; i<=n; i++) {
    // 	        for(int target = 1; target<=sum; target++) {
    //                 int pick = 0;
    //                 if(nums[i] <= target) pick = dp[i - 1][target - nums[i]];

    //                 int notPick = dp[i - 1][target];

    //                 dp[i][target] = (pick + notPick) % MOD;
    // 	        }
    // 	    }

    // 	    return dp[n][sum];
    // 	}

    // Space Optimization
    // TC -> O(sum * n)
    // SC -> O(n) + O(n)
    int solve(vector<int> &nums, int sum, int n)
    {
        vector<int> curr(sum + 1, 0);
        vector<int> prev(sum + 1, 0);

        curr[0] = prev[0] = 1;
        if (nums[0] <= sum)
            prev[nums[0]] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int target = 1; target <= sum; target++)
            {
                int pick = 0;
                if (nums[i] <= target)
                    pick = prev[target - nums[i]];

                int notPick = prev[target];

                curr[target] = (pick + notPick) % MOD;
            }

            prev = curr;
        }

        return prev[sum];
    }

    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
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

        // return (solve(nums, sum, nums.size() - 1, dp) * (1 << zeros)) % MOD;

        return (solve(nums, sum, nums.size() - 1) * (1 << zeros)) % MOD;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";
    }
    return 0;
}

// } Driver Code Ends