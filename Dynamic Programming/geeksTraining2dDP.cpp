//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Using recursion
    // Time Complexity -> O(n^n)
    // Space Complexity -> O(n^n)
    // int solve(vector<vector<int>> &points, int day, int lastChosen) {
    //     if(day < 0) return 0;

    //     int maxPoints = 0;
    //     for(int i = 2; i >= 0; i--) {
    //         if(i != lastChosen) {
    //             int curr = points[day][i] + solve(points, day - 1, i, n);

    //             maxPoints = max(maxPoints, curr);
    //         }
    //     }

    //     return maxPoints;
    // }

    // Memoization
    // Time Complexity -> O(3*n)
    // Space Complexity -> O(3*n) + O(3*n)
    // int solve(vector<vector<int>> &points, int day, int lastChosen, vector<vector<int>> &dp) {
    //     if(day == 0) {
    //         int maxi = INT_MIN;
    //         for(int i = 0; i < 3; i++) {
    //             if(i != lastChosen) {
    //                 maxi = max(maxi, points[0][i]);
    //             }
    //         }

    //         return maxi;
    //     }

    //     if (lastChosen != -1 && dp[day][lastChosen] != -1) return dp[day][lastChosen];

    //     int maxPoints = 0;
    //     for(int i = 2; i>=0; i--) {
    //         if(i != lastChosen) {
    //             int curr = points[day][i] + solve(points, day - 1, i, dp);

    //             maxPoints = max(maxPoints, curr);
    //         }
    //     }

    //     if(lastChosen == -1) return maxPoints;

    //     return dp[day][lastChosen] = maxPoints;
    // }

    // Tabulation
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)
    // int solve(vector<vector<int>> &points, vector<vector<int>> &dp) {
    //     int n = points.size();

    //     dp[0][0] = points[0][0];
    //     dp[0][1] = points[0][1];
    //     dp[0][2] = points[0][2];

    //     for(int day = 1; day < n; day++) {
    //         dp[day][0] = points[day][0] + max(dp[day - 1][1], dp[day - 1][2]);
    //         dp[day][1] = points[day][1] + max(dp[day - 1][0], dp[day - 1][2]);
    //         dp[day][2] = points[day][2] + max(dp[day - 1][0], dp[day - 1][1]);
    //     }

    //     return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
    // }

    // Space Optimization
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)
    int solve(vector<vector<int>> &points, int n)
    {
        int firstTask = points[0][0];
        int secondTask = points[0][1];
        int thirdTask = points[0][2];

        for (int day = 1; day < n; day++)
        {
            int currFirst = points[day][0] + max(secondTask, thirdTask);
            int currSecond = points[day][1] + max(firstTask, thirdTask);
            int currThird = points[day][2] + max(firstTask, secondTask);

            firstTask = currFirst;
            secondTask = currSecond;
            thirdTask = currThird;
        }

        return max(firstTask, max(secondTask, thirdTask));
    }

    int maximumPoints(vector<vector<int>> &points, int n)
    {
        // return solve(points, n - 1, -1);

        // vector<vector<int>> dp(n, vector<int> (3, -1));
        // return solve(points, n - 1, -1, dp);

        // return solve(points, dp);
        return solve(points, n);
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
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends