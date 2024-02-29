#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using Top-Down Approach
// Time Complexity -> O(n)
// Space Complexity -> O(n)
int fibonacci(int num, vector<int> &dp)
{
    if (num == 1 or num == 0)
    {
        return num;
    }

    // Step 3
    // overlapping subproblem
    if (dp[num] != -1)
    {
        return dp[num];
    }

    // Step 2
    dp[num] = fibonacci(num - 1, dp) + fibonacci(num - 2, dp);
    return dp[num];
}

// Using Bottom-Up Approach
// Time Complexity -> O(n)
// Space Complexity -> O(n) (Better than Top-Down Approach in this case as no recursive calls)
// int fibonacciBottom(int n)
// {
//     // Step 1
//     vector<int> dp(n + 1);

//     // Step 2
//     dp[0] = 0;
//     dp[1] = 1;

//     // Step 3
//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }

//     return dp[n];
// }

// After Space Complexity
// Time Complexity -> O(n)
// Space Complexity -> O(1)
int fibonacciBottom(int n)
{
    int prev1 = 0;
    int prev2 = 1;

    if (n == 0)
        return prev1;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;

        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

int main()
{
    int n;
    cin >> n;

    // Step 1
    // For Memoization
    vector<int> dp(n + 1, -1);

    cout << fibonacci(n, dp) << endl;

    cout << fibonacciBottom(n) << endl;

    return 0;
}