#include <vector>
#include <iostream>
using namespace std;

bool isSafe(int new_x, int new_y, vector<vector<bool>> &isVisited, vector<vector<int>> &arr, int n)
{
    if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && !isVisited[new_x][new_y] && arr[new_x][new_y] == 1)
    {
        return true;
    }

    return false;
}

void solve(int x, int y, vector<vector<int>> &arr, vector<vector<bool>> &isVisited, string path, vector<string> &ans)
{
    // base case
    int n = arr.size();
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // 4 movements: D, L, R, U
    // Down
    if (isSafe(x + 1, y, isVisited, arr, n))
    {
        isVisited[x][y] = 1;
        solve(x + 1, y, arr, isVisited, path + "D", ans);
        isVisited[x][y] = 0; // backtracking
    }

    // Left
    if (isSafe(x, y - 1, isVisited, arr, n))
    {
        isVisited[x][y] = 1;
        solve(x, y - 1, arr, isVisited, path + "L", ans);
        isVisited[x][y] = 0; // backtracking
    }

    // Right
    if (isSafe(x, y + 1, isVisited, arr, n))
    {
        isVisited[x][y] = 1;
        solve(x, y + 1, arr, isVisited, path + "R", ans);
        isVisited[x][y] = 0; // backtracking
    }

    // Up
    if (isSafe(x - 1, y, isVisited, arr, n))
    {
        isVisited[x][y] = 1;
        solve(x - 1, y, arr, isVisited, path + "U", ans);
        isVisited[x][y] = 0; // backtracking
    }
}

// Time Complexity -> O(4^(n^2)) [cuz there are 4 possible directions]
// Space Complexity -> O(n*m)
vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<bool>> isVisited(n, vector<bool>(n, false));
    string path = "";
    if (arr[0][0] == 0)
        return ans;

    solve(0, 0, arr, isVisited, path, ans);
    return ans;
}

int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = maze.size();
    vector<string> paths = searchMaze(maze, n);
    cout << "The paths are: " << endl;
    for (int i = 0; i < paths.size(); i++)
    {
        cout << paths[i] << endl;
    }

    return 0;
}