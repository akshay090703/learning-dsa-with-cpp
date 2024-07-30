//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isConvertible(string &a, string &b)
    {
        int n = a.length();
        int m = b.length();

        if ((m - n) != 1)
            return false;

        int i = 0, j = 0;
        bool canAdd = true;
        while (i < n and j < m)
        {
            if (a[i] == b[j])
            {
                i++;
                j++;
            }
            else
            {
                if (canAdd)
                {
                    canAdd = false;
                    j++;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }

    // Tabulation Adv Approach
    // TC -> O(n * n * L),where L is the length of the longest string in the words.
    // SC -> O(n)
    int solve(vector<string> &words, int n)
    {
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });

        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            for (int prevIdx = 0; prevIdx < i; prevIdx++)
            {
                if (isConvertible(words[prevIdx], words[i]) and dp[i] < dp[prevIdx] + 1)
                {
                    dp[i] = max(dp[i], dp[prevIdx] + 1);
                }
            }

            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }

    int longestChain(int n, vector<string> &words)
    {
        return solve(words, n);
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
        vector<string> words(N);
        for (int i = 0; i < N; i++)
        {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends