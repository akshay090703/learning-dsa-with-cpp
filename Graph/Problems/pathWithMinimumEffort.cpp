//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// } Driver Code Ends

class Solution
{
public:
    // Time Complexity: O(rows x columns)
    // Space Complexity: O(rows x columns)
    int MinimumEffort(int n, int m, vector<vector<int>> &heights)
    {
        vector<vector<int>> minEffort(n, vector<int>(m, INT_MAX));
        // as the distances in each cell is different so we have to use the priority queue and queue is not enough
        // abs_distance, row:col
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

        minHeap.push({0, {0, 0}});
        minEffort[0][0] = 0;

        int delR[] = {-1, 0, 1, 0};
        int delC[] = {0, -1, 0, 1};
        while (!minHeap.empty())
        {
            int abs_dist = minHeap.top().first;
            int row = minHeap.top().second.first;
            int col = minHeap.top().second.second;
            minHeap.pop();

            if (row == n - 1 and col == m - 1)
                return abs_dist;

            for (int i = 0; i <= 3; i++)
            {
                int nRow = row + delR[i];
                int nCol = col + delC[i];

                if (nRow >= 0 and nCol >= 0 and nRow < n and nCol < m)
                {
                    int newEffort = abs(heights[row][col] - heights[nRow][nCol]);

                    if (newEffort < minEffort[nRow][nCol])
                    {
                        minEffort[nRow][nCol] = newEffort;
                        minHeap.push({max(abs_dist, newEffort), {nRow, nCol}});
                    }
                }
            }
        }

        return minEffort[n - 1][m - 1];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends