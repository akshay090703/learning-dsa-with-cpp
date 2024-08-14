//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    const int MOD = 100000;

    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // multiplications : value
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        queue<pair<int, int>> q;
        q.push({0, start});

        vector<int> dist(100000, INT_MAX);
        dist[start] = 0;

        int minMultiplications = INT_MAX;
        while (!q.empty())
        {
            int multiplications = q.front().first;
            int value = q.front().second;
            q.pop();

            if (value == end)
            {
                continue;
            }

            for (int i = 0; i < arr.size(); i++)
            {
                int newVal = (value * arr[i]) % MOD;

                if (dist[newVal] > multiplications + 1)
                {
                    q.push({multiplications + 1, newVal});
                    dist[newVal] = multiplications + 1;
                }
            }
        }

        return dist[end] == INT_MAX ? -1 : dist[end];
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends