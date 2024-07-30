//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Tabulation Advanced approach
    // TC -> O(n * n)
    // SC -> O(n) + O(n)
    vector<int> solve(vector<int> &arr, int n)
    {
        vector<int> dp(n, 0);
        vector<int> prevArr(n, 0);

        int lastIdx = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            prevArr[i] = i;

            for (int prevIdx = 0; prevIdx < i; prevIdx++)
            {
                if (arr[i] % arr[prevIdx] == 0 and dp[i] < dp[prevIdx] + 1)
                {
                    dp[i] = dp[prevIdx] + 1;
                    prevArr[i] = prevIdx;
                }
            }

            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastIdx = i;
            }
        }

        vector<int> result;
        result.push_back(arr[lastIdx]);
        while (lastIdx != prevArr[lastIdx])
        {
            lastIdx = prevArr[lastIdx];
            result.push_back(arr[lastIdx]);
        }

        // reverse(result.begin(), result.end());
        return result;
    }

    vector<int> LargestSubset(int n, vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

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
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++)
        {
            for (int j = i + 1; j < sz; j++)
            {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else
                {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends