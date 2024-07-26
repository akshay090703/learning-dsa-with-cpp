//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Recursion with Memoization
    // TC -> O(n * sum)
    // SC -> O(n * sum) + O(n)
    // long long int solve(int coins[], int n, int sum, vector<vector<long long int>> &dp) {
    // if(sum == 0) return 1;
    // if(sum < 0 or n < 0) return 0;

    // if(dp[n][sum] != -1) return dp[n][sum];

    // long long int pick = solve(coins, n, sum - coins[n], dp);
    // long long int notPick = solve(coins, n - 1, sum, dp);

    // return dp[n][sum] = pick + notPick;
    // }

    // Tabulation
    // TC -> O(n * sum)
    // SC -> O(n * sum)
    // long long int solve(int coins[], int n, int sum, vector<vector<long long int>> &dp) {
    //     for(int target = 0; target <= sum; target++) {
    //         if(target % coins[0] == 0) {
    //             dp[0][target] = 1;
    //         }
    //     }

    //     for(int i = 1; i <= n; i++) {
    //         for(int target = 0; target <= sum; target++) {
    //             long long int pick = 0;
    //             if(coins[i] <= target) pick = dp[i][target - coins[i]];

    //             long long int notPick = dp[i - 1][target];

    //             dp[i][target] = pick + notPick;
    //         }
    //     }

    //     return dp[n][sum];
    // }

    // Space Optimization
    // TC -> O(n * sum)
    // SC -> O(n) + O(n)
    long long int solve(int coins[], int n, int sum)
    {
        vector<long long int> curr(sum + 1, 0), prev(sum + 1, 0);

        for (int target = 0; target <= sum; target++)
        {
            if (target % coins[0] == 0)
            {
                prev[target] = 1;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int target = 0; target <= sum; target++)
            {
                long long int pick = 0;
                if (coins[i] <= target)
                    pick = curr[target - coins[i]];

                long long int notPick = prev[target];

                curr[target] = pick + notPick;
            }

            prev = curr;
        }

        return prev[sum];
    }

    long long int count(int coins[], int N, int sum)
    {
        // vector<vector<long long int>> dp(N, vector<long long int> (sum + 1, 0));
        // return solve(coins, N - 1, sum, dp);
        return solve(coins, N - 1, sum);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++)
            cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}

// } Driver Code Ends