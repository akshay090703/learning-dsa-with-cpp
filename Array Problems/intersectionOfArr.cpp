#include <iostream>
#include <vector>
using namespace std;

vector<int> intersectionOfArr(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> v;

    int i = 0, j = 0;
    while (i < n || j < m)
    {
        if (arr1[i] == arr2[j])
        {
            v.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
    };

    if (v.size() == 0)
        v.push_back(-1);

    return v;
};

int main()
{
    cout << "Enter size of array1: ";
    int n;
    cin >> n;

    cout << "Enter elements of the array1: ";
    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    };

    cout << "Enter size of array2: ";
    int m;
    cin >> m;

    cout << "Enter elements of the array2: ";
    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    };

    cout << "The intersection of the array is: ";
    for (auto it : intersectionOfArr(arr1, n, arr2, m))
    {
        cout << it << " ";
    }

    return 0;
}