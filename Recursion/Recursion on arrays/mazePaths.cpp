#include <iostream>
#include <vector>
using namespace std;

void allPossiblePaths(vector<vector<int>> &v, int m, int n, int i, int j, int &count)
{
    if (i == m - 1 && j == n - 1)
    {
        count++;
        return;
    }

    if (i == m - 1)
    {
        allPossiblePaths(v, m, n, i, j + 1, count);
    }
    else if (j == n - 1)
    {
        allPossiblePaths(v, m, n, i + 1, j, count);
    }
    else
    {

        allPossiblePaths(v, m, n, i + 1, j, count);
        allPossiblePaths(v, m, n, i, j + 1, count);
    }
    return;
};

// Shorter method
int mazePath(int i, int j, int m, int n)
{
    if (i == m - 1 && j == n - 1)
        return 1;
    if (i >= m || j >= n)
        return 0;
    return mazePath(i, j + 1, m, n) + mazePath(i + 1, j, m, n);
};

int main()
{
    int m, n, count = 0;

    // Get dimensions from user input
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    // Create a 2D vector and initialize with zeros
    vector<vector<int>> grid(m, vector<int>(n, 0));
    allPossiblePaths(grid, m, n, 0, 0, count);

    cout << "No. of possible ways in the grid: " << count << endl;
    cout << "No. of possible ways in the grid using shorter method: " << mazePath(0, 0, m, n) << endl;

    return 0;
}