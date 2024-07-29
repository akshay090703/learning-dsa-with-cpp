//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    // Recursion
    // TC -> O(2^n)
    // SC -> O(n)
    // int solve(vector<int> &prices, int n, int i, bool canBuy) {
    //     if(i == n) return 0;

    //     int profit = 0;
    //     if(canBuy) {
    //         int buy = -prices[i] + solve(prices, n, i + 1, false);
    //         int notBuy = 0 + solve(prices, n, i + 1, true);

    //         profit = max(buy, notBuy);
    //     } else {
    //         int sell = prices[i] + solve(prices, n, i + 1, true);
    //         int notSell = 0 + solve(prices, n, i + 1, false);

    //         profit = max(sell, notSell);
    //     }

    //     return profit;
    // }

    // Memoization
    // TC -> O(n * 2)
    // SC -> O(n * 2) + O(n)
    // int solve(vector<int> &prices, int n, int i, bool canBuy, vector<vector<int>> &dp) {
    //     if(i == n) return 0;

    //     if(dp[i][canBuy] != -1) return dp[i][canBuy];

    //     int profit = 0;
    //     if(canBuy) {
    //         int buy = -prices[i] + solve(prices, n, i + 1, false, dp);
    //         int notBuy = 0 + solve(prices, n, i + 1, true, dp);

    //         profit = max(buy, notBuy);
    //     } else {
    //         int sell = prices[i] + solve(prices, n, i + 1, true, dp);
    //         int notSell = 0 + solve(prices, n, i + 1, false, dp);

    //         profit = max(sell, notSell);
    //     }

    //     return dp[i][canBuy] = profit;
    // }

    // Tabulation
    // TC -> O(n * 2)
    // SC -> O(n * 2)
    // int solve(vector<int> &prices, int n) {
    //     vector<vector<int>> dp(n + 1, vector<int> (2, 0));

    //     for(int i = n - 1; i>=0; i--) {
    //         for(int canBuy = 0; canBuy <= 1; canBuy++) {
    //             int profit = 0;
    //             if(canBuy) {
    //                 int buy = -prices[i] + dp[i + 1][0];
    //                 int notBuy = 0 + dp[i + 1][1];

    //                 profit = max(buy, notBuy);
    //             } else {
    //                 int sell = prices[i] + dp[i + 1][1];
    //                 int notSell = 0 + dp[i + 1][0];

    //                 profit = max(sell, notSell);
    //             }

    //             dp[i][canBuy] = profit;
    //         }
    //     }

    //     return dp[0][1];
    // }

    // Space Optimization
    // TC -> O(n * 2)
    // SC -> O(4)
    int solve(vector<int> &prices, int n)
    {
        vector<int> next(2, 0), curr(2, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                int profit = 0;
                if (canBuy)
                {
                    int buy = -prices[i] + next[0];
                    int notBuy = 0 + next[1];

                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = prices[i] + next[1];
                    int notSell = 0 + next[0];

                    profit = max(sell, notSell);
                }

                curr[canBuy] = profit;
            }

            next = curr;
        }

        return next[1];
    }

    int stockBuyAndSell(int n, vector<int> &prices)
    {
        // vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        // return solve(prices, n, 0, true, dp);

        return solve(prices, n);

        // return solve(prices, n, 0, true);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        vector<int> prices(n);
        Array::input(prices, n);

        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);

        cout << res << endl;
    }
}

// } Driver Code Ends