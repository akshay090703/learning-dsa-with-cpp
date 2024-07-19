#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // using recursion
    // Time Complexity -> O(2^n)
    // Space Complexity -> O(2^n)
    // int climbStairs(int n) {
    //     if(n == 0) return 1;
    //     if(n < 0) return 0;

    //     int ans = 0;

    //     ans += climbStairs(n - 1);
    //     ans += climbStairs(n - 2);

    //     return ans;
    // }

    // Memoization
    // Time Complexity -> O(n)
    // Space Complexity -> O(n) + O(n)
    // int solve(int n, vector<int> &dp) {
    //     if(n == 0) {
    //         dp[0] = 1;
    //         return dp[0];
    //     } else if(n < 0) return 0;

    //     if(dp[n] != -1) return dp[n];

    //     int left = 0, right = 0;

    //     left += solve(n - 1, dp);
    //     right += solve(n - 2, dp);

    //     return dp[n] = left + right;
    // }

    // Using Tabulation
    // Space Complexity ->
    // Time Complexity ->
    // int solve(int n, vector<int> &dp) {
    //     for(int i = 2; i <= n; i++) {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }

    //     return dp[n];
    // }

    // Using Space Optimization
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)
    int solve(int n)
    {
        int prev = 1;
        int prevPrev = 1;
        for (int i = 2; i <= n; i++)
        {
            int curr = prevPrev + prev;

            prevPrev = prev;
            prev = curr;
        }

        return prev;
    }

    int climbStairs(int n)
    {
        // vector<int> dp(n + 1, -1);
        // dp[0] = 1;
        // dp[1] = 1;
        // return solve(n, dp);

        return solve(n);
    }
};

int main()
{

    return 0;
}