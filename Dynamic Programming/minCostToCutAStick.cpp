#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursion
    // TC -> O(exponential)
    // SC -> O(n)
    // int solve(vector<int> &cuts, int start, int end) {
    //     if(start > end) return 0;

    //     int minCost = INT_MAX;
    //     for(int k = start; k <= end; k++) {
    //         int cost = (cuts[end + 1] - cuts[start - 1]) + solve(cuts, start, k - 1) + solve(cuts, k + 1, end);

    //         minCost = min(minCost, cost);
    //     }

    //     return minCost;
    // }

    // Memoization
    // TC -> O(n^3)
    // SC -> O(n^2) + O(n)
    // int solve(vector<int> &cuts, int start, int end, vector<vector<int>> &dp) {
    //     if(start > end) return 0;

    //     if(dp[start][end] != -1) return dp[start][end];

    //     int minCost = INT_MAX;
    //     for(int k = start; k <= end; k++) {
    //         int cost = (cuts[end + 1] - cuts[start - 1]) + solve(cuts, start, k - 1, dp) + solve(cuts, k + 1, end, dp);

    //         minCost = min(minCost, cost);
    //     }

    //     return dp[start][end] = minCost;
    // }

    // Tabulation
    // TC -> O(n^3)
    // SC -> O(n^2)
    int solve(vector<int> &cuts, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int start = n - 2; start >= 1; start--)
        {
            for (int end = start; end <= n - 2; end++)
            {
                int minCost = INT_MAX;
                for (int k = start; k <= end; k++)
                {
                    int cost = (cuts[end + 1] - cuts[start - 1]) + dp[start][k - 1] + dp[k + 1][end];

                    minCost = min(minCost, cost);
                }

                dp[start][end] = minCost;
            }
        }

        return dp[1][n - 2];
    }

    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();

        // vector<vector<int>> dp(m, vector<int> (m, -1));
        // return solve(cuts, 1, m - 2, dp);

        return solve(cuts, m);
    }
};

int main()
{

    return 0;
}