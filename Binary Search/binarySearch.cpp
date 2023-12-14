#include <iostream>
#include <vector>
using namespace std;

// Iterative Approach
int binarySearch(vector<int> &input, int target)
{
    // defining search space
    int low = 0;                 // start of the search space
    int high = input.size() - 1; // end of the search space

    while (low <= high)
    {
        // calculating midpoint for the search space
        // int mid = (low + high) / 2;
        int mid = low + ((high - low) / 2); // modified mid to tackle overflow

        if (input[mid] == target)
            return mid;

        else if (input[mid] < target)
        {
            // discard the left of mid
            low = mid + 1;
        }
        else
        {
            // discard the right of mid
            high = mid - 1;
        }
    };
    // if element not found then returning -1
    return -1;
};

int recursiveBinarySearch(vector<int> &input, int target, int high, int low)
{
    if (high < low)
        return -1;

    // int mid = (low + high) / 2;
    int mid = low + ((high - low) / 2); // modified mid to tackle overflow

    if (input[mid] == target)
        return mid;
    else if (input[mid] > target)
        high = mid - 1;
    else
        low = mid + 1;

    return recursiveBinarySearch(input, target, high, low);
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

    cout << "Give a target element to search: ";
    int target;
    cin >> target;

    // cout << "The given target is present at index: " << binarySearch(input, target);
    cout << "The given target is present at index: " << recursiveBinarySearch(input, target, n - 1, 0);

    return 0;
}

// n -> length of the array
// Iterative Binary Search
// Time Complexity -> O(log(n))
// Space Complexity -> O(1)

// Recursive Binary Search
// Time Complexity -> O(log(n))
// Space Complexity -> O(log(n))