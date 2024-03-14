#include <bits/stdc++.h>
using namespace std;

// Using Recursion
int solve(vector<int> &num, int x)
{
    // base case
    if (x == 0)
    {
        return 0;
    }

    if (x < 0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;

    for (auto coin : num)
    {
        int ans = solve(num, x - coin);

        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }

    return mini;
}

// Using Memoization
int solveMemo(vector<int> &num, vector<int> &memo, int x)
{
    if (x == 0)
        return 0;

    if (x < 0)
        return INT_MAX;

    if (memo[x] != -1)
    {
        return memo[x];
    }

    int mini = INT_MAX;

    for (auto coin : num)
    {
        int ans = solveMemo(num, memo, x - coin);

        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }

    memo[x] = mini;

    return memo[x];
}

// Using Tabulation
int solveTabu(vector<int> &num, int x)
{
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        // here we are to find minimum coins for every amount between 1 and x
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0 and dp[i - num[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }

    if (dp[x] == INT_MAX)
    {
        return -1;
    }

    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    /* int ans = solve(num, x);

    if(ans == INT_MAX) {
        return -1;
    }

    return ans; */

    /* vector<int> memo(x + 1, -1);
    int ans = solveMemo(num, memo, x);

    if(ans == INT_MAX) return -1;

    return ans; */

    return solveTabu(num, x);
}

int main()
{

    return 0;
}