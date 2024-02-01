#include <vector>
#include <iostream>
using namespace std;

// m -> number of empty cell
// Time Complexity -> O(9^m)
// Space Complexity -> O(1)
// as max to max the recursive calls can be 81, not more than that
bool isSafe(vector<vector<int>> &board, int row, int col, int val)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == val or board[row][i] == val)
        {
            return false;
        }

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + (i % 3)] == val)
        {
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>> &board, int n)
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (board[row][col] == 0)
            {
                for (int i = 1; i <= 9; i++)
                {
                    if (isSafe(board, row, col, i))
                    {
                        board[row][col] = i;

                        bool nextSolution = solve(board, n);
                        if (nextSolution)
                        {
                            return true;
                        }
                        else
                        {
                            // backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    int n = sudoku.size(); // size of the Sudoku board (n x n)
    solve(sudoku, n);
}

int main()
{
    vector<vector<int>> sudoku = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0},
    };

    // Answer
    // 3 1 6 5 7 8 4 9 2
    // 5 2 9 1 3 4 7 6 8
    // 4 8 7 6 2 9 5 3 1
    // 2 6 3 4 1 5 9 8 7
    // 9 7 4 8 6 3 1 2 5
    // 8 5 1 7 9 2 6 4 3
    // 1 3 8 9 4 7 2 5 6
    // 6 9 2 3 5 1 8 7 4
    // 7 4 5 2 8 6 3 1 9

    solveSudoku(sudoku);
    cout << "The solved sudoku is: " << endl;
    for (int row = 0; row < sudoku.size(); row++)
    {
        for (int col = 0; col < sudoku.size(); col++)
        {
            cout << sudoku[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}