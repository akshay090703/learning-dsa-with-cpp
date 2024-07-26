//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    // Recursion with Memoization
    // TC -> O(n * amount)
    // SC -> O(n * amount) + O(n)
    // long long solve(vector<int> &coins, int amount, int n, vector<vector<int>> &dp) {
    //     if(n == 0) {
    //         if(amount % coins[n] == 0) return amount / coins[n];
    //         return INT_MAX;
    //     }

    //     if(amount == 0) return 0;

    //     if(dp[n][amount] != -1) return dp[n][amount];

    //     long long pick = INT_MAX;
    //     if(coins[n] <= amount) pick = solve(coins, amount - coins[n], n, dp) + 1;

    //     long long notPick = solve(coins, amount, n - 1, dp);

    //     return dp[n][amount] = min(pick, notPick);
    // }

    // Tabulation
    // TC -> O(n * amount)
    // SC -> O(n * amount)
    // long long solve(vector<int> &coins, int amount, int n, vector<vector<long long>> &dp) {
    //     for(int target = 0; target <= amount; target++) {
    //         if(target % coins[0] == 0) {
    //             dp[0][target] = target / coins[0];
    //         } else {
    //             dp[0][target] = INT_MAX;
    //         }
    //     }

    //     for(int i = 1; i<=n; i++) {
    //         for(int target = 0; target <= amount; target++) {
    //             long long pick = INT_MAX;
    //             if(coins[i] <= target) pick = dp[i][target - coins[i]] + 1;

    //             long long notPick = dp[i - 1][target];

    //             dp[i][target] = min(pick, notPick);
    //         }
    //     }

    //     return dp[n][amount];
    // }

    // Space Optimization
    // TC -> O(n * amount)
    // SC -> O(n) + O(n)
    long long solve(vector<int> &coins, int amount, int n)
    {
        vector<long long> prev(amount + 1, 0), curr(amount + 1, 0);

        for (int target = 0; target <= amount; target++)
        {
            if (target % coins[0] == 0)
            {
                prev[target] = target / coins[0];
            }
            else
            {
                prev[target] = INT_MAX;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int target = 0; target <= amount; target++)
            {
                long long pick = INT_MAX;
                if (coins[i] <= target)
                    pick = curr[target - coins[i]] + 1;

                long long notPick = prev[target];

                curr[target] = min(pick, notPick);
            }

            prev = curr;
        }

        return prev[amount];
    }

    int minCoins(vector<int> &coins, int M, int V)
    {
        // vector<vector<long long>> dp(n, vector<long long> (amount + 1, -1));
        // long long result = solve(coins, amount, n - 1, dp);
        long long result = solve(coins, V, M - 1);
        return result == INT_MAX ? -1 : result;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, m, v) << "\n";
    }
    return 0;
}

// } Driver Code Ends