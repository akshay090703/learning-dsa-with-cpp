#include <iostream>
#include <vector>
using namespace std;

void sumOfSubsets(int *arr, int n, int i, int sum, vector<int> &result)
{
    // base case
    if (i == n)
    {
        result.push_back(sum);
        return;
    };

    sumOfSubsets(arr, n, i + 1, sum + arr[i], result); // pick the ith element
    sumOfSubsets(arr, n, i + 1, sum, result);          // don't pick the ith element
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

    vector<int> result;
    sumOfSubsets(arr, n, 0, 0, result);

    cout << "Sum of Subsets in the array: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}

// Time Complexity -> O(log n)