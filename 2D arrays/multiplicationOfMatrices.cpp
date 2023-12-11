#include <iostream>
using namespace std;

int main()
{
    cout << "--MATRIX 1--\n";
    cout << "Enter the number of rows: ";
    int n1;
    cin >> n1;
    cout << "Enter the number of columns: ";
    int m1;
    cin >> m1;
    int arr1[n1][m1];

    cout << "Enter the elements: \n";
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            cin >> arr1[i][j];
        }
    }

    cout << "--MATRIX 2--\n";
    cout << "Enter the number of rows: ";
    int n2;
    cin >> n2;
    cout << "Enter the number of columns: ";
    int m2;
    cin >> m2;
    int arr2[n2][m2];

    cout << "Enter the elements: \n";
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cin >> arr2[i][j];
        }
    }

    if (m1 != n2)
    {
        cout << "Matrix dimensions are incompatible for multiplication.\n";
    }
    else
    {

        int ansArr[n1][m2] = {};
        ;
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m2; j++)
            {
                for (int k = 0; k < m1; k++)
                {
                    ansArr[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }

        // Displaying the output
        cout << "The output is: \n";
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m2; j++)
            {
                cout << ansArr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}