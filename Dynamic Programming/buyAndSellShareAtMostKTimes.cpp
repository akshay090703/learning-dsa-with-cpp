//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Recursion
    // TC -> O(2^n)
    // SC -> O(n)
    // int solve(int prices[], int n, int i, bool canBuy, int buysLeft) {
    //     if(i == n) return 0;

    //     int profit = 0;
    //     if(canBuy and buysLeft > 0) {
    //         int buy = -prices[i] + solve(prices, n, i + 1, false, buysLeft - 1);
    //         int notBuy = 0 + solve(prices, n, i + 1, true, buysLeft);

    //         profit = max(buy, notBuy);
    //     } else if(!canBuy) {
    //         int sell = +prices[i] + solve(prices, n, i + 1, true, buysLeft);
    //         int notSell = 0 + solve(prices, n, i + 1, false, buysLeft);

    //         profit = max(sell, notSell);
    //     }

    //     return profit;
    // }

    // Memoization
    // TC -> O(n * 2 * k)
    // SC -> O(n * 2 * k) + O(n)
    // int solve(int prices[], int n, int i, bool canBuy, int buysLeft, vector<vector<vector<int>>> &dp) {
    //     if(i == n) return 0;

    //     if(dp[i][canBuy][buysLeft] != -1) return dp[i][canBuy][buysLeft];

    //     int profit = 0;
    //     if(canBuy and buysLeft > 0) {
    //         int buy = -prices[i] + solve(prices, n, i + 1, false, buysLeft - 1, dp);
    //         int notBuy = 0 + solve(prices, n, i + 1, true, buysLeft, dp);

    //         profit = max(buy, notBuy);
    //     } else if(!canBuy) {
    //         int sell = +prices[i] + solve(prices, n, i + 1, true, buysLeft, dp);
    //         int notSell = 0 + solve(prices, n, i + 1, false, buysLeft, dp);

    //         profit = max(sell, notSell);
    //     }

    //     return dp[i][canBuy][buysLeft] = profit;
    // }

    // Tabulation
    // TC -> O(n * 2 * k)
    // SC -> O(n * 2 * k)
    // int solve(int prices[], int n, int k) {
    //     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (k + 1, 0)));

    //     for(int i = n - 1; i>=0; i--) {
    //         for(int canBuy = 0; canBuy <= 1; canBuy++) {
    //             for(int buysLeft = 0; buysLeft <= k; buysLeft++) {
    //                 int profit = 0;
    //                 if(canBuy and buysLeft > 0) {
    //                     int buy = -prices[i] + dp[i + 1][0][buysLeft - 1];
    //                     int notBuy = 0 + dp[i + 1][1][buysLeft];

    //                     profit = max(buy, notBuy);
    //                 } else if(!canBuy) {
    //                     int sell = +prices[i] + dp[i + 1][1][buysLeft];
    //                     int notSell = 0 + dp[i + 1][0][buysLeft];

    //                     profit = max(sell, notSell);
    //                 }

    //                 dp[i][canBuy][buysLeft] = profit;
    //             }
    //         }
    //     }

    //     return dp[0][1][k];
    // }

    // Space Optimization
    // TC -> O(n * 2 * k)
    // SC -> O(2 * k)
    int solve(int prices[], int n, int k) {
        vector<vector<int>> next(2, vector<int> (k + 1, 0)), curr(2, vector<int> (k + 1, 0));

        for(int i = n - 1; i>=0; i--) {
            for(int canBuy = 0; canBuy <= 1; canBuy++) {
                for(int buysLeft = 0; buysLeft <= k; buysLeft++) {
                    int profit = 0;
                    if(canBuy and buysLeft > 0) {
                        int buy = -prices[i] + next[0][buysLeft - 1];
                        int notBuy = 0 + next[1][buysLeft];

                        profit = max(buy, notBuy);
                    } else if(!canBuy) {
                        int sell = +prices[i] + next[1][buysLeft];
                        int notSell = 0 + next[0][buysLeft];

                        profit = max(sell, notSell);
                    }

                    curr[canBuy][buysLeft] = profit;
                }
            }

            next = curr;
        }

        return next[1][k];
    }
  
    int maxProfit(int K, int N, int A[]) {
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (k + 1, -1)));
        // return solve(A, N, 0, true, K, dp);

        return solve(A, N, K);

        // return solve(A, N, 0, true, K);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends