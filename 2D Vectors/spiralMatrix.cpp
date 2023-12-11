#include <iostream>
#include <vector>
using namespace std;

void printSpiralMatrix(vector<vector<int>> v)
{
    int top = 0;
    int bottom = v.size() - 1;
    int left = 0;
    int right = v[0].size() - 1;

    int direction = 0;

    while (left <= right && top <= bottom)
    {
        // left -> right
        if (direction % 4 == 0)
        {
            for (int col = left; col <= right; col++)
            {
                cout << v[top][col] << " ";
            }
            top++;
        }

        // top -> bottom
        else if (direction % 4 == 1)
        {
            for (int row = top; row <= bottom; row++)
            {
                cout << v[row][right] << " ";
            }
            right--;
        }

        // right -> left
        else if (direction % 4 == 2)
        {
            for (int col = right; col >= left; col--)
            {
                cout << v[bottom][col] << " ";
            }
            bottom--;
        }

        // bottom -> up
        else
        {
            for (int row = bottom; row >= top; row--)
            {
                cout << v[row][left] << " ";
            }
            left++;
        }

        // increasing direction variable
        direction++;
    }
    return;
}

int main()
{
    cout << "Enter the number of rows: ";
    int n;
    cin >> n;
    cout << "Enter the number of columns: ";
    int m;
    cin >> m;

    vector<vector<int>> v(n, vector<int>(m));
    cout << "Enter the elements for the matrix: \n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> v[i][j];
        }
    }

    printSpiralMatrix(v);

    return 0;
}