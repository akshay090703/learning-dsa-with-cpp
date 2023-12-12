#include <iostream>
#include <vector>
using namespace std;

// int arr[][4] : has to put the number of cols in case of arrays(second bracket)
vector<int> wavePrint(const vector<vector<int>> &arr, int rows, int cols)
{
    vector<int> v;
    for (int i = 0; i < cols; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < rows; j++)
            {
                v.push_back(arr[j][i]);
            }
        }
        else
        {
            for (int j = 0; j < rows; j++)
            {
                v.push_back(arr[j][i]);
            }
        }
    }
    return v;
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
        cout << endl;
    }

    cout << "The wave print of the array is: ";
    for (auto i : wavePrint(arr, rows, cols))
    {
        cout << i << " ";
    }

    return 0;
}