//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Recursion
    // TC -> O(2^n)
    // SC -> O(n)
    // int solve(vector<int> &price, int n, int i, bool canBuy, int buysLeft) {
    //     if(i == n) return 0;

    //     int profit = 0;

    //     if(canBuy and buysLeft > 0) {
    //         int buy = -price[i] + solve(price, n, i + 1, false, buysLeft - 1);
    //         int notBuy = 0 + solve(price, n, i + 1, true, buysLeft);

    //         profit = max(buy, notBuy);
    //     } else if(!canBuy) {
    //         int sell = +price[i] + solve(price, n, i + 1, true, buysLeft);
    //         int notSell = 0 + solve(price, n, i + 1, false, buysLeft);

    //         profit = max(sell, notSell);
    //     }

    //     return profit;
    // }

    // Memoization
    // TC -> O(n * 2 * 2)
    // SC -> O(n * 2 * 2) + O(n)
    // int solve(vector<int> &price, int n, int i, bool canBuy, int buysLeft, vector<vector<vector<int>>> &dp) {
    //     if(i == n) return 0;

    //     if(dp[i][canBuy][buysLeft] != -1) return dp[i][canBuy][buysLeft];

    //     int profit = 0;

    //     if(canBuy and buysLeft > 0) {
    //         int buy = -price[i] + solve(price, n, i + 1, false, buysLeft - 1, dp);
    //         int notBuy = 0 + solve(price, n, i + 1, true, buysLeft, dp);

    //         profit = max(buy, notBuy);
    //     } else if(!canBuy) {
    //         int sell = +price[i] + solve(price, n, i + 1, true, buysLeft, dp);
    //         int notSell = 0 + solve(price, n, i + 1, false, buysLeft, dp);

    //         profit = max(sell, notSell);
    //     }

    //     return dp[i][canBuy][buysLeft] = profit;
    // }

    // Tabulation
    // TC -> O(n * 2 * 2)
    // SC -> O(n * 2 * 2)
    // int solve(vector<int> &price, int n) {
    //     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, 0)));

    //     for(int i = n - 1; i>=0; i--) {
    //         for(int canBuy = 0; canBuy <= 1; canBuy++) {
    //             for(int buysLeft = 0; buysLeft <= 2; buysLeft++) {
    //                 int profit = 0;

    //                 if(canBuy and buysLeft > 0) {
    //                     int buy = -price[i] + dp[i + 1][0][buysLeft - 1];
    //                     int notBuy = 0 + dp[i + 1][1][buysLeft];

    //                     profit = max(buy, notBuy);
    //                 } else if(!canBuy) {
    //                     int sell = +price[i] + dp[i + 1][1][buysLeft];
    //                     int notSell = 0 + dp[i + 1][0][buysLeft];

    //                     profit = max(sell, notSell);
    //                 }

    //                 dp[i][canBuy][buysLeft] = profit;
    //             }
    //         }
    //     }

    //     return dp[0][1][2];
    // }

    // Tabulation
    // TC -> O(n * 2 * 2)
    // SC -> O(2 * 2)
    int solve(vector<int> &price, int n)
    {
        vector<vector<int>> next(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int canBuy = 0; canBuy <= 1; canBuy++)
            {
                for (int buysLeft = 0; buysLeft <= 2; buysLeft++)
                {
                    int profit = 0;

                    if (canBuy and buysLeft > 0)
                    {
                        int buy = -price[i] + next[0][buysLeft - 1];
                        int notBuy = 0 + next[1][buysLeft];

                        profit = max(buy, notBuy);
                    }
                    else if (!canBuy)
                    {
                        int sell = +price[i] + next[1][buysLeft];
                        int notSell = 0 + next[0][buysLeft];

                        profit = max(sell, notSell);
                    }

                    curr[canBuy][buysLeft] = profit;
                }
            }

            next = curr;
        }

        return next[1][2];
    }

    int maxProfit(vector<int> &price)
    {
        int n = price.size();

        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, -1)));
        // return solve(price, n, 0, true, 2, dp);

        return solve(price, n);

        // return solve(price, n, 0, true, 2);
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
        vector<int> price(n);
        for (int i = 0; i < n; i++)
            cin >> price[i];
        Solution obj;
        cout << obj.maxProfit(price) << endl;
    }
}

// } Driver Code Ends