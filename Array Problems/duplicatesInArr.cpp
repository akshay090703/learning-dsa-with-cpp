#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &arr)
{
    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }

    for (int i = 1; i < arr.size(); i++)
    {
        ans = ans ^ i;
    }

    return ans;
};

int main()
{
    cout << "Enter the size of array: ";
    int n;
    cin >> n;

    cout << "Enter the elements of the array: ";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << "Duplicate element in the array: " << findDuplicate(v) << endl;

    return 0;
}