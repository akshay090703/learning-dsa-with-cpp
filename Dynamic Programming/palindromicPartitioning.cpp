//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isPalindrome(string &str, int start, int end)
    {
        while (start <= end)
        {
            if (str[start++] != str[end--])
                return false;
        }

        return true;
    }

    // Recursion
    // TC -> O(exponential)
    // SC -> O(n)
    // int solve(string &str, int start, int n) {
    //     if(start == n) return 0;

    //     int minPartitions = INT_MAX;
    //     for(int i = start; i<n; i++) {
    //         if(isPalindrome(str, start, i)) {
    //             minPartitions = min(minPartitions, 1 + solve(str, i + 1, n));
    //         }
    //     }

    //     return minPartitions;
    // }

    // Memoization
    // TC -> O(n^2)
    // SC -> O(n^2) + O(n)
    // int solve(string &str, int start, int n, vector<int> &dp) {
    //     if(start == n) return 0;

    //     if(dp[start] != -1) return dp[start];

    //     int minPartitions = INT_MAX;
    //     for(int i = start; i<n; i++) {
    //         if(isPalindrome(str, start, i)) {
    //             minPartitions = min(minPartitions, 1 + solve(str, i + 1, n, dp));
    //         }
    //     }

    //     return dp[start] = minPartitions;
    // }

    // Tabulation
    // TC -> O(n^2)
    // SC -> O(n^2)
    int solve(string &str, int n)
    {
        vector<int> dp(n + 1, 0);

        for (int start = n - 1; start >= 0; start--)
        {
            int minPartitions = INT_MAX;

            for (int i = start; i < n; i++)
            {
                if (isPalindrome(str, start, i))
                {
                    minPartitions = min(minPartitions, 1 + dp[i + 1]);
                }
            }

            dp[start] = minPartitions;
        }

        return dp[0];
    }

    int palindromicPartition(string str)
    {
        int n = str.length();

        // vector<int> dp(n, -1);
        // return solve(str, 0, n, dp) - 1;

        return solve(str, n) - 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}
// } Driver Code Ends