#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // using Recursion
    // Time Complexity -> O(2^n)
    // Space Complexity -> O(2^n)
    // int solve(vector<int> &nums, int start, int n) {
    //     if(n == start) return nums[start];
    //     if(n < start) return 0;

    //     int pick = solve(nums, start, n - 2) + nums[n];
    //     int notPick = solve(nums, start, n - 1);

    //     return max(pick, notPick);
    // }

    // Using Memoization
    // Time Complexity -> O(n)
    // Space Complexity -> O(n) + O(n)
    // int solve(vector<int> &nums, int start, int n, int max) {
    //     vector<int> dp(max, -1);
    //     if(n == start) return dp[start] = nums[start];
    //     if(n < start) return 0;

    //     if(dp[n] != -1) return dp[n];

    //     int pick = solve(nums, start, n - 2, dp) + nums[n];
    //     int notPick = solve(nums, start, n - 1, dp);

    //     return dp[n] = max(pick, notPick);
    // }

    // Using Tabulation
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)
    // int solve(vector<int> &nums, int start, int end, int n) {
    //     vector<int> dp(n, -1);
    //     dp[start] = nums[start];

    //     for(int i = start + 1; i<=end; i++) {
    //         int pick = INT_MAX, notPick = INT_MAX;

    //         if(i - 2 >= start) pick = dp[i - 2] + nums[i];
    //         else pick = nums[i];

    //         notPick = dp[i - 1];

    //         dp[i] = max(pick, notPick);
    //     }

    //     return dp[end];
    // }

    // Space Optimization
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)
    int solve(vector<int> &nums, int start, int end)
    {
        int prev = nums[start];
        int prevPrev = 0;

        for (int i = start + 1; i <= end; i++)
        {
            int pick = prevPrev + nums[i];
            int notPick = prev;

            prevPrev = prev;
            prev = max(pick, notPick);
        }

        return prev;
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        // return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));

        if (n == 1)
            return nums[0];
        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
        // return max(solve(nums, 0, n - 2, n), solve(nums, 1, n - 1, n));

        // return max(solve(nums, 0, n - 2, n), solve(nums, 1, n - 1, n));
    }
};

int main()
{

    return 0;
}