#include <bits/stdc++.h>
using namespace std;

// Using Recursion
int solve(vector<int> &nums, int n, int i)
{
    if (i >= n)
        return 0;

    if (i == n - 1)
        return nums[i];

    int included = nums[i] + solve(nums, n, i + 2);
    int excluded = solve(nums, n, i + 1);

    return max(included, excluded);
}

// Using Memoization
int solveMemo(vector<int> &nums, vector<int> &memo, int n, int i)
{
    if (i >= n)
        return 0;

    if (i == n - 1)
        return nums[i];

    if (memo[i] != -1)
        return memo[i];

    int included = nums[i] + solveMemo(nums, memo, n, i + 2);
    int excluded = solveMemo(nums, memo, n, i + 1);

    memo[i] = max(included, excluded);

    return memo[i];
}

// Using Tabulation
// Bottom Up Approach
int solveTabu(vector<int> &nums)
{
    int n = nums.size();
    vector<int> tabu(n, 0);
    tabu[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        int included = nums[i] + tabu[i - 2];
        int excluded = tabu[i - 1];

        tabu[i] = max(included, excluded);
    }

    return tabu[n - 1];
}

// Using Space Optimization
int solveSO(vector<int> &nums)
{
    int n = nums.size();
    int prev2 = 0; // as for index less than 0, we take 0
    int prev1 = nums[0];

    for (int i = 1; i < n; i++)
    {
        int included = nums[i] + prev2;
        int excluded = prev1;

        int ans = max(included, excluded);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    /* int n = nums.size();
    return solve(nums, n, 0); */

    /* int n = nums.size();
    vector<int> memo(n+1, -1);
    return solveMemo(nums, memo, n, 0); */

    // return solveTabu(nums);

    return solveSO(nums);
}

int main()
{
    return 0;
}