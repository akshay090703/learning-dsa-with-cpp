#include <iostream>
#include <vector>
using namespace std;

void pascalTriangle(vector<vector<int>> &v, int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int spaces = 0; spaces < (num - i); spaces++)
        {
            cout << " "; // printing space
        }

        v[i].resize(i + 1);
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                v[i][j] = 1;
            }
            else
            {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
            }
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Enter the number of rows to be printed of Pascal Triangle: ";
    int num;
    cin >> num;

    vector<vector<int>> v(num, vector<int>(num, 0));

    cout << "<-- Pascal Triangle -->\n";
    pascalTriangle(v, num);

    // For displaying actual vector
    // for (int i = 0; i < v.size(); i++)
    // {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}