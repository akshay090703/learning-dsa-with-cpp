#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateArrBy90Deg(vector<vector<int>> &v)
{
    // Transpose
    int n = v.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; j++)
        {
            swap(v[i][j], v[j][i]);
        }
    }

    // reverse every row
    for (int i = 0; i < n; ++i)
    {
        reverse(v[i].begin(), v[i].end());
    }

    return;
}

int main()
{

    cout << "Enter the size of the square matrix: ";
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));
    cout << "Enter the elements for the matrix: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    rotateArrBy90Deg(v);
    cout << "<-- Matrix after 90deg rotation -->\n";
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