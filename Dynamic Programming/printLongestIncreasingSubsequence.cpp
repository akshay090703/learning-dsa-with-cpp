//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Recursion
    // TC -> O(2 ^ n)
    // SC -> O(n)
    // int solve(vector<int>& a, int n, int i, int prevIdx) {
    //     if(i == n) return 0;

    //     int take = 0;
    //     if(prevIdx == -1 or a[prevIdx] < a[i]) take = 1 + solve(a, n, i + 1, i);

    //     int notTake = 0 + solve(a, n, i + 1, prevIdx);

    //     return max(take, notTake);
    // }

    // Memoization
    // TC -> O(n * n)
    // SC -> O(n * n) + O(n)
    // int solve(vector<int>& a, int n, int i, int prevIdx, vector<vector<int>> &dp) {
    //     if(i == n) return 0;

    //     if(dp[i][prevIdx + 1] != -1) return dp[i][prevIdx + 1];

    //     int take = 0;
    //     if(prevIdx == -1 or a[prevIdx] < a[i]) take = 1 + solve(a, n, i + 1, i, dp);

    //     int notTake = 0 + solve(a, n, i + 1, prevIdx, dp);

    //     return dp[i][prevIdx + 1] = max(take, notTake);
    // }

    // Tabulation
    // TC -> O(n * n)
    // SC -> O(n * n)
    // int solve(vector<int>& a, int n) {
    //     vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

    //     for(int i = n - 1; i>=0; i--) {
    //         for(int prevIdx = i - 1; prevIdx >= -1; prevIdx--) {
    //             int take = 0;
    //             if(prevIdx == -1 or a[prevIdx] < a[i]) take = 1 + dp[i + 1][i + 1];

    //             int notTake = 0 + dp[i + 1][prevIdx + 1];

    //             dp[i][prevIdx + 1] = max(take, notTake);
    //         }
    //     }

    //     return dp[0][-1 + 1];
    // }

    // Space Optimization
    // TC -> O(n * n)
    // SC -> O(n) + O(n)
    // int solve(vector<int>& a, int n) {
    //     vector<int> next(n + 1, 0), curr(n + 1, 0);

    //     for(int i = n - 1; i>=0; i--) {
    //         for(int prevIdx = i - 1; prevIdx >= -1; prevIdx--) {
    //             int take = 0;
    //             if(prevIdx == -1 or a[prevIdx] < a[i]) take = 1 + next[i + 1];

    //             int notTake = 0 + next[prevIdx + 1];

    //             curr[prevIdx + 1] = max(take, notTake);
    //         }

    //         next = curr;
    //     }

    //     return next[-1 + 1];
    // }

    // A different Tabulation Approach
    // TC -> O(n^2)
    // SC -> O(n)
    vector<int> solve(vector<int> &a, int n)
    {
        vector<int> dp(n, 1);
        vector<int> prevArr(n, 0);

        int maxi = 0;
        int lastIdx = -1;
        for (int i = 0; i < n; i++)
        {
            prevArr[i] = i;

            for (int prevIdx = 0; prevIdx < i; prevIdx++)
            {
                if (a[i] > a[prevIdx])
                {
                    if (dp[i] < dp[prevIdx] + 1)
                    {
                        dp[i] = dp[prevIdx] + 1;
                        prevArr[i] = prevIdx;
                    }
                }
            }

            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastIdx = i;
            }
        }

        vector<int> result;
        result.push_back(a[lastIdx]);
        while (prevArr[lastIdx] != lastIdx)
        {
            lastIdx = prevArr[lastIdx];
            result.push_back(a[lastIdx]);
        }

        reverse(result.begin(), result.end());
        return result;
    }

    vector<int> longestIncreasingSubsequence(int n, vector<int> &nums)
    {
        // vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        // return solve(nums, n, 0, -1, dp);

        return solve(nums, n);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends