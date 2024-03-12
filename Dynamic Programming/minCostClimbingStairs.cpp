#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// #define MOD 1000000007

// int solve(long long nStairs, int i)
// {
//     if (i == nStairs)
//     {
//         return 1;
//     }

//     if (i > nStairs)
//     {
//         return 0;
//     }

//     return (solve(nStairs, i + 1) + solve(nStairs, i + 2)) % MOD;
// }

// int countDistinctWayToClimbStair(long long nStairs)
// {
//     int ans = solve(nStairs, 0);
//     return ans;
// }

// Using Recursion and memoization
// Time Complexity -> O(n)
// Space Complexity -> O(n)
int solve(vector<int> &cost, vector<int> &memo, int n)
{
    if (n == 0 or n == 1)
    {
        return cost[n];
    }

    if (memo[n] != -1)
    {
        return memo[n];
    }

    memo[n] = cost[n] + min(solve(cost, memo, n - 1), solve(cost, memo, n - 2));
    return memo[n];
}

// Using Tabulation
// as only 1 variable is changing so 1d data structure is used
// Time Complexity -> O(n)
// Space Complexity -> O(n)
int solve2(vector<int> &cost, int n)
{
    // Step 1: Creation of dp table
    vector<int> dp(n + 1);

    // Step 2: Base case analysis
    dp[0] = cost[0];
    dp[1] = cost[1];

    // Step 3: Build the dp table from bottom to top.
    for (int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);
}

// Using Space Optimization
// Time Complexity -> O(n)
// Space Complexity -> O(1)
int solve3(vector<int> &cost, int n)
{
    int prev2 = cost[0];
    int prev1 = cost[1];
    int ans = 0;

    for (int i = 2; i < n; i++)
    {
        ans = cost[i] + min(prev2, prev1);
        prev2 = prev1;
        prev1 = ans;
    }

    return min(prev1, prev2);
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();

    // adding memoization
    vector<int> memo(n + 1, -1);

    int ans = min(solve(cost, memo, n - 1), solve(cost, memo, n - 2));
    return ans;
}

int main()
{

    return 0;
}