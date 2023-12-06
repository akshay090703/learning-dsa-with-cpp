#include <iostream>
using namespace std;

// Recursive function
void printArray(auto *arr, int i, int n)
{
    // Base Case
    if (i == n)
        return;

    // Self work
    cout << arr[i] << " ";

    // Assumption
    printArray(arr, i + 1, n);
};

int main()
{
    int n;
    cout << "Size of array: ";
    cin >> n;
    int array[n] = {};
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    };

    cout << "The elements of the array are: ";
    printArray(array, 0, n);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
// where n is the length of the array