#include <iostream>
#include <vector>
using namespace std;

void squareSpiralOrder(vector<vector<int>> &v)
{
    int top = 0, bottom = v.size() - 1;
    int left = 0, right = v[0].size() - 1;

    int direction = 0;
    int value = 0;

    while (left <= right && top <= bottom)
    {
        // left => right
        if (direction % 4 == 0)
        {
            for (int col = left; col <= right; col++)
            {
                v[top][col] = ++value;
            }
            top++;
        }

        // top -> bottom
        else if (direction % 4 == 1)
        {
            for (int row = top; row <= bottom; row++)
            {
                v[row][right] = ++value;
            }
            right--;
        }

        // right -> left
        else if (direction % 4 == 2)
        {
            for (int col = right; col >= left; col--)
            {
                v[bottom][col] = ++value;
            }
            bottom--;
        }

        // bottom -> top
        else
        {
            for (int row = bottom; row >= top; row--)
            {
                v[row][left] = ++value;
            }
            left++;
        }

        direction++;
    }
    return;
}

int main()
{
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));

    squareSpiralOrder(v);

    cout << "Elements of the matrix: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}