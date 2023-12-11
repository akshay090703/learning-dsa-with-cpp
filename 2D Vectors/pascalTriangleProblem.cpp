#include <iostream>
#include <vector>
using namespace std;

// In pascal triangle, we can observe that each element is a value of
// nCm where n is the rows and m is the columns.

int factorial(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}

int nCrFormula(int n, int m)
{
    if (n < m)
        return 0;
    return factorial(n) / (factorial(m) * factorial(n - m));
}

// in pascal triangle n = m
int main()
{
    cout << "Enter the numbers of Pascal Triangle rows to be printed: ";
    int num;
    cin >> num;

    vector<vector<int>> v(num, vector<int>(num, 0));

    cout << "<-- Pascal Triangle -->\n";
    for (int i = 0; i < num; i++)
    {
        for (int space = 0; space < (num - i); space++)
        {
            cout << " ";
        }

        for (int j = 0; j <= i; j++)
        {
            v[i][j] = nCrFormula(i, j);
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}