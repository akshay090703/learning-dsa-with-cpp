#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralPrint(vector<vector<int>> &v, int n, int m)
{
    // n -> rows
    // m -> columns
    vector<int> res;

    int left = 0, right = n - 1;
    int top = 0, bottom = m - 1;
    int direction = 0;

    while (left <= right && top <= bottom)
    {
        if (direction % 4 == 0)
        {
            // left to right
            for (int i = left; i <= right; i++)
            {
                res.push_back(v[top][i]);
            }
            top++;
        }
        else if (direction % 4 == 1)
        {
            // top to bottom
            for (int i = top; i <= bottom; i++)
            {
                res.push_back(v[i][right]);
            }
            right--;
        }
        else if (direction % 4 == 2)
        {
            // right to left
            for (int i = right; i >= left; i--)
            {
                res.push_back(v[bottom][i]);
            }
            bottom--;
        }
        else if (direction % 4 == 3)
        {
            // bottom to top
            for (int i = bottom; i >= top; i--)
            {
                res.push_back(v[i][left]);
            }
            left++;
        }

        direction++;
    };

    return res;
};

int main()
{
    cout << "Enter the number of rows: ";
    int rows;
    cin >> rows;

    cout << "Enter the number of columns: ";
    int cols;
    cin >> cols;

    vector<vector<int>> arr(rows, vector<int>(cols));
    cout << "Enter your elements of the 2d array:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "The wave print of the array is: ";
    auto v = spiralPrint(arr, rows, cols);
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}