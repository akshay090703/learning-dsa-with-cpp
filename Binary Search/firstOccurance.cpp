#include <iostream>
#include <vector>
using namespace std;

int firstOccurance(vector<int> &v, int &target)
{
    int low = 0;
    int high = v.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + ((high - low) / 2);
        // if (v[mid] == target)
        // {
        //     while (v[mid] == target)
        //     {
        //         ans = mid;
        //         mid--;
        //     };
        //     return ans;
        // }
        if (v[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (v[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    };

    return ans;
};

int main()
{
    cout << "Enter the size of vector: ";
    int n;
    cin >> n;

    vector<int> input(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    };

    cout << "Element to be searched: ";
    int target;
    cin >> target;

    cout << "First occurance of the element is at index: " << firstOccurance(input, target) << endl;

    return 0;
}

// Time Complexity: O(logn)
// Space Complexity: O(1)