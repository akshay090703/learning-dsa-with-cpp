#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Enter the number of rows: ";
    int n;
    cin >> n;
    cout << "Enter the number of columns: ";
    int m;
    cin >> m;

    vector<vector<int>> v(n, vector<int>(m));
    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    int max = -1;
    int maxOnes = INT16_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] != 0)
            {
                count = v[i].size() - j;

                if (count > maxOnes)
                {
                    maxOnes = count;
                    max = i;
                }
                break;
            }
        }
    }

    cout << "The maximum number of 1s are in row: " << max;

    return 0;
}