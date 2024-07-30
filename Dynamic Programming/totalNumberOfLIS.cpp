//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int solve(vector<int> &arr, int n)
    {
        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            for (int prevIdx = 0; prevIdx < i; prevIdx++)
            {
                if (arr[prevIdx] < arr[i] and dp[i] < dp[prevIdx] + 1)
                {
                    dp[i] = dp[prevIdx] + 1;
                    count[i] = count[prevIdx];
                }
                else if (arr[prevIdx] < arr[i] and dp[i] == dp[prevIdx] + 1)
                {
                    count[i] += count[prevIdx];
                }
            }

            maxLen = max(maxLen, dp[i]);
        }

        int totalLIS = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxLen)
            {
                totalLIS += count[i];
            }
        }

        return totalLIS;
    }

    int NumberofLIS(int n, vector<int> &arr)
    {
        return solve(arr, n);
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
        vector<int> arr;

        for (int i = 0; i < n; ++i)
        {
            long long x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.NumberofLIS(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends