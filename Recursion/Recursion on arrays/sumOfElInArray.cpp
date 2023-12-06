#include <iostream>
using namespace std;

// Recursive function
int sumOfElInArr(int *arr, int i, int n)
{
    // Base condition
    if (i == (n - 1))
        return arr[i];

    return arr[i] + sumOfElInArr(arr, i + 1, n);
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

    cout << "Sum of elements is: " << sumOfElInArr(array, 0, n) << endl;

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
// where n is the length of the array