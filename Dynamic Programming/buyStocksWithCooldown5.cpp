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
    // long long solve(vector<long long> &prices, int n, int i, bool canBuy, int cooldown) {
    //     if(i == n) return 0;

    //     long long profit = 0;
    //     if(canBuy) {
    //            long long buy = 0;
    //            long long notBuy = 0;

    //            if(cooldown == 0) {
    //                buy = -prices[i] + solve(prices, n, i + 1, false, 0);
    //                notBuy = 0 + solve(prices, n, i + 1, true, 0);
    //            } else {
    //                notBuy = 0 + solve(prices, n, i + 1, true, cooldown - 1);
    //            }

    //            profit = max(buy, notBuy);
    //     } else {
    //         long long sell = +prices[i] + solve(prices, n, i + 1, true, 1);
    //         long long notSell = 0 + solve(prices, n, i + 1, false, 0);

    //         profit = max(sell, notSell);
    //     }

    //     return profit;
    // }

    // Memoization
    // TC -> O(n * 2 * 2)
    // SC -> O(n * 2 * 2) + O(n)
    // long long solve(vector<long long> &prices, int n, int i, bool canBuy, int cooldown, vector<vector<vector<long long>>> &dp) {
    //     if(i == n) return 0;

    //     if(dp[i][canBuy][cooldown] != -1) return dp[i][canBuy][cooldown];

    //     long long profit = 0;
    //     if(canBuy) {
    //         long long buy = 0;
    //         long long notBuy = 0;

    //         if(cooldown == 0) {
    //             buy = -prices[i] + solve(prices, n, i + 1, false, 0, dp);
    //             notBuy = 0 + solve(prices, n, i + 1, true, 0, dp);
    //         } else {
    //             notBuy = 0 + solve(prices, n, i + 1, true, cooldown - 1, dp);
    //         }

    //         profit = max(buy, notBuy);
    //     } else {
    //         long long sell = +prices[i] + solve(prices, n, i + 1, true, 1, dp);
    //         long long notSell = 0 + solve(prices, n, i + 1, false, 0, dp);

    //         profit = max(sell, notSell);
    //     }

    //     return dp[i][canBuy][cooldown] = profit;
    // }

    // Tabulation
    // TC -> O(n * 2 * 2)
    // SC -> O(n * 2 * 2)
    // long long solve(vector<long long> &prices, int n) {
    //     vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>> (2, vector<long long> (2, 0)));

    //     for(int i = n - 1; i >= 0; i--) {
    //         for(int canBuy = 0; canBuy <= 1; canBuy++) {
    //             for(int cooldown = 0; cooldown <= 1; cooldown++) {
    //                 long long profit = 0;
    //                 if(canBuy) {
    //                     long long buy = 0;
    //                     long long notBuy = 0;

    //                     if(cooldown == 0) {
    //                         buy = -prices[i] + dp[i + 1][0][0];
    //                         notBuy = 0 + dp[i + 1][1][0];
    //                     } else {
    //                         notBuy = 0 + dp[i + 1][1][cooldown - 1];
    //                     }

    //                     profit = max(buy, notBuy);
    //                 } else {
    //                     long long sell = +prices[i] + dp[i + 1][1][1];
    //                     long long notSell = 0 + dp[i + 1][0][0];

    //                     profit = max(sell, notSell);
    //                 }

    //                 dp[i][canBuy][cooldown] = profit;
    //             }
    //         }
    //     }

    //     return dp[0][1][0];
    // }

    // Space Optimization
    // TC -> O(n * 2 * 2)
    // SC -> O(2 * 2) + O(2 * 2)
    long long solve(vector<long long> &prices, int n)
    {
        vector<vector<long long>> next(2, vector<long long>(2, 0)), curr(2, vector<long long>(2, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                for (int cooldown = 0; cooldown <= 1; cooldown++)
                {
                    long long profit = 0;

                    if (canBuy)
                    {
                        long long buy = 0;
                        long long notBuy = 0;

                        if (cooldown == 0)
                        {
                            buy = -prices[i] + next[0][0];
                            notBuy = 0 + next[1][0];
                        }
                        else
                        {
                            notBuy = 0 + next[1][cooldown - 1];
                        }

                        profit = max(buy, notBuy);
                    }
                    else
                    {
                        long long sell = +prices[i] + next[1][1];
                        long long notSell = 0 + next[0][0];

                        profit = max(sell, notSell);
                    }

                    curr[canBuy][cooldown] = profit;
                }
            }

            next = curr;
        }

        return next[1][0];
    }

    long long maximumProfit(vector<long long> &prices, int n)
    {
        // vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>> (2, vector<long long> (2, -1)));
        // return solve(prices, n, 0, true, 0, dp);

        return solve(prices, n);
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

        Solution obj;
        cout << obj.maximumProfit(prices, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends