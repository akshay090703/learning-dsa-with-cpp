#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the number of rows: ";
    int n;
    cin >> n;
    cout << "Enter the number of cols: ";
    int m;
    cin >> m;

    int array[n][m];
    cout << "Enter elements of the array: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> array[i][j];
        }
    }

    // Transpose
    int transposeArr[m][n];
    cout << "Transpose of the given matrix is :\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transposeArr[i][j] = array[j][i];
        }
    }

    // Printing the results
    cout << "The transpose of the array is: \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << transposeArr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}