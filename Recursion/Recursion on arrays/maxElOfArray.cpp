#include <iostream>
using namespace std;

// Recursive function
int maxElInArr(int *arr, int i, int n)
{
    // Base condition
    if (i == (n - 1))
        return arr[i];

    return arr[i] > maxElInArr(arr, i + 1, n) ? arr[i] : maxElInArr(arr, i + 1, n);
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

    cout << "Max element is: " << maxElInArr(array, 0, n) << endl;

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
// where n is the length of the array