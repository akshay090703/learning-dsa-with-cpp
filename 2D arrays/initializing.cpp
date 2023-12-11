#include <iostream>
using namespace std;

int main()
{
    int array[2][3] = {1, 2, 3, 4, 5, 6};

    int array2[2][3] = {{1, 2, 3},
                        {4, 5, 6}};

    // Taking input in 2D loops
    // rows -> n, columns -> m
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of cols: ";
    cin >> m;

    int arr[n][m];

    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "The elements are: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}