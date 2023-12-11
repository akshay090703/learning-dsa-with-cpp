#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach
int rectangleSum(vector<vector<int>> v, int l1, int r1, int l2, int r2)
{
    int sum = 0;
    for (int i = l1; i <= l2; i++)
    {
        for (int j = r1; j <= r2; j++)
        {
            sum += v[i][j];
        }
    }
    return sum;
}

// Prefix Sum Matrix Approach (row wise)
int prefixRectangleSum(vector<vector<int>> v, int l1, int r1, int l2, int r2)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 1; j < v[i].size(); j++)
        {
            v[i][j] += v[i][j - 1];
        }
    }

    cout << "PreSum Matrix: \n";
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    int sum = 0;
    for (int i = l1; i <= l2; i++)
    {
        if (r1 != 0)
        {
            sum += (v[i][r2] - v[i][r1 - 1]);
        }
        else
        {
            sum += v[i][r2];
        }
    }
    return sum;
}

// Prefix Sum over columns and rows both: First row and then column
// prefix sum the row prefix output
// when we will use the ouput 2D array v[i][j], it will give the sum
// for all the elements between (0,0) and (i,j)
int rowColPrefixSumMatrix(vector<vector<int>> v, int l1, int r1, int l2, int r2)
{
    // row wise prefix sum
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 1; j < v[i].size(); j++)
        {
            v[i][j] += v[i][j - 1];
        }
    }

    // column wise prefix sum
    for (int i = 0; i < v[0].size(); i++)
    {
        for (int j = 1; j < v.size(); j++)
        {
            v[j][i] += v[j - 1][i];
        }
    }

    // Printing the row-column prefix sum matrix
    cout << "PreSum Matrix: \n";
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    int sum = v[l2][r2] - (l1 > 0 ? v[l1 - 1][r2] : 0) - (r1 > 0 ? v[l2][r1 - 1] : 0) + (l1 > 0 && r1 > 0 ? v[l1 - 1][r1 - 1] : 0);
    return sum;
}

int main()
{
    int n, m;
    cout << "Enter the number of rows in matrix: ";
    cin >> n;
    cout << "Enter the number of columns in matrix: ";
    cin >> m;

    vector<vector<int>> v(n, vector<int>(m));
    cout << "Enter the elements for the matrix: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    int l1, r1, l2, r2;
    cout << "Enter the first coordinates: ";
    cin >> l1 >> r1;
    cout << "Enter the second coordinates: ";
    cin >> l2 >> r2;

    cout << "<-- Rectangle according to coordinates -->\n";
    for (int i = l1; i <= l2; i++)
    {
        for (int j = r1; j <= r2; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    // int sum = rectangleSum(v, l1, r1, l2, r2);
    // int sum = prefixRectangleSum(v, l1, r1, l2, r2);
    int sum = rowColPrefixSumMatrix(v, l1, r1, l2, r2);
    cout << "The rectangle sum is: " << sum;

    return 0;
}