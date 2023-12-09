#include <iostream>
#include <vector>
using namespace std;

void subsetsOfArr(int *arr, int n, int i, vector<int> &currentSubset, vector<vector<int>> &v)
{
    if (i == n)
    {
        if (currentSubset.empty())
        {
            vector<int> empty(1, 0);
            v.push_back(empty);
            return;
        };

        v.push_back(currentSubset);
        return;
    }

    // Include the current element in the subset and recurse
    currentSubset.push_back(arr[i]);
    subsetsOfArr(arr, n, i + 1, currentSubset, v);

    // Don't include the current element and then recurse
    currentSubset.pop_back();
    subsetsOfArr(arr, n, i + 1, currentSubset, v);
};

int main()
{
    cout << "Enter size of array: ";
    int n;
    cin >> n;
    int arr[n];

    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    };

    vector<vector<int>> subsets;
    vector<int> currentSubset;
    subsetsOfArr(arr, n, 0, currentSubset, subsets);

    cout << "Subsets in the array: " << endl;
    for (int i = 0; i < subsets.size(); i++)
    {
        for (int j = 0; j < subsets[i].size(); j++)
        {
            cout << subsets[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}