//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Recursion
    // TC -> O(2^n)
    // SC -> O(n)
    // long long solve(vector<long long> &prices, int n, int fee, int i, bool canBuy) {
    //     if(i == n) return 0;

    //     long long profit = 0;
    //     if(canBuy) {
    //         long long buy = -prices[i] + solve(prices, n, fee, i + 1, false);
    //         long long notBuy = 0 + solve(prices, n, fee, i + 1, true);

    //         profit = max(buy, notBuy);
    //     } else {
    //         long long sell = prices[i] - fee + solve(prices, n, fee, i + 1, true);
    //         long long notSell = 0 + solve(prices, n, fee, i + 1, false);

    //         profit = max(sell, notSell);
    //     }

    //     return profit;
    // }

    // Memoization
    // TC -> O(n * 2)
    // SC -> O(n * 2) + O(n)
    // long long solve(vector<long long> &prices, int n, int fee, int i, bool canBuy, vector<vector<long long>> &dp) {
    //     if(i == n) return 0;

    //     if(dp[i][canBuy] != -1) return dp[i][canBuy];

    //     long long profit = 0;
    //     if(canBuy) {
    //         long long buy = -prices[i] + solve(prices, n, fee, i + 1, false, dp);
    //         long long notBuy = 0 + solve(prices, n, fee, i + 1, true, dp);

    //         profit = max(buy, notBuy);
    //     } else {
    //         long long sell = prices[i] - fee + solve(prices, n, fee, i + 1, true, dp);
    //         long long notSell = 0 + solve(prices, n, fee, i + 1, false, dp);

    //         profit = max(sell, notSell);
    //     }

    //     return dp[i][canBuy] = profit;
    // }

    // Tabulation
    // TC -> O(n * 2)
    // SC -> O(n * 2) + O(n)
    // long long solve(vector<long long> &prices, int n, int fee) {
    //     vector<vector<long long>> dp(n + 1, vector<long long> (2, 0));

    //     for(int i = n - 1; i>=0; i--) {
    //         for(int canBuy = 0; canBuy <= 1; canBuy++) {
    //             long long profit = 0;
    //             if(canBuy) {
    //                 long long buy = -prices[i] + dp[i + 1][0];
    //                 long long notBuy = 0 + dp[i + 1][1];

    //                 profit = max(buy, notBuy);
    //             } else {
    //                 long long sell = prices[i] - fee + dp[i + 1][1];
    //                 long long notSell = 0 + dp[i + 1][0];

    //                 profit = max(sell, notSell);
    //             }

    //             dp[i][canBuy] = profit;
    //         }
    //     }

    //     return dp[0][1];
    // }

    // Space Optimization
    // TC -> O(n * 2)
    // SC -> O(2) + O(2)
    long long solve(vector<long long> &prices, int n, int fee)
    {
        vector<long long> next(2, 0), curr(2, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                long long profit = 0;
                if (canBuy)
                {
                    long long buy = -prices[i] + next[0];
                    long long notBuy = 0 + next[1];

                    profit = max(buy, notBuy);
                }
                else
                {
                    long long sell = prices[i] - fee + next[1];
                    long long notSell = 0 + next[0];

                    profit = max(sell, notSell);
                }

                curr[canBuy] = profit;
            }

            next = curr;
        }

        return next[1];
    }

    long long maximumProfit(vector<long long> &prices, int n, int fee)
    {
        // vector<vector<long long>> dp(n + 1, vector<long long> (2, -1));
        // return solve(prices, n, fee, 0, true, dp);

        return solve(prices, n, fee);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> prices;

        for (int i = 0; i < n; ++i)
        {
            long long x;
            cin >> x;
            prices.push_back(x);
        }

        int fee;
        cin >> fee;

        Solution obj;
        cout << obj.maximumProfit(prices, n, fee) << "\n";
    }
    return 0;
}
// } Driver Code Ends