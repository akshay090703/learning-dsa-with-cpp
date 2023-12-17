#include <iostream>
#include <vector>
using namespace std;

string binarySearch2DArr(vector<vector<int>> &input, int &target)
{
    int n = input.size(), m = input[0].size();
    int low = 0, high = m - 1;
    int i = 0;
    while (i < n && low <= high)
    {
        int mid = low + (high - low) / 2;
        if (input[i][mid] == target)
            return "(" + to_string(i) + "," + to_string(mid) + ")";
        else if (input[i][high] < target)
        {
            i++;
            low = 0, high = input[i].size() - 1;
        }
        else if (input[i][mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return "(-1, -1)";
}

// alterantive approach
bool alterantiveApproach(vector<vector<int>> &input, int &target)
{
    int n = input.size(), m = input[0].size();
    int low = 0, high = n * m - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int x = mid / m; // row index
        int y = mid % m; // column index
        if (input[x][y] == target)
        {
            return true;
        }
        else if (input[x][y] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int>> input(n, vector<int>(m));
    cout << "Enter elements of array: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> input[i][j];
        }
    };

    cout << "Enter the target element: ";
    int target;
    cin >> target;

    string result = binarySearch2DArr(input, target);

    cout << "Target element index in 2D array: " << result << endl;

    system("pause");
    return 0;
}

// n -> rows, m -> columns
// Time complexity: O(nlog(m))
// Space complexity: O(1)