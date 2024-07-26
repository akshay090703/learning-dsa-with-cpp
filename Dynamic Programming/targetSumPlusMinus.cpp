//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution
{
public:
    // Recursion with memoization
    // TC -> O(n * reqSum)
    // SC -> O(n * reqSum) + O(n)
    // long long solve(vector<int> &nums, int n, int sum, vector<vector<long long>> &dp) {
    //     if(sum == 0) return 1;
    //     if(n == 0) return nums[0] == sum;

    //     if(dp[n][sum] != -1) return dp[n][sum];

    //     int pick = 0;
    //     if(nums[n] <= sum) pick = solve(nums, n - 1, sum - nums[n], dp);

    //     int notPick = solve(nums, n - 1, sum, dp);

    //     return dp[n][sum] = pick + notPick;
    // }

    // Tabulation
    // TC -> O(n * reqSum)
    // SC -> O(n * reqSum)
    // long long solve(vector<int> &nums, int n, int sum, vector<vector<long long>> &dp) {
    //     for(int i = 0; i<=n; i++) dp[i][0] = 1;
    //     if(nums[0] <= sum) dp[0][nums[0]] = 1;

    //     for(int i = 1; i<=n; i++) {
    //         for(int target = 1; target <= sum; target++) {
    //             int pick = 0;
    //             if(nums[i] <= target) pick = dp[i - 1][target - nums[i]];

    //             int notPick = dp[i - 1][target];

    //             dp[i][target] = pick + notPick;
    //         }
    //     }

    //     return dp[n][sum];
    // }

    // Space Optimization
    // TC -> O(n * reqSum)
    // SC -> O(n) + O(n)
    long long solve(vector<int> &nums, int n, int sum)
    {
        vector<long long> prev(sum + 1, 0), curr(sum + 1, 0);

        prev[0] = curr[0] = 1;
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

                curr[target] = pick + notPick;
            }

            prev = curr;
        }

        return prev[sum];
    }

    long long findTargetSumWays(int n, vector<int> &A, int target)
    {
        int sum = accumulate(A.begin(), A.end(), 0);

        if ((sum - target) % 2 != 0 or sum < target)
            return 0;

        int reqSum = (sum - target) / 2;
        vector<int> nums;

        int zeros = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == 0)
                zeros++;
            else
                nums.push_back(A[i]);
        }

        int m = nums.size();
        // vector<vector<long long>> dp(m, vector<long long> (reqSum + 1, 0));
        // return solve(nums, m - 1, reqSum, dp) * (1 << zeros);
        return solve(nums, m - 1, reqSum) * (1 << zeros);
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
        int target;
        cin >> target;

        Solution ob;
        cout << ob.findTargetSumWays(N, arr, target);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends