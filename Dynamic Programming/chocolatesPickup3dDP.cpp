//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Memoization
    // Time Comlexity -> O(n * m * m * 9)
    // Space Complexity -> O(n * m * m) + O(n)
    // int f(vector<vector<int>> &grid, int row, int col1, int col2, int n, int m, vector<vector<vector<int>>> &dp) {
    //     if(col1 < 0 or col2 < 0 or col1 >= m or col2 >= m) return INT_MIN;

    //     if(row == n - 1) {
    //         if(col1 == col2) return dp[row][col1][col1] = grid[n - 1][col1];

    //         return dp[row][col1][col2] = grid[row][col1] + grid[row][col2];
    //     }

    //     if(dp[row][col1][col2] != -1) return dp[row][col1][col2];

    //     int maxChoco = 0;
    //     for(int i = -1; i <= 1; i++) {
    //         for(int j = -1; j <= 1; j++) {
    //             int newCol1 = col1 + i;
    //             int newCol2 = col2 + j;

    //             if(col1 == col2) {
    //                 maxChoco = max(maxChoco, grid[row][col1] + f(grid, row + 1, newCol1, newCol2, n, m, dp));
    //             } else {
    //                 maxChoco = max(maxChoco, grid[row][col1] + grid[row][col2] + f(grid, row + 1, newCol1, newCol2, n, m, dp));
    //             }
    //         }
    //     }

    //     return dp[row][col1][col2] = maxChoco;
    // }

    // Tabulation
    // TC -> O(n * m * m * 9)
    // SC -> O(n * m * m)
    // int f(vector<vector<int>> &grid, int n, int m, vector<vector<vector<int>>> &dp) {
    //     for(int i = 0; i<m; i++) {
    //         for(int j = 0; j < m; j++) {
    //             if(i == j) {
    //                 dp[n - 1][i][j] = grid[n - 1][j];
    //             } else {
    //                 dp[n - 1][i][j] = grid[n - 1][i] + grid[n - 1][j];
    //             }
    //         }
    //     }

    //     for(int i = n - 2; i>=0; i--) {
    //         for(int j1 = 0; j1 < m; j1++) {
    //             for(int j2 = 0; j2 < m; j2++) {
    //                 int maxChoco = INT_MIN;
    //                 for(int diff1 = -1; diff1 <= 1; diff1++) {
    //                     for(int diff2 = -1; diff2 <= 1; diff2++) {
    //                         int newCol1 = j1 + diff1;
    //                         int newCol2 = j2 + diff2;
    //                         int value = 0;

    //                         if(j1 == j2) {
    //                             value = grid[i][j1];
    //                         } else {
    //                             value = grid[i][j1] + grid[i][j2];
    //                         }

    //                         if(newCol1 >= 0 and newCol1 < m and newCol2 >= 0 and newCol2 < m) {
    //                             value +=  dp[i + 1][newCol1][newCol2];
    //                         } else {
    //                             value += INT_MIN;
    //                         }

    //                         maxChoco = max(maxChoco, value);
    //                     }
    //                 }

    //                 dp[i][j1][j2] = maxChoco;
    //             }
    //         }
    //     }

    //     return dp[0][0][m - 1];
    // }

    // Space Optimization
    // TC -> O(n * m * m * 9)
    // SC -> O(m * m)
    int f(vector<vector<int>> &grid, int n, int m)
    {
        vector<vector<int>> dp(m, vector<int>(m, -1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j)
                {
                    dp[i][j] = grid[n - 1][j];
                }
                else
                {
                    dp[i][j] = grid[n - 1][i] + grid[n - 1][j];
                }
            }
        }

        vector<vector<int>> temp(m, vector<int>(m, 0));

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < m; j1++)
            {
                for (int j2 = 0; j2 < m; j2++)
                {
                    int maxChoco = INT_MIN;
                    for (int diff1 = -1; diff1 <= 1; diff1++)
                    {
                        for (int diff2 = -1; diff2 <= 1; diff2++)
                        {
                            int newCol1 = j1 + diff1;
                            int newCol2 = j2 + diff2;
                            int value = 0;

                            if (j1 == j2)
                            {
                                value = grid[i][j1];
                            }
                            else
                            {
                                value = grid[i][j1] + grid[i][j2];
                            }

                            if (newCol1 >= 0 and newCol1 < m and newCol2 >= 0 and newCol2 < m)
                            {
                                value += dp[newCol1][newCol2];
                            }
                            else
                            {
                                value += INT_MIN;
                            }

                            maxChoco = max(maxChoco, value);
                        }
                    }

                    temp[j1][j2] = maxChoco;
                }
            }

            dp = temp;
        }

        return dp[0][m - 1];
    }

    int solve(int n, int m, vector<vector<int>> &grid)
    {
        // vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));
        return f(grid, n, m);
        // return f(grid, n, m, dp);
        // return f(grid, 0, 0, m - 1, n, m, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends