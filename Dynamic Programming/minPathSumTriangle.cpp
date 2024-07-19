//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Recursion
    // TC -> O(2^n)
    // SC -> O(path length)
    // int solve(vector<vector<int>> &triangle, int n, int m) {
    //     if(m < 0 or m >= triangle[n].size()) return INT_MAX;

    //     if(n == 0) return triangle[0][0];

    //     int left = solve(triangle, n - 1, m - 1);
    //     int right = solve(triangle, n - 1, m);

    //     return min(left, right) + triangle[n][m];
    // }

    // Memoization
    // TC -> O(n(n+1)/2)
    // SC -> O(n(n+1)/2)
    // int solve(vector<vector<int>> &triangle, int n, int m, vector<vector<int>> &dp) {
    //     if(m < 0 or m >= triangle[n].size()) return INT_MAX;

    //     if(n == 0) return dp[0][0] = triangle[0][0];

    //     if(dp[n][m] != -1) return dp[n][m];

    //     int left = solve(triangle, n - 1, m - 1, dp);
    //     int right = solve(triangle, n - 1, m, dp);

    //     return dp[n][m] = min(left, right) + triangle[n][m];
    // }

    // // Tabulation
    // // TC -> O(n(n+1)/2)
    // // SC -> O(n(n+1)/2)
    // int solve(vector<vector<int>> &triangle, int n, vector<vector<int>> &dp) {
    //     dp[0][0] = triangle[0][0];

    //     for(int i = 1; i<=n; i++) {
    //         for(int j = 0; j<=i; j++) {
    //             int left = INT_MAX, right = INT_MAX;

    //             if(j < triangle[i - 1].size()) left = dp[i - 1][j];
    //             if(j - 1 < triangle[i - 1].size()) right = dp[i - 1][j - 1];

    //             dp[i][j] = min(left, right) + triangle[i][j];
    //         }
    //     }

    //     return *min_element(dp[n].begin(), dp[n].end());
    // }

    // Space Optimization
    // TC -> O(n(n+1)/2) + O(n)
    // SC -> O(n) + O(n)
    int solve(vector<vector<int>> &triangle, int n)
    {
        vector<int> dp(1, triangle[0][0]);

        for (int i = 1; i <= n; i++)
        {
            vector<int> temp(i + 1);
            for (int j = 0; j <= i; j++)
            {
                int left = INT_MAX, right = INT_MAX;

                if (j < dp.size() and j >= 0)
                    left = dp[j];
                if (j - 1 < dp.size() and j - 1 >= 0)
                    right = dp[j - 1];

                temp[j] = min(left, right) + triangle[i][j];
            }

            dp = temp;
        }

        return *min_element(dp.begin(), dp.end());
    }

    int minimizeSum(int n, vector<vector<int>> &triangle)
    {
        // int minPath = INT_MAX;
        // for(int i = n - 1; i>=0; i--) {
        //     minPath = min(minPath, solve(triangle, n - 1, i));
        // }
        // return minPath;

        // vector<vector<int>> dp;
        // for(int i = 1; i<=n; i++) {
        //     vector<int> row(i, -1);
        //     dp.push_back(row);
        // }
        // return solve(triangle, n - 1, dp);

        return solve(triangle, n - 1);
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
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int j = 0; j <= i; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends