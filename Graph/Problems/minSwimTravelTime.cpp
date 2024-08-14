//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int Solve(int n, vector<vector<int>> &grid)
    {
        // time : row : col
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            minHeap;
        vector<vector<bool>> isVisited(n, vector<bool>(n, false));

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, -1, 0, 1};

        minHeap.push({grid[0][0], {0, 0}});
        isVisited[0][0] = true;
        while (!minHeap.empty())
        {
            int currTime = minHeap.top().first;
            int row = minHeap.top().second.first;
            int col = minHeap.top().second.second;
            minHeap.pop();

            if (row == n - 1 and col == n - 1)
                return currTime;

            for (int i = 0; i < 4; i++)
            {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if (nRow >= 0 and nCol >= 0 and nRow < n and nCol < n and !isVisited[nRow][nCol])
                {
                    isVisited[nRow][nCol] = true;
                    minHeap.push({max(currTime, grid[nRow][nCol]), {nRow, nCol}});
                }
            }
        }

        return -1;
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

        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < n; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends