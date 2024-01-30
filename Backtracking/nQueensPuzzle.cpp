#include <vector>
#include <iostream>
using namespace std;

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board)
{
    vector<int> temp;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}

// we can also use Hashmap which will optimize this process from O(n) to O(1)
// There for upper diagonal we will use: (n-1) + (col-row)
// And for lower diagonal we know that the sum of row and col is equal
// we are filling left to right so we only need to check there
bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;

    // for same row
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    // we dont't need to check the columns
    // we then will check the diagonal
    // for upper diagonal
    x = row;
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;

        x--;
        y--;
    }

    // for lower diagonal
    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
            return false;

        x++;
        y--;
    }

    return true;
}

// Time Complexity -> n! (factorial)
// Space Complexity -> O(n^2)
void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board)
{
    if (col == board.size())
    {
        addSolution(ans, board);
        return;
    }

    for (int row = 0; row < board.size(); row++)
    {
        if (isSafe(row, col, board, board.size()))
        {
            board[row][col] = 1;
            solve(col + 1, ans, board);
            board[row][col] = 0; // backtracking
        }
    }
}

// queen - 1 and no queen - 0
vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board);

    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> nQueensSol = nQueens(n);
    cout << "Solutions are: ";
    for (int i = 0; i < nQueensSol.size(); i++)
    {
        for (int j = 0; j < nQueensSol[0].size(); j++)
        {
            if (j % 4 == 0)
                cout << endl;
            cout << nQueensSol[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}