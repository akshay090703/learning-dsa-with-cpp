#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter thw sizes of the two arrays: \n";
    cin >> n >> m;

    int arr1[n], arr2[m];
    cout << "Enter the elements for array1: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter the elements for array2: ";
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    vector<int> v;
    int pointer1 = 0, pointer2 = 0;
    while (pointer1 <= n && pointer2 <= m)
    {
        if (arr1[pointer1] <= arr2[pointer2])
        {
            v.push_back(arr1[pointer1]);
            pointer1++;
        }
        else
        {
            v.push_back(arr2[pointer2]);
            pointer2++;
        }
    }

    // printing the new answer array
    cout << "The output array will be: ";
    for (int i = 0; i < (m + n); i++)
    {
        cout << v[i] << " ";
    }
}