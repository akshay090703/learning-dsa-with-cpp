//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // void dfs(vector<vector<int>>& temp, vector<vector<bool>> &isVisited, int row, int col, int color) {
    //     int n = temp.size();
    //     int m = temp[0].size();
    //     isVisited[row][col] = true;

    //     vector<pair<int, int>> neighbours;
    //     if(row - 1 >= 0 and temp[row - 1][col] == temp[row][col]) neighbours.push_back({row - 1, col});
    //     if(row + 1 < n and temp[row + 1][col] == temp[row][col]) neighbours.push_back({row + 1, col});
    //     if(col - 1 >= 0 and temp[row][col - 1] == temp[row][col]) neighbours.push_back({row, col - 1});
    //     if(col + 1 < m and temp[row][col + 1] == temp[row][col]) neighbours.push_back({row, col + 1});

    //     temp[row][col] = color;
    //     for(auto p : neighbours) {
    //         if(!isVisited[p.first][p.second]) {
    //             dfs(temp, isVisited, p.first, p.second, color);
    //         }
    //     }
    // }

    // vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    //     int n = image.size();
    //     int m = image[0].size();
    //     vector<vector<int>> temp(image.begin(), image.end());
    //     vector<vector<bool>> isVisited(n, vector<bool> (m, false));

    //     dfs(temp, isVisited, sr, sc, color);

    //     return temp;
    // }

    // BFS
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> temp(image.begin(), image.end());
        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        q.push({sr, sc});
        isVisited[sr][sc] = true;
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            vector<pair<int, int>> neighbours;
            if (row - 1 >= 0 and temp[row - 1][col] == temp[row][col])
                neighbours.push_back({row - 1, col});
            if (row + 1 < n and temp[row + 1][col] == temp[row][col])
                neighbours.push_back({row + 1, col});
            if (col - 1 >= 0 and temp[row][col - 1] == temp[row][col])
                neighbours.push_back({row, col - 1});
            if (col + 1 < m and temp[row][col + 1] == temp[row][col])
                neighbours.push_back({row, col + 1});

            temp[row][col] = newColor;
            for (auto p : neighbours)
            {
                if (!isVisited[p.first][p.second])
                {
                    isVisited[p.first][p.second] = true;
                    q.push({p.first, p.second});
                }
            }
        }

        return temp;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends